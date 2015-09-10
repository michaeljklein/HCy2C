module Main where

import Cycles.Maxcy
import Cycles.Findcy
import Cycles.IO
import Cycles.Aux

--import Data.GList

import Control.Exception (catch, SomeException, throwIO)
import Control.Monad
import Data.List (sort, group)
import Test.Hspec
import Test.QuickCheck
import Test.QuickCheck.Gen
import Test.QuickCheck.Monadic
import System.Directory
import System.IO
import System.IO.Error ( isDoesNotExistError )

-- This is the test suite. Use "*y and "*p to copy between files.


-- Add a "print current options" feature for prop_goodShuttleGraphNumCyShuffled ->> run it alone until you get a memory blowup and then debug.


-- | Because the number of cycles and edges tried by quickcheck can blow up quickly, these are the ranges allowable for (reasonably) fast tests
-- Tested on Macbook Pro 15", Late 2011, 8 GB RAM, 2.5 GHZ Intel Core i7, 64-bit
maxNumCyForTest = completeGraphNumCy 6

-- | See 'maxNumCyForTest'
maxNumEdgesForTest = 100

-- | This tests the readInt function in Cycles.IO (notice the little endian interpretation)
prop_readInt :: Int -> Property
prop_readInt n = property $ (readInt . reverse . show . abs) n == abs n

-- | This tests the readIntList function in Cycles.IO (similar to \s->read s :: [Int], but faster)
prop_readIntList :: [Int] -> Property
prop_readIntList list = property $ readIntList (show posList) == posList
  where
    posList = map abs list

-- | This function sorts an [[Ord a]] on both levels (because FindCy and MaxCy both use ordered lists for undirected graphs)
sort2 lists = sort $ map sort lists

-- | This function takes a string and char and returns everything up to (but not including) that char
cutUntoChar :: String -> Char -> String
cutUntoChar [] _ = []
cutUntoChar (x:xs) char
    | x == char  = []
    | otherwise = x : cutUntoChar xs char

-- | This function converts a string like "0101010101001010" into a list of Ints
readBins :: String -> [Int]
readBins [] = []
readBins ('0':xs) = 0 : readBins xs
readBins ('1':xs) = 1 : readBins xs
readBins (_:xs)   = error "list passed not composed of 0's and 1's"

-- | This function converts a solution string (such as "[10101010, 2384]") to a (list of bins, number)
solutionStrToTup :: String -> ([Int], Int)
solutionStrToTup str = (readBins bins, read num)
  where
    bins = cutUntoChar (tail str) ','
    num  = reverse $ cutUntoChar (reverse $ trim str) ','

-- | This function takes a list of directions encoded as '1's and '0's ('0' is forward, i.e. [a,b] -> a<b) and a graph and returns a digraph
--orientGraph :: [Int] -> [[Int]] -> [[Int]] --'0' forward (a<b)
orientGraph directions graph = if good then map (\tup ->if fst tup then snd tup else reverse $ snd tup) edgeTupList else error "bad graph or directions"
  where
    edgeTupList = zip (map (==0) directions) graph
    good = sameLen && orderedEdges && orderedGraph
    sameLen = length directions == length graph
    orderedEdges = foldl (\prev next ->prev && (head next < last next)) True graph
    orderedGraph = fst $ foldl (\prev next -> if fst prev then (snd prev < next, next) else (False, [0,0])) (True, [0,0]) graph

-- | This is the first level of the pipe 'strSolutionPipe'
strSolutionPipe1 :: String -> [[Int]] -> (([Int], Int), [[Int]])
strSolutionPipe1 string graph = (solutionStrToTup string, graph)

-- | This is the second level of the pipe 'strSolutionPipe'
strSolutionPipe2 :: (([Int], Int), [[Int]]) -> ([[Int]], Int)
strSolutionPipe2 ((binList, number), graph) = (orientGraph binList graph, number)

-- | This is the third level of the pipe 'strSolutionPipe'
strSolutionPipe3 :: ([[Int]], Int) -> IO Bool
strSolutionPipe3 (digraph, number) = do
  ioNum <- graphToNumCycles digraph True
  let supposedNum = number
  return $ ioNum == supposedNum

-- | This function takes a solution string and a graph and returns whether the solution agrees with the graphToNumCycles interpretation
strSolutionPipe :: String -> [[Int]] -> IO Bool
strSolutionPipe string graph = strSolutionPipe3 $ strSolutionPipe2 $ strSolutionPipe1 string graph

-- | This function takes a file (path) and checks each solution against the graphToNumCycles interpretation
checkMaxCySolution :: FilePath -> IO Bool
checkMaxCySolution file = do
  handle <- openFile file ReadMode
  solutionFile <- catch (readFile file) handler
  --goodFile <- return (finished $ lines solutionFile) -- && (good_graph solutionFile)
  let graph = read $ head $ lines solutionFile
  let solutionsStr = trim $ lines solutionFile
  print graph
  -- here, need to write function converting a single solution into (binary list, number)->(digraph, number)->(number from graphToNumCycles, number)->(fst %) == (snd %)
  -- Solutions are of the form "[01010101001,6784765]"
  whichValid <- mapM (\str -> return $ strSolutionPipe str graph) solutionsStr :: IO [IO Bool]
  let whichValidTups = zip whichValid (map return [0..])
  invalidTups <- filterM trueFst whichValidTups
  invalid <- mapM snd invalidTups :: IO [Int]
--  putStrLn "[Begin failures]"
--  (putStrLn . show) invalid
--  putStrLn "[End failures]"
  let allGood = null invalid
  return $ allGood && finished (lines solutionFile)
  where
    trueFst x0 = do
      first <- fst x0
      return $ not first
    finished list = last list == "FINISHED."
    handler :: SomeException -> IO String
    handler _ = error "The results have disappeared under my nose."

-- | This is the cycleGraph $C_n$, composed of a single undirected cycle
cycleGraph :: Int -> [[Int]]
cycleGraph n = sort2 $ [0,n-1] : [[i-1, i] | i <- [1..n-1]]

-- | This function returns the complete graph with 'n' vertices
completeGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
completeGraph n = sort2 [[a,b] | a <- [0..n-1], b <- [0..n-1], a<b]

-- | This function returns the number of undirected cycles in (completeGraph n)
-- The formula is divided by 'k' because with cycles of size k, there are k orientation of each cycle.
-- cycles size k require three choices: n possibilities, n-1, n-2 etc.
-- Sum[Product[(i - k + n)/2 k, {i, 1, k}], {k, 3, n}] (Undirected cycles, '/2' removed for directed cycles)
completeGraphNumCy :: Int -> Int --Integral a => a -> a
completeGraphNumCy n = if good then sum  [div (product [i - k + n | i <- [1..k]]) k | k <- [3..n]] else 10^12
  where
    good = n < 20


-- | This function returns the shuttle graph of size n, which looks like <|=|=|=|>
-- The following shows how the formula was derived:
-- 3->1,4
-- 4->2,3
-- 5->3,6
-- 6->4,5
-- n->n - 2, n - 1 + 2 * (mod n 2)
-- The shuttle graph is good for debugging because of the following property:
--    There are (n+1) cycles that are a cap or middle square (units)
--    There are (n+0) cycles that are an adjacent pair   of units
--    There are (n-1) cycles that are an adjacent triple of units
--    etc.
-- Because of this property, this graph has exactly (2 + 3 n + n^2)/2 cycles (equal to TriangularNumber(n+1)).
-- This graph has 8 + 3*n edges
shuttleGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
shuttleGraph n = sort2 $ [0,1] : [0,2] : [1,2] : [2*n-1, 2*n+1] : [2*n, 2*n+1] : [[m, m - 2] | m <- [3..2*n]] ++ [[m, m+1] | m <- [3,5..2*n-1]]

-- | Returns the number of undirected cycles in (shuttleGraph n)
shuttleGraphNumCy :: Int -> Int --Integral a => a -> a
shuttleGraphNumCy n = 2 + 3*n + n^2 -- modified from div (2 + 3*n + n^2) 2, because undirected, not directed cycles found

-- | This function returns the wheel graph of size n
-- Constructed by making the spokes from '0', adding all but one of the outer cycle, then adding the final edge
-- This graph has 2*(n+1) edges
wheelGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
wheelGraph n = sort2 $ [[0, i] | i <- [1..(n-1)]] ++ [[j, j+1] | j <- [1..(n-2)]] ++ [[1, n-1]]

-- | For the wheel graph, starting with n == 4 (by mathematica's definition, isomorphic to K4),
--    The nth graph is (n-1) triangles joined at a common central vertex and each joined to the
--    next in a wheel. The number of cycles may be found as follows:
--      ( 1 ) There are (n-1)     1-triangle cycles
--      ( 2 ) There are (n-1)     2-triangle cycles
--      ( . ) ...
--      (n-2) There are (n-1) (n-2)-triangle cycles
--  With the addition of the single cycle of all the triangles, this gives that there is a total
--    of (n-1)*(n-2) + 1 cycles
wheelGraphNumCy :: Int -> Int --Integral a => a -> a
wheelGraphNumCy n = 2*((n - 1)*(n - 2) + 1) -- 2*\x added because undirected, not directed cycles are found

-- | This function resizes an input for "sane" use in testing, based on facts about the graph given
resizeN :: Int -> Int -> Int
resizeN n whichGraph = bringDown $ bringUpToMin (abs n)
  where
    bringDown x = if lessThanMax x then x else 4 + mod x 5 -- this gives a range of [4..8]
    bringUpToMin x = if x < minsize then minsize else x
    lessThanMax x = (maxNumCyForTest >= numCy x) && (maxNumEdgesForTest >= numEd x)
    minsize = [3, 3, 4, 4] !! whichGraph
    graph = [cycleGraph, completeGraph, shuttleGraph, wheelGraph] !! whichGraph
    numCy = [const  2, completeGraphNumCy, shuttleGraphNumCy, wheelGraphNumCy] !! whichGraph
    numEd = [id, \m ->div (n*(n-1)) 2, \m ->8 + 3*m, \m ->2*(m+1)] !! whichGraph

-- | Taken from <http://stackoverflow.com/questions/16108714/haskell-removing-duplicates-from-a-list>
rmdups :: (Ord a) => [a] -> [a]
rmdups = map head . group . sort

-- | This function takes a list and the two first elements (if they exist) from 'swaps' and swaps the elements at those indices, or those indices mod (the length of the list)
listSwap :: [Int] -> [Int] -> [Int]
listSwap list swaps = if (length list < 1) || (length swaps < 2) then list else map switch list
  where
    switch x
      | x == a1 = b1
      | x == b1 = a1
      | otherwise = x
    len = length list
    a0 = head swaps
    b0 = swaps !! 1
    a1 = rerange a0
    b1 = rerange a1
    rerange x = mod (x-1) len + 1 -- this moves x into the range [1..len]

-- | This tests that 'listSwap' is its own inverse for lists without duplicates
prop_listSwapReversible :: [Int] -> [Int] -> Property
prop_listSwapReversible inlist seeds = property ( listSwap (listSwap list (take 2 seeds)) (reverse (take 2 seeds)) == list )
  where
    list = rmdups inlist

-- | This function performs 'listSwap' on the list using the first two (if they exist) elements of 'seeds', removes the first element of 'seeds' and repeats.
-- Thus, it can take a list of seeds to permute the list in any fashion (as any permutation is the composition of some list of transpositions)
permuteList :: [Int] -> [Int] -> [Int]
permuteList list seeds
    | (length list < 1) || (length seeds < 2) = list
    | otherwise = permuteList (listSwap list (take 2 seeds)) (tail seeds)

-- | This function uses a list of seeds to shuffle the vertex labels (indices) in a graph
shuffleGraph :: [[Int]] -> [Int] -> [[Int]]
shuffleGraph graph seeds = map (map (\v ->permuted !! v)) graph
  where
    permuted = permuteList [0..(maximum $ map maximum graph)] seeds

-- | This is a general monadic tester for the 'graphToNumCycles' function, using a known result for the number of cycles
--testNumCyShuffled :: [[Int]] -> Int -> [Int] -> Property
testNumCyShuffled graph result seeds = monadicIO $ do
  run $ putStrLn $ "graph: " ++ show graph ++ ";  seeds: " ++ show seeds
  resultFromC <- run $ graphToNumCycles graph False
  let resultKnown = result
  assert (resultFromC == resultKnown)

-- | This property takes a graph and a known result for the number of undirected cycles to test 'graphToNumCycles'
testNumCy :: [[Int]] -> Int -> Property
testNumCy graph result = monadicIO $ do
  resultFromC <- run $ graphToNumCycles graph False
--  resultKnown <- return result
  assert (resultFromC == result)

-- | This property checks that a cycle graph of any valid size has two (directed) cycles
prop_goodCycleGraphNumCy :: Int -> Property
prop_goodCycleGraphNumCy n = testNumCy graph 2
  where
    graph = cycleGraph nGood
    nGood = resizeN n 0

-- | This property check that a cycle graph of any valid size and permutation of vertex labels has two (directed) cycles
prop_goodCycleGraphNumCyShuffled :: Int -> [Int] -> Property
prop_goodCycleGraphNumCyShuffled n = testNumCyShuffled graph 2
  where
    graph = cycleGraph nGood
    nGood = resizeN n 0

-- | This function returns a complete graph with resized input
goodCompleteGraph :: Int -> [[Int]]
goodCompleteGraph n = completeGraph $ resizeN n 1

-- | This property performs as 'prop_goodCycleGraphNumCy', except for complete graphs
prop_goodCompleteGraphNumCy :: Int -> Property
prop_goodCompleteGraphNumCy n = testNumCy (goodCompleteGraph n) result
  where
    result = completeGraphNumCy nGood
    nGood  = resizeN n 1

-- | This property performs as 'prop_goodCycleGraphNumCyShuffled', except for complete graphs
prop_goodCompleteGraphNumCyShuffled :: Int -> [Int] -> Property
prop_goodCompleteGraphNumCyShuffled n = testNumCyShuffled (goodCompleteGraph n) result
  where
    result = completeGraphNumCy nGood
    nGood  = resizeN n 1

-- | This property performs as 'prop_goodCycleGraphNumCy', except for shuttle graphs
prop_goodShuttleGraphNumCy :: Int -> Property
prop_goodShuttleGraphNumCy n = testNumCy (shuttleGraph nGood) result
  where
    result = shuttleGraphNumCy nGood
    nGood  = resizeN n 2

-- | This property performs as 'prop_goodCycleGraphNumCyShuffled', except for shuttle graphs
prop_goodShuttleGraphNumCyShuffled :: Int -> [Int] -> Property
prop_goodShuttleGraphNumCyShuffled n = testNumCyShuffled graph result
  where
    graph  = shuttleGraph nGood
    result = shuttleGraphNumCy nGood
    nGood  = resizeN n 2

-- | This property performs as 'prop_goodCycleGraphNumCy', except for wheel graphs
prop_goodWheelGraphNumCy :: Int -> Property
prop_goodWheelGraphNumCy n = testNumCy (wheelGraph nGood) result
  where
    result = wheelGraphNumCy nGood
    nGood  = resizeN n 3

-- | This property performs as 'prop_goodCycleGraphNumCyShuffled', except for wheel graphs
prop_goodWheelGraphNumCyShuffled :: Int -> [Int] -> Property
prop_goodWheelGraphNumCyShuffled n = testNumCyShuffled graph result
  where
    graph  = wheelGraph nGood
    result = wheelGraphNumCy nGood
    nGood  = resizeN n 3

-- | This function allows one to randomly trim a list of any size, given an arbitrary seed (here called 'moddedsize')
trimByLenMod :: [a] -> Int -> [a]
trimByLenMod list moddedsize = take thisMany list
  where
    thisMany = if len > 0 then mod (abs moddedsize) len + 1 else 0
    len = length list

-- | This is the non-property form of 'testMaxCy'
testMaxCy' :: [[Int]] -> Int -> Int -> IO Bool
testMaxCy' graph splitbits seed = do
  graphToMaxcyCode graph splitbits foldername "maxcy_testing"
  compileAllInDir foldername
  runAllInDir foldername
  files <- getDirectoryContents foldername :: IO [FilePath]
  let txtFile file = (last file == 't') && (last (init file) == 'x') && (last (init $ init file) == 't') && (last (init $ init $ init file) == '.')
  text_files_untrimmed <- return $ filter txtFile files :: IO [FilePath]
  let text_files = trimByLenMod text_files_untrimmed seed
  checked <- mapM checkMaxCySolution text_files :: IO [Bool]
  let checkedTups = zip (map return checked) (map return [0..])
  invalidTups <- filterM trueFst checkedTups
  invalid <- mapM snd invalidTups :: IO [Int]
--  putStrLn "[Begin failures]"
--  (putStrLn . show) invalid
--  putStrLn "[End failures]"
  let allGood = null invalid
  when allGood (removeDirIfExists foldername)
  return allGood
  where
    trueFst x0 = do
      first <- fst x0
      return $ not first
    foldername = "testMaxCy"

-- | This is a general monadic tester for the 'graphToMaxCyCode' function, using 'graphToNumCycles' to check a random subset of its results
testMaxCy :: [[Int]] -> Int -> Int -> Property
testMaxCy graph splitbits seed = monadicIO $ run $ testMaxCy' graph splitbits seed

-- | This value should be kept small; it will generate 2^maxsplitbits MaxCy code pieces,
-- each of which will generate an exponential (by back of a napkin calculation) number of possible solutions,
-- each of which will be checked by 'graphToNumCycles'.
maxsplitbits = 5 + 1 :: Int

-- | This property checks the 'graphToMaxcyCode' function for complete graphs of reasonable and valid size
prop_goodCompleteGraphMaxCy :: Int -> Int -> Int -> Property
prop_goodCompleteGraphMaxCy n splitbits = testMaxCy graph splitbitsGood
  where
    graph         = completeGraph nGood
    splitbitsGood = if (abs splitbits >= 0) && (abs splitbits < maxsplitbits) then abs splitbits else 0
    nGood         = resizeN n 1

-- | This property checks the 'graphToMaxcyCode' function for shuttle graphs of reasonable and valid size
prop_goodShuttleGraphMaxCy :: Int -> Int -> Int -> Property
prop_goodShuttleGraphMaxCy n splitbits = testMaxCy graph splitbitsGood
  where
    graph         = shuttleGraph nGood
    splitbitsGood = if (abs splitbits >= 0) && (abs splitbits < maxsplitbits) then abs splitbits else 0
    nGood         = resizeN n 2

-- | This property checks the 'graphToMaxcyCode' function for wheel graphs of reasonable and valid size
prop_goodWheelGraphMaxCy :: Int -> Int -> Int -> Property
prop_goodWheelGraphMaxCy n splitbits = testMaxCy graph splitbitsGood
  where
    graph         = wheelGraph nGood
    splitbitsGood = if (abs splitbits >= 0) && (abs splitbits < maxsplitbits) then abs splitbits else 0
    nGood         = resizeN n 3

-- | Checks all properties with HSpec
main' :: IO ()
main' = hspec $ do
  describe "readInt" $ do
    context "when used with a show Int" $ do
      it "returns the Int" $ property $
        prop_readInt
  describe "readIntList" $ do
    context "when used with a show [Int]" $ do
      it "returns the [Int]" $ property $
        prop_readIntList
  describe "listSwap" $ do
    context "when used with a pairs of [Int]'s" $ do
      it "is its own inverse" $ property $
        prop_listSwapReversible
  describe "graphToNumCycles" $ do
    context "when used with a simple cycle" $ do
      it "has 2 cycles" $ property $
        prop_goodCycleGraphNumCy
    context "when used with a simple cycle (shuffled)" $ do
      it "has 2 cycles" $ property $
        prop_goodCycleGraphNumCyShuffled
    context "when used with complete graphs" $ do
      it "has Sum[Product[(i - k + n)/k, {i, 1, k}], {k, 3, n}] cycles" $ property $
        prop_goodCompleteGraphNumCy
    context "when used with complete graphs (shuffled)" $ do
      it "has Sum[Product[(i - k + n)/k, {i, 1, k}], {k, 3, n}] cycles" $ property $
        prop_goodCompleteGraphNumCyShuffled
    context "when used with shuttle graphs" $ do
      it "has (2 + 3*n + n^2) cycles" $ property $
        prop_goodShuttleGraphNumCy
    context "when used with shuttle graphs (shuffled)" $ do
      it "has (2 + 3*n + n^2) cycles" $ property $
        prop_goodShuttleGraphNumCyShuffled
    context "when used with wheel graphs" $ do
      it "has 2*((n-1)*(n-2) + 1) cycles" $ property $
        prop_goodWheelGraphNumCy
    context "when used with wheel graphs (shuffled)" $ do
      it "has 2*((n-1)*(n-2) + 1) cycles" $ property $
        prop_goodWheelGraphNumCyShuffled
  describe "graphToMaxCyCode" $ do
    context "when used with complete graphs" $ do
      it "agrees in its solutions with graphToNumCycles" $ property $
        prop_goodCompleteGraphMaxCy
    context "when used with shuttle graphs" $ do
      it "agrees in its solutions with graphToNumCycles" $ property $
        prop_goodShuttleGraphMaxCy
    context "when used with wheel graphs" $ do
      it "agrees in its solutions with graphToNumCycles" $ property $
        prop_goodWheelGraphMaxCy

makeMaxcyForAll :: [(String,[[Int]])] -> IO ()
makeMaxcyForAll listofgraphs = do
  let tupList = enum strippedList
  mapM_ makeCode tupList
  putStrLn "Done."
    where
      strippedList = map snd listofgraphs

makeCode :: (Int, [[Int]]) -> IO String
makeCode graphTup = do
  print graphNum
  graphToMaxcyCode graph splitbits foldername filename
    where
      graphNum = fst graphTup
      graph = snd graphTup
      splitbits = if length graph > 31 then length graph - 31 else 0 -- 31 is size of largest "managable" maxcy c program (by experiment)
      foldername = "graphNum_" ++ show (length graph) ++ "_" ++ show graphNum
      filename = foldername

main :: IO ()
main = main' --do
--  mainDone <- main'
--  makeMaxcyForAll gList

-- 33+







