module Cycles.Aux where


import Data.Maybe

goodGraphList :: Integral a => [[a]] -> Bool
goodGraphList list = ((length (filter (\x -> x!!0 >= x!!1) list)) == 0) && ((minimum $ map minimum list) == 0)

trimList :: Integral a => [a] -> [a]
trimList list = if (last list) == 0 then trimList (init list) else list

-- | 'wrapAround' appends the first element to the list
wrapAround :: [a] -> [a]
wrapAround [] = []
wrapAround (x:xs) = [x] ++ xs ++ [x]

-- | 'elemIndex'' is the same as 'elemIndex', except it allows for any Integral type as the index and has no Maybe
elemIndex' :: (Eq a, Integral b) => a -> [a] -> b -> b
elemIndex' _ [] _ = error "you tried to get the index of an element from an empty list"
elemIndex' x (y:ys) p = if x == y then p else elemIndex' x ys (p + 1)

bool :: Integral a => Bool -> a
bool x = if x then 1 else 0

-- | 'length'' outputs a general Integral type
--length' :: Integral b => [a] -> b -> b
--length' [] p = p
--length' (_:xs) p = length' xs (p+1)
length' :: (Eq a, Integral b) => [a] -> b
length' l = if l == [] then 0 else 1 + length' (tail l)

replicate' :: Integral b => a -> b -> [a]
replicate' x t = map (\_ -> x) [1..t]

-- | 'padMod' pads the end of the list with the given padding so that the final length is 0 modulo the given modulus
padMod :: Integral a => [a] -> a -> a -> [a]
padMod list padding modulus = list ++ (replicate' padding extra)
                where
                    extra = mod (-1 * (length' list)) modulus

---- Now all we need to do before building is make the variable text generators
---- I will be using a custom formatter: each line that needs more info filled in will be marked ":[name of thing to insert]"

-- | 'elemIndex''' is the same as 'elemIndex'', except it allows Maybe
elemIndex'' :: (Eq a, Integral b) => a -> [a] -> b -> Maybe b
elemIndex'' _ [] _ = Nothing
elemIndex'' x (y:ys) p = if x == y then Just p else elemIndex'' x ys (p + 1)
--nojust :: Maybe t -> t
--nojust (Just a) = a
--el_prop x list = if (el x list) == Nothing then True else (list !! (nojust $ el x list)) == x
--quickCheck el_prop
--(All good)

getElem :: Integral b => [a] -> b -> a
getElem l 0 = head l
getElem [] _ = error "index out of range"
getElem (_:ls) p = getElem ls (p-1)

-- | 'formatByDict' takes a string and a dictionary composed of [(key_string, result_string)] and returns the string with the appropriate key replaced (if any) ((only replaces one key))
formatByDict :: String -> [(String, String)] -> String
formatByDict string dictionary = if location == Nothing then string else snd $ getElem dictionary (fromJust location)
                        where
                            location = elemIndex'' string (map fst dictionary) 0

removeExtraNewlines :: String -> String
removeExtraNewlines string
  | (length string) < 2  = string
  | (x == y) && (x == '\n') =     removeExtraNewlines (y:zs)
  | otherwise            = x : removeExtraNewlines (y:zs)
    where
      x  = head string
      y  = head $ tail string
      zs = tail $ tail string

-- | 's' is the string, 'l' is how long to make the final one
padStrLeft0s :: (Integral a) => String -> a -> String
padStrLeft0s s t = if (length' s) >= t then s else padStrLeft0s ('0':s) t

-- | Number of decimal digits in n
digLen10 :: (Num a, Integral a, Eq a) => a -> a
digLen10 0 = 0
digLen10 n = 1 + digLen10 (div n 10)

-- | Get first element of l that's not equal to a (assuming no repetitons)
otherElem :: Eq a => a -> [a] -> a
otherElem a l = if (head l) == a then head $ tail l else head l

unlines' :: [[Char]] -> [Char]
unlines' s = foldr (\a b -> a ++ "\n" ++ b) "" s

trim :: [a] -> [a]
trim list = init $ tail list

hStringToCList :: String -> String
hStringToCList string = "[" ++ (trim string) ++ "]"

enum :: [a] -> [(Int, a)]
enum list = zip [0..] list


