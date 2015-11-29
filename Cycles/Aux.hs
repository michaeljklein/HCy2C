module Cycles.Aux where

import Data.Maybe

-- | This function returns 'True' if the given graph has: a smallest vertex of index '0', sorted edges ([a,b] <-> a < b)
goodGraphList :: Integral a => [[a]] -> Bool
goodGraphList list = not (any (\x -> head x >= x!!1) list) && (minimum (map minimum list) == 0)

-- | Given a list of the form [a,b..c,d] this function will return [b..c], trimming off the first and last elements
trimList :: Integral a => [a] -> [a]
trimList list = if last list == 0 then trimList (init list) else list

-- | 'wrapAround' appends the first element to the list
wrapAround :: [a] -> [a]
wrapAround [] = []
wrapAround (x:xs) = [x] ++ xs ++ [x]

-- | 'elemIndex'' is the same as 'elemIndex', except it allows for any Integral type as the index and has no Maybe
elemIndex' :: (Eq a, Integral b) => a -> [a] -> b -> b
elemIndex' _ [] _ = error "you tried to get the index of an element from an empty list"
elemIndex' x (y:ys) p = if x == y then p else elemIndex' x ys (p + 1)

-- | This function maps: True -> 1, False -> 0
bool :: Integral a => Bool -> a
bool x = if x then 1 else 0

-- | 'length'' outputs a general Integral type
-- length' :: [a] -> Int
-- length' = length
-- length' :: (Eq a, Integral b) => [a] -> b
-- length' l = if null l then 0 else 1 + length' (tail l)

-- | This is an integral type allowing version of 'replicate'
replicate' :: Integral b => a -> b -> [a]
replicate' x t = map (const x) [1..t]

-- | 'padMod' pads the end of the list with the given padding so that the final length is 0 modulo the given modulus
-- padMod :: Integral a => [a] -> a -> a -> [a]
-- padMod list padding modulus = list ++ replicate' padding extra
--                 where
--                     extra = mod ((-1) * length' list) modulus
padMod :: [Int] -> Int -> Int -> [Int]
padMod list padding modulus = list ++ replicate padding extra
  where
    extra = mod ((-1) * length list) modulus



-- | 'elemIndex''' is the same as 'elemIndex'', except it allows Maybe
elemIndex'' :: (Eq a, Integral b) => a -> [a] -> b -> Maybe b
elemIndex'' _ [] _ = Nothing
elemIndex'' x (y:ys) p = if x == y then Just p else elemIndex'' x ys (p + 1)
--nojust :: Maybe t -> t
--nojust (Just a) = a
--el_prop x list = if (el x list) == Nothing then True else (list !! (nojust $ el x list)) == x
--quickCheck el_prop
--(All good)

-- | This function takes a list and position and gets the element in the list at that position (without using a Maybe t0)
getElem :: Integral b => [a] -> b -> a
getElem l 0 = head l
getElem [] _ = error "index out of range"
getElem (_:ls) p = getElem ls (p-1)

-- | 'formatByDict' takes a string and a dictionary composed of [(key_string, result_string)] and returns the string with the appropriate key replaced (if any) ((only replaces one key))
formatByDict :: String -> [(String, String)] -> String
formatByDict string dictionary = if isNothing location then string else snd $ getElem dictionary (fromJust location)
                        where
                            location = elemIndex'' string (map fst dictionary) 0

-- This function makes the C code look better, but unfortunately it is horribly slow.
-- removeExtraNewlines :: String -> String
-- removeExtraNewlines string
--   | (length string) < 2  = string
--   | (x == y) && (x == '\n') =     removeExtraNewlines (y:zs)
--   | otherwise            = x : removeExtraNewlines (y:zs)
--     where
--       x  = head string
--       y  = head $ tail string
--       zs = tail $ tail string

-- | For 'padStrLeft0s' s t, 's' is the string, 'l' is how long to make the final one
-- padStrLeft0s :: (Integral a) => String -> a -> String
-- padStrLeft0s s t = if length' s >= t then s else padStrLeft0s ('0':s) t
padStrLeft0s :: String -> Int -> String
padStrLeft0s s t = if length s >= t then s else padStrLeft0s ('0':s) t

-- | Number of decimal digits
digLen10 :: (Num a, Integral a, Eq a) => a -> a
digLen10 0 = 0
digLen10 n = 1 + digLen10 (div n 10)

-- | Get first element of l that's not equal to 'a' (assuming no repetitons)
otherElem :: Eq a => a -> [a] -> a
otherElem a l = if head l == a then head $ tail l else head l

-- | This is a custom implementation of 'unlines'. See source for details
unlines' :: [String] -> String
unlines' = foldr (\a b -> a ++ "\n" ++ b) ""

-- | This is a general typed version of 'trimList'
trim :: [a] -> [a]
trim list = init $ tail list

-- | This converts a haskell type (show List) to something to be used in the C code
hStringToCList :: String -> String
hStringToCList string = "[" ++ trim string ++ "]"

-- | This converts a list to a [(Element Index, Element)]
enum :: [a] -> [(Int, a)]
enum = zip [0..]

-- | This function takes a list of directions encoded as '1's and '0's ('0' is forward, i.e. [a,b] -> a<b) and a graph and returns a digraph
orientGraph :: (Ord a1, Num a1, Num a, Eq a) => [a] -> [[a1]] -> [[a1]] -- '0' forward (a<b)
orientGraph directions graph = if good then map (\tup ->if fst tup then snd tup else reverse $ snd tup) edgeTupList else error "bad graph or directions"
  where
    edgeTupList = zip (map (==0) directions) graph
    good = sameLen && orderedEdges && orderedGraph
    sameLen = length directions == length graph
    orderedEdges = foldl (\prev next ->prev && (head next < last next)) True graph
    orderedGraph = fst $ foldl (\prev next -> if fst prev then (snd prev < next, next) else (False, [0,0])) (True, [0,0]) graph


