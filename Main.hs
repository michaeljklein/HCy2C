module Main where

--module Testing where
--import Cycles.Forcy
import Cycles.Maxcy
import Cycles.Findcy
import Cycles.IO
import Cycles.Aux
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

-- Because the number of cycles and edges tried by quickcheck can blow up quickly, these are the ranges allowable for (reasonably) fast tests
-- Tested on Macbook Pro 15", Late 2011, 8 GB RAM, 2.5 GHZ Intel Core i7, 64-bit
maxNumCyForTest = completeGraphNumCy 6
maxNumEdgesForTest = 100

-- removeDirIfExists :: FilePath -> IO ()
-- removeDirIfExists foldername = removeDirectoryRecursive foldername `catch` handleExists
--   where handleExists e
--          | isDoesNotExistError e = return ()
--          | otherwise = throwIO e

sort2 lists = sort $ map sort lists

-- | This function takes a string and char and returns everything up to (but not including) that char
cutUntoChar :: [Char] -> Char -> [Char]
cutUntoChar [] _ = []
cutUntoChar (x:xs) char
    | x == char  = []
    | otherwise = x : (cutUntoChar xs char)

-- | This function converts a string like "0101010101001010" into a list of Ints
readBins :: [Char] -> [Int]
readBins [] = []
readBins ('0':xs) = 0 : (readBins xs)
readBins ('1':xs) = 1 : (readBins xs)
readBins (_:xs)   = error "list passed not composed of 0's and 1's"

-- | This function converts a solution string (such as "[10101010, 2384]") to a (list of bins, number)
solutionStrToTup :: [Char] -> ([Int], Int)
solutionStrToTup str = (readBins bins, read num)
  where
    bins = cutUntoChar (tail str) ','
    num  = reverse $ cutUntoChar (reverse $ trim str) ','

-- | This function takes a list of directions encoded as '1's and '0's ('0' is forward, i.e. [a,b] -> a<b) and a graph and returns a digraph
--orientGraph :: [Int] -> [[Int]] -> [[Int]] --'0' forward (a<b)
orientGraph directions graph = if good then map (\tup ->if fst tup then snd tup else reverse $ snd tup) edgeTupList else error "bad graph or directions"
  where
    edgeTupList = zip (map (\x ->x==0) directions) graph
    good = sameLen && orderedEdges && orderedGraph
    sameLen = (length directions) == (length graph)
    orderedEdges = foldl (\prev next ->prev && ((head next) < (last next))) True graph
    orderedGraph = fst $ foldl (\prev next -> if fst prev then ((snd prev) < next, next) else (False, [0,0])) (True, [0,0]) graph

strSolutionPipe1 :: [Char] -> [[Int]] -> (([Int], Int), [[Int]])
strSolutionPipe1 string graph = (solutionStrToTup string, graph)

strSolutionPipe2 :: (([Int], Int), [[Int]]) -> ([[Int]], Int)
strSolutionPipe2 ((binList, number), graph) = (orientGraph binList graph, number)

--strSolutionPipe3 :: ([[Int]], Int) -> IO Bool
strSolutionPipe3 (digraph, number) = do
  ioNum <- graphToNumCycles digraph True
  supposedNum <- return number
  return $ ioNum == supposedNum

-- | This function takes a solution string and a graph and returns whether the solution agrees with the graphToNumCycles interpretation
strSolutionPipe :: [Char] -> [[Int]] -> IO Bool
strSolutionPipe string graph = strSolutionPipe3 $ strSolutionPipe2 $ strSolutionPipe1 string graph

-- | This function takes a file (path) and checks each solution against the graphToNumCycles interpretation
checkMaxCySolution :: FilePath -> IO Bool
checkMaxCySolution file = do
  handle <- openFile file ReadMode
  solutionFile <- catch (readFile file) handler
  --goodFile <- return (finished $ lines solutionFile) -- && (good_graph solutionFile)
  graph <- return $ read $ head $ lines solutionFile :: IO [[Int]]
  solutionsStr <- return $ trim $ lines solutionFile
  putStrLn $ show graph
  -- here, need to write function converting a single solution into (binary list, number)->(digraph, number)->(number from graphToNumCycles, number)->(fst %) == (snd %)
  -- Solutions are of the form "[01010101001,6784765]"
  whichValid <- mapM (\str -> return $ strSolutionPipe str graph) solutionsStr :: IO [IO Bool]
  whichValidTups <- return $ zip whichValid (map return [0..])
  invalidTups <- filterM trueFst whichValidTups
  invalid <- mapM snd invalidTups :: IO [Int]
  putStrLn "[Begin failures]"
  (putStrLn . show) invalid
  putStrLn "[End failures]"
  allGood <- return $ invalid == []
  return $ allGood && (finished $ lines solutionFile)
  where
    trueFst x0 = do
      first <- fst x0
      notted <- return $ not first
      return notted
    finished = \list ->(last list) == "FINISHED."
    handler :: SomeException -> IO String
    handler _ = error "The results have disappeared under my nose."

cycleGraph :: Int -> [[Int]]
cycleGraph n = sort2 $ [0,n-1] : [[i-1, i] | i <- [1..n-1]]

-- | This function returns the complete graph with 'n' vertices
completeGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
completeGraph n = sort2 $ [[a,b] | a <- [0..n-1], b <- [0..n-1], a<b]

-- | This function returns the number of undirected cycles in (completeGraph n)
-- The formula is divided by 'k' because with cycles of size k, there are k orientation of each cycle.
-- cycles size k require three choices: n possibilities, n-1, n-2 etc.
-- Sum[Product[(i - k + n)/2 k, {i, 1, k}], {k, 3, n}] (Undirected cycles, '/2' removed for directed cycles)
completeGraphNumCy :: Int -> Int --Integral a => a -> a
completeGraphNumCy n = if good then foldl (+) 0 [(div (foldl (*) 1 [i - k + n | i <- [1..k]]) k) | k <- [3..n]] else 10^12
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
shuttleGraphNumCy n = (2 + 3*n + n^2) -- modified from div (2 + 3*n + n^2) 2, because undirected, not directed cycles found

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

resizeN :: Int -> Int -> Int
resizeN n whichGraph = bringDown $ bringUpToMin (abs n)
  where
    bringDown x = if lessThanMax x then x else 4 + (mod x 5) -- this gives a range of [4..8]
    bringUpToMin x = if x < minsize then minsize else x
    lessThanMax x = (maxNumCyForTest >= (numCy x)) && (maxNumEdgesForTest >= (numEd x))
    minsize = [3, 3, 4, 4] !! whichGraph
    graph = [cycleGraph, completeGraph, shuttleGraph, wheelGraph] !! whichGraph
    numCy = [\_ -> 2, completeGraphNumCy, shuttleGraphNumCy, wheelGraphNumCy] !! whichGraph
    numEd = [\m ->m, \m ->div (n*(n-1)) 2, \m ->8 + 3*m, \m ->2*(m+1)] !! whichGraph

-- | Taken from http://stackoverflow.com/questions/16108714/haskell-removing-duplicates-from-a-list
rmdups :: (Ord a) => [a] -> [a]
rmdups = map head . group . sort

listSwap :: [Int] -> [Int] -> [Int]
listSwap list swaps = if ((length list) < 1) || ((length swaps) < 2) then list else map switch list
  where
    switch x
      | x == a1 = b1
      | x == b1 = a1
      | otherwise = x
    len = length list
    a0 = swaps !! 0
    b0 = swaps !! 1
    a1 = rerange a0
    b1 = rerange a1
    rerange x = (mod (x-1) len) + 1 -- this moves x into the range [1..len]

prop_listSwapReversible :: [Int] -> [Int] -> Property
prop_listSwapReversible inlist seeds = property ( (listSwap (listSwap list (take 2 seeds)) (reverse (take 2 seeds))) == list )
  where
    list = rmdups inlist

permuteList :: [Int] -> [Int] -> [Int]
permuteList list seeds
    | ((length list) < 1) || ((length seeds) < 2) = list
    | otherwise = permuteList (listSwap list (take 2 seeds)) (tail seeds)

shuffleGraph :: [[Int]] -> [Int] -> [[Int]]
shuffleGraph graph seeds = map (\e ->map (\v ->permuted !! v) e) graph
  where
    permuted = permuteList [0..(maximum $ map maximum graph)] seeds

testNumCyShuffled :: [[Int]] -> Int -> [Int] -> Property
testNumCyShuffled graph result seeds = monadicIO $ do
  resultFromC <- run $ graphToNumCycles graph False
  resultKnown <- return result
  assert (resultFromC == resultKnown)

-- | This property takes a graph and a known result for the number of undirected cycles to test graphToNumCycles
testNumCy :: [[Int]] -> Int -> Property
testNumCy graph result = monadicIO $ do
  resultFromC <- run $ graphToNumCycles graph False
  resultKnown <- return result
  assert (resultFromC == resultKnown)

prop_goodCycleGraphNumCy :: Int -> Property
prop_goodCycleGraphNumCy n = testNumCy graph 2
  where
    graph = cycleGraph nGood
    nGood = resizeN n 0

prop_goodCycleGraphNumCyShuffled :: Int -> [Int] -> Property
prop_goodCycleGraphNumCyShuffled n seeds = testNumCyShuffled graph 2 seeds
  where
    graph = cycleGraph nGood
    nGood = resizeN n 0

prop_goodCompleteGraphNumCy :: Int -> Property
prop_goodCompleteGraphNumCy n = testNumCy graph result
  where
    graph  = completeGraph nGood
    result = completeGraphNumCy nGood
    nGood  = resizeN n 1

prop_goodCompleteGraphNumCyShuffled :: Int -> [Int] -> Property
prop_goodCompleteGraphNumCyShuffled n seeds = testNumCyShuffled graph result seeds
  where
    graph  = completeGraph nGood
    result = completeGraphNumCy nGood
    nGood  = resizeN n 1

prop_goodShuttleGraphNumCy :: Int -> Property
prop_goodShuttleGraphNumCy n = testNumCy graph result
  where
    graph  = shuttleGraph nGood
    result = shuttleGraphNumCy nGood
    nGood  = resizeN n 2

prop_goodShuttleGraphNumCyShuffled :: Int -> [Int] -> Property
prop_goodShuttleGraphNumCyShuffled n seeds = testNumCyShuffled graph result seeds
  where
    graph  = shuttleGraph nGood
    result = shuttleGraphNumCy nGood
    nGood  = resizeN n 2

prop_goodWheelGraphNumCy :: Int -> Property
prop_goodWheelGraphNumCy n = testNumCy graph result
  where
    graph  = wheelGraph nGood
    result = wheelGraphNumCy nGood
    nGood  = resizeN n 3

prop_goodWheelGraphNumCyShuffled :: Int -> [Int] -> Property
prop_goodWheelGraphNumCyShuffled n seeds = testNumCyShuffled graph result seeds
  where
    graph  = wheelGraph nGood
    result = wheelGraphNumCy nGood
    nGood  = resizeN n 3

trimByLenMod :: [a] -> Int -> [a]
trimByLenMod list moddedsize = take thisMany list
  where
    thisMany = if len > 0 then (mod ((abs moddedsize)) len) + 1 else 0
    len = length list

testMaxCy' :: [[Int]] -> Int -> Int -> IO Bool
testMaxCy' graph splitbits seed = do
  graphToMaxcyCode graph splitbits foldername
  compileAllInDir foldername
  runAllInDir foldername
  files <- getDirectoryContents foldername :: IO [FilePath]
  let txtFile = \file ->((last file) == 't') && ((last $ init file) == 'x') && ((last $ init $ init file) == 't') && ((last $ init $ init $ init file) == '.')
  text_files_untrimmed <- return $ filter txtFile files :: IO [FilePath]
  text_files <- return $ trimByLenMod text_files_untrimmed seed
  checked <- mapM checkMaxCySolution text_files :: IO [Bool]
  checkedTups <- return $ zip (map return checked) (map return [0..])
  invalidTups <- filterM trueFst checkedTups
  invalid <- mapM snd invalidTups :: IO [Int]
  putStrLn "[Begin failures]"
  (putStrLn . show) invalid
  putStrLn "[End failures]"
  allGood <- return $ invalid == []
  when allGood (removeDirIfExists foldername)
  return allGood
  where
    trueFst x0 = do
      first <- fst x0
      notted <- return $ not first
      return notted
    foldername = "testMaxCy"

testMaxCy :: [[Int]] -> Int -> Int -> Property
testMaxCy graph splitbits seed = monadicIO $ run $ testMaxCy' graph splitbits seed

-- | This value should be kept small; it will generate 2^maxsplitbits MaxCy code pieces,
-- each of which will generate an exponential (by back of a napkin calculation) number of possible solutions,
-- each of which will be checked by graphToNumCycles.
maxsplitbits = (5) + 1 :: Int

prop_goodCompleteGraphMaxCy :: Int -> Int -> Int -> Property
prop_goodCompleteGraphMaxCy n splitbits seed = testMaxCy graph splitbitsGood seed
  where
    graph         = completeGraph nGood
    splitbitsGood = if ((abs splitbits) >= 0) && ((abs splitbits) < maxsplitbits) then (abs splitbits) else 0
    nGood         = resizeN n 1

prop_goodShuttleGraphMaxCy :: Int -> Int -> Int -> Property
prop_goodShuttleGraphMaxCy n splitbits seed = testMaxCy graph splitbitsGood seed
  where
    graph         = shuttleGraph nGood
    splitbitsGood = if ((abs splitbits) >= 0) && ((abs splitbits) < maxsplitbits) then (abs splitbits) else 0
    nGood         = resizeN n 2

prop_goodWheelGraphMaxCy :: Int -> Int -> Int -> Property
prop_goodWheelGraphMaxCy n splitbits seed = testMaxCy graph splitbitsGood seed
  where
    graph         = wheelGraph nGood
    splitbitsGood = if ((abs splitbits) >= 0) && ((abs splitbits) < maxsplitbits) then (abs splitbits) else 0
    nGood         = resizeN n 3




main :: IO ()
main = hspec $ do
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
      it "agrees in *all* its solutions with graphToNumCycles" $ property $
        prop_goodCompleteGraphMaxCy
    context "when used with shuttle graphs" $ do
      it "agrees in *all* its solutions with graphToNumCycles" $ property $
        prop_goodShuttleGraphMaxCy
    context "when used with wheel graphs" $ do
      it "agrees in *all* its solutions with graphToNumCycles" $ property $
        prop_goodWheelGraphMaxCy

