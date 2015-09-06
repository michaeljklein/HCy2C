--module Testing where
import Forcy
import Test.Hspec
import Test.QuickCheck
import Test.QuickCheck.Monadic

-- This is the test suite. Use "*y and "*p to copy between files.

-- The formula is divided by 'k' because with cycles of size k, there are k orientation of each cycle.
-- cycles size k require three choices: n possibilities, n-1, n-2 etc.
-- Sum[Product[(i - k + n)/2 k, {i, 1, k}], {k, 3, n}] (Undirected cycles, '/2' removed for directed cycles)
completeGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
completeGraph n = [[a,b] | a <- [0..n-1], b <- [0..n-1], a<b]

completeGraphNumCy :: Int -> Int --Integral a => a -> a
completeGraphNumCy n = foldl (+) 0 [(div (foldl (*) 1 [i - k + n | i <- [1..k]]) k) | k <- [3..n]]


-- lookes like <|=|=|=|>
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

shuttleGraphNumCy :: Int -> Int --Integral a => a -> a
shuttleGraphNumCy n = (2 + 3*n + n^2) -- modified from div (2 + 3*n + n^2) 2, because undirected, not directed cycles found


--  For the wheel graph, starting with n == 4 (by mathematica's definition, isomorphic to K4),
--    the nth graph is (n-1) triangles joined at a common central vertex and each joined to the
--    next in a wheel. The number of cycles may be found as follows:
--      ( 1 ) There are (n-1)     1-triangle cycles
--      ( 2 ) There are (n-1)     2-triangle cycles
--      ( . ) ...
--      (n-2) There are (n-1) (n-2)-triangle cycles
--  With the addition of the single cycle of all the triangles, this gives that there is a total
--    of (n-1)*(n-2) + 1 cycles
--
-- Constructed by making the spokes from '0', adding all but one of the outer cycle, then adding the final edge
wheelGraph :: Int -> [[Int]] --Integral a => a -> [[a]]
wheelGraph n = [[0, i] | i <- [1..(n-1)]] ++ [[j, j+1] | j <- [1..(n-2)]] ++ [[1, n-1]]

wheelGraphNumCy :: Int -> Int --Integral a => a -> a
wheelGraphNumCy n = 2*((n - 1)*(n - 2) + 1) -- 2*\x added because undirected, not directed cycles are found


-- prop_factor :: Positive Integer -> Property
-- prop_factor (Positive n) = monadicIO $ do
--     factors <- run (factor n)

--   assert (product factors == n)

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

-- main = do
--   quickCheck prop_goodWheelGraph
--   quickCheck prop_goodShuttleGraph

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

