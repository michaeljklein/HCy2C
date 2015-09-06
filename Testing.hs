--module Testing where
import Forcy
import Test.Hspec
import Test.QuickCheck
import Test.QuickCheck.Monadic

-- This is the test suite. Use "*y and "*p to copy between files.

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

-- | This function returns the complete graph with 'n' vertices
completeGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
completeGraph n = [[a,b] | a <- [0..n-1], b <- [0..n-1], a<b]

-- | This function returns the number of undirected cycles in (completeGraph n)
-- The formula is divided by 'k' because with cycles of size k, there are k orientation of each cycle.
-- cycles size k require three choices: n possibilities, n-1, n-2 etc.
-- Sum[Product[(i - k + n)/2 k, {i, 1, k}], {k, 3, n}] (Undirected cycles, '/2' removed for directed cycles)
completeGraphNumCy :: Int -> Int --Integral a => a -> a
completeGraphNumCy n = foldl (+) 0 [(div (foldl (*) 1 [i - k + n | i <- [1..k]]) k) | k <- [3..n]]


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
shuttleGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
shuttleGraph n = [0,1] : [0,2] : [1,2] : [2*n-1, 2*n+1] : [2*n, 2*n+1] : [[m, m - 2] | m <- [3..2*n]] ++ [[m, m+1] | m <- [3,5..2*n-1]]

-- | Returns the number of undirected cycles in (shuttleGraph n)
shuttleGraphNumCy :: Int -> Int --Integral a => a -> a
shuttleGraphNumCy n = (2 + 3*n + n^2) -- modified from div (2 + 3*n + n^2) 2, because undirected, not directed cycles found

-- | This function returns the wheel graph of size n
-- Constructed by making the spokes from '0', adding all but one of the outer cycle, then adding the final edge
wheelGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
wheelGraph n = [[0, i] | i <- [1..(n-1)]] ++ [[j, j+1] | j <- [1..(n-2)]] ++ [[1, n-1]]

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


-- | This property takes a graph and a known result for the number of undirected cycles to test graphToNumCycles
testNumCy :: [[Int]] -> Int -> Property
testNumCy graph result = monadicIO $ do
  resultFromC <- run $ graphToNumCycles graph False
  resultKnown <- return result
  assert (resultFromC == resultKnown)

prop_goodCompleteGraph :: Int -> Property
prop_goodCompleteGraph n = testNumCy graph result
  where
    graph  = completeGraph nGood
    result = completeGraphNumCy nGood
    nGood  = if (abs n) > 2 then (abs n) else 3

prop_goodShuttleGraph :: Int -> Property
prop_goodShuttleGraph n = testNumCy graph result
  where
    graph  = shuttleGraph nGood
    result = shuttleGraphNumCy nGood
    nGood  = if (abs n) > 3 then (abs n) else 4

prop_goodWheelGraph :: Int -> Property
prop_goodWheelGraph n = testNumCy graph result
  where
    graph  = wheelGraph nGood
    result = wheelGraphNumCy nGood
    nGood  = if (abs n) > 0 then (abs n) else 1

main :: IO ()
main = hspec $ do
  -- describe "read" $ do
  --   context "when used with ints" $ do
  --     it "is inverse to show" $ property $
  --       \x -> (read . show) x == (x :: Int)
  describe "graphToNumCycles" $ do
    context "when used with complete graphs" $ do
      it "has Sum[Product[(i - k + n)/k, {i, 1, k}], {k, 3, n}] cycles" $ property $
        prop_goodCompleteGraph
    context "when used with shuttle graphs" $ do
      it "has (2 + 3*n + n^2) cycles" $ property $
        prop_goodShuttleGraph
    context "when used with wheel graphs" $ do
      it "has 2*((n-1)*(n-2) + 1) cycles" $ property $
        prop_goodWheelGraph

-- MAKE sure cyclelists out of graphToCycles are properly sorted by snd of cycle.
-- Randomly rename/shuffle edge labels and make sure that the results are the same.
-- Use Test.QuickCheck.Monadic
-- Move checkMaxCySolutions to this file.
-- Add function to go graph -> files -> check all
-- Add option for splitbits in above function

