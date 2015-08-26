import Data.Bits
import Foreign.C.Types

cs :: [[CULLong]]
cs = [0..]
ds :: [[CuLLong]]
ds = [0..]

addBit :: Bits Bool -> [[Bits CULLong]] -> [[Bits CULLong]]
addBit bit list   | bit = map (\x->\y->map (xor (shift y 1) 1) x) list
                  | _   = map (\x->\y->map (    (shift y 1)  ) x) list

popCount' :: [Bits CULLong] -> Int
popCount' vec = sum $ map popCount vec

-- addbit :: Bits Bool -> Int -> Int
-- addbit bit val  | not bit =     (shift val 1)
--                 |  bit = xor (shift val 1) 1

reduce :: Bits Bool -> (Int, [[CULLong]]) -> (Int, [[CULLong]) -> (Int, [CULLong])
reduce bit (best1, sofars1) (best2, sofars2)  | best1 > best2 = (best1, addBit bit sofars1)
                                              | best1 == best2 = (best1, addbit bit (sofars1 ++ sofars2))
                                              | best1 < best2 = (best2, addBit bit sofars2)

expand :: Bits Bool -> (Int, Int) -> (Int, [Int])
expand bit (depth, prev)  | depth == max = (popCount' curr, [curr])
                          | depth /= max = reduce bit (expand 0 (depth + 1, curr)) (expand 1 (depth + 1, curr))
                            where
                              curr  | bit = zipWith (.&.) prev (ds !! depth)
                                    | _   = zipWith (.&.) prev (cs !! depth)
