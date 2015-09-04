

-- This is the test suite.

completeGraph :: Integral a => a -> [[a]]
completeGraph n = [[a,b] | a <- [0..n-1], b <- [0..n-1], a<b]

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
shuttleGraph :: Integral a => a -> [[a]]
shuttleGraph n = [0,1] : [0,2] : [1,2] : [2*n-1, 2*n+1] : [2*n, 2*n+1] : [[m, m - 2] | m <- [3..2*n]] ++ [[m, m+1] | m <- [3,5..2*n-1]]

shuttleGraphNumCy :: Integral a => a -> a
shuttleGraphNumCy n = div (2 + 3*n + n^2) 2

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
wheelGraph :: Integral a => a -> [[a]]
wheelGraph n = [[0, i] | i <- [1..(n-1)]] ++ [[j, j+1] | j <- [1..(n-2)]] ++ [[1, n-1]]

wheelGraphNumCy :: Integral a => a -> a
wheelGraphNumCy n = (n - 1)*(n - 2) + 1


