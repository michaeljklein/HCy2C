module Cycles.Maxcy where

import Cycles.Aux
import Data.Bits ( Bits((.&.), (.|.), bit) )
import Data.Function
import Data.List ( foldl', sort, sortBy )
import Data.List.Split ( chunksOf )
import Data.String.Utils ( replace )
import Foreign.C.Types ( CULLong )
import Text.Regex ( subRegex, mkRegex )

-- | 'elist' is edge list and vlist is cycle vertex list
convIndivCycle :: (Integral a, Bits a) => [[a]] -> [a] -> [(Bool, a)]
convIndivCycle elist vlist = loop elist tvlist []
                        where
                            loop :: Integral a => [[a]] -> [a] -> [(Bool, a)] -> [(Bool, a)]
                            loop _ [] output = output
                            loop elist' vlist' output = loop elist' (tail vlist') (if length vlist' < 2
                                                                                    then output
                                                                                    else (head vlist' < vlist'!!1, elemIndex' (sort (take 2 vlist')) elist' 0):output )
                            tvlist = wrapAround $ trimList vlist


-- | aVarList is a[var][j]
aVarList :: (Integral a, Bits a, Integral b, Bits b) => [[(Bool, a)]] -> a -> [b]
aVarList cyclelists var = map ((bool . elem var) . map snd) cyclelists

-- | bVarList is b[var][j]
bVarList :: (Integral a, Bits a) => [[(Bool, a)]] -> a -> [a]
bVarList cyclelists var = map (gettf . filter (\x -> snd x == var)) cyclelists
                    where
                        gettf :: Integral a => [(Bool, a)] -> a
                        gettf list = if null list
                                        then 0
                                        else bool $ fst $ head list

-- | This combines the 'aVarList' and 'bVarList' lists to give the combined cVarList
-- | Note: (1-x) == ~x for x <- [0,1]
cVarList :: (Integral a, Bits a) => [a] -> [a] -> [a]
cVarList = zipWith ((.|.) `Data.Function.on` (-) 1)

-- | This combines the 'aVarList' and 'bVarList' lists to give the combined dVarList
dVarList :: (Integral a, Bits a) => [a] -> [a] -> [a]
dVarList = zipWith (\a b -> (1-a) .|.    b  )

-- | 'listToULL' converts a length <= 64 list of 0,1 values into a single 'CULLong'
-- listToULL :: Integral a => [a] -> CULLong
-- listToULL list = if length list > 64
--                     then error "You want to use listToULLs for this (You're using listToULL)."
--                     else foldl' (.|.) 0 (zipWith (\x y -> if x == 0 then 0 else bit y) (padMod list 0 64) [0..])
listToULL :: [Int] -> CULLong
listToULL list = if length list > 64
                    then error "You want to use listToULLs for this (You're using listToULL)."
                    else foldl' (.|.) 0 (zipWith (\x y -> if x == 0 then 0 else bit y) (padMod list 0 64) [0..])

-- | 'listToULLs' converts a list of length > 64 to a list of 'CULLong' values
-- listToULLs :: Integral a => [a] -> [CULLong]
listToULLs :: [Int] -> [CULLong]
listToULLs list = map listToULL (chunksOf 64 (padMod list 0 64))

-- This adds "LLU" to the end of each number in a string, useful for generating C code with long long unsigned integers
-- However, it is SUPER slow, taking over 63% of the total time...regex's are just stupid slow for this kind of application.
-- addULLs :: String -> String
-- addULLs text = subRegex (mkRegex patc) (subRegex (mkRegex patb) text "\\1LLU}") "\\1LLU,"
--             where
--                 patc = "([0-9]{3})(,)"
--                 patb = "([0-9]{3})(})"

-- | 'listFirstAnd' replaces a!!0 with b!!0 .&. c!!0
listFirstAnd :: [[CULLong]] -> [[CULLong]] -> [[CULLong]] -> [[CULLong]]
listFirstAnd [] _  _  = []
listFirstAnd a  [] _  = a
listFirstAnd a  _  [] = a
listFirstAnd a  b  c  = zipWith (.&.) (head b) (head c) : tail a

-- | This function maps snd to the second level of a list of lists
sndMap2 :: [[(a,b)]] -> [[b]]
sndMap2 = map (map snd)

-- | This function gives the largest element of a list greater than '0', or zero if all the elements are negative
maxPositive :: (Ord a, Num a) => [a] -> a
maxPositive = foldl (\sofar next ->if sofar >= next then sofar else next) 0

-- | This function gives the tuple in a list that has the greates positive snd element
maxPositiveSnd :: (Num a, Ord b, Num b) => [(a,b)] -> (a,b)
maxPositiveSnd = foldl (\sofar next -> if snd sofar >= snd next then sofar else next) (-1,-1)

-- | This function gives the maxPositive for a list of lists
listsMaxPositive :: (Ord a, Num a) => [[a]] -> a
listsMaxPositive lists = maxPositive $ map maxPositive lists

-- | This function counts the number of occurances of x in lists
tallyElem :: Eq a => [[a]] -> a -> Int
tallyElem lists x = foldl (\count list ->count + bool (x `elem` list)) 0 lists

-- | This function finds some most commonly occuring snd element in a list of lists
aMostOftenElem :: [[(a, Int)]] -> Int
aMostOftenElem listsOfTups = fst maxTally
  where
    lists = sndMap2 listsOfTups
    tallies = map (\elem ->(elem, tallyElem lists elem)) [0..maxElem]
    maxTally = maxPositiveSnd tallies
    maxElem = listsMaxPositive lists

-- | This function takes a list of lists of tuples and switches all occurances of 'a' with 'b' and all occurances of 'b' with 'a'.
switchInTupLists :: [[(a, Int)]] -> Int -> Int -> [[(a, Int)]]
switchInTupLists lists a b = switchOne interLists1 interElem b
  where
    maximum = listsMaxPositive $ sndMap2 lists
    interElem = maximum + 1
    interLists0 = switchOne lists a interElem
    interLists1 = switchOne interLists0 b a
    switchOne lists0 a0 b0 = map (map (\e ->if snd e == a0 then (fst e, b0) else e)) lists0

-- | This function makes sure that '0' is a most often snd element in a list of lists
frontLoadTupLists :: [[(a, Int)]] -> [[(a, Int)]]
frontLoadTupLists tuplists = switchInTupLists tuplists 0 (aMostOftenElem tuplists)

-- | This function deletes the cycles which will be nulled out by the first edge being zero, i.e. it deletes cycles made impossible by fixing the 0th edge forward.
-- Additionally, this function re-frontloads the lists so that more maxcy orientations "may" be found more quickly, reducing the need to print cycles.
-- (True, _) if edge is forward in cycle, blist[][] = 0 (is how it's shown to be forward)
trimCycleList :: [[(Bool, Int)]] -> [[(Bool, Int)]]
trimCycleList cyclelist = switchInTupLists refrontloaded 0 (aMostOftenElem refrontloaded)
  where
    frontloaded = frontLoadTupLists cyclelist
    trimmed = map (\cy ->if (True, 0) `elem` cy then tail cy else cy) frontloaded -- if a cycle has (forward,0) then remove it
    refrontloaded = frontLoadTupLists cyclelist

addLLUs :: [[CULLong]] -> String
addLLUs list = (\s ->"[" ++ s ++ "]") $ init $ concatMap addLLUsSingleDepth list
	where
		addLLUsSingleDepth u = (\s ->"[" ++ s ++ "],") $ init $ concatMap (\y ->show y ++ "LLU,") u

-- | This function is a version of 'generateMaxCyCodeAtStart' that is cross-compatible with the previous way of generating the C code to find the maximally cyclic orientations of a graph
generateMaxCyCode :: [[Int]] -> [[Int]] -> Int -> Int -> Int -> String -> (String, String)
generateMaxCyCode graph cycles start end splitbits name = (fst starter start, snd starter)
  where
    starter = generateMaxCyCodeAtStart graph cycles end splitbits name

-- | This function creates a function which may be mapped to a start value (to reduce overhead in splitting up the files) to produce C code. These C code files may be compiled to produce independent programs, able to be run in parallel or even on seperate machines with different architectures.
--  Assuming variables are unlimited width for the purposes of explaining the logic: (1 is true, 0 is false) (i is the variable index, j is the digit index)
--
--	a[i][j] := is the ith edge in the jth cycle?
--
--	b[i][j] := is the ith edge backward in the jth cycle? (forward is [x,y] -> x<y )
--
--	c[i][j] := ~a[i][j] | ~b[i][j]
--
--	d[i][j] := ~a[i][j] |  b[i][j]
--
--	A[i][j] := (up to and inc. the ith var/edge) is it still possible that this digraph has the jth cycle?
--
--	A[0][j] := 1 if j < number of cycles
--
--	y[i][j] := is ith edge backward? (so 0 is forward, 1 is backward)
--
--	A[i][j] := A[i-1][j] & (~y[j] | c[i][j]) & (y[j] | d[i][j]
generateMaxCyCodeAtStart :: [[Int]] -> [[Int]] -> Int -> Int -> String -> (Int -> String, String)
generateMaxCyCodeAtStart graph cycles end splitbits filename = (\start ->unlines introlist ++ (starthere start ++ fout start) ++ unlines (map (`formatByDict` dict) codelist), printout)
    where
        twotothesplitbits = 2^splitbits
        printout = unlines ["graph:" ++ show graph,
                            "cycles:" ++ show cycles,
                            "cyclelists:" ++ show cyclelists,
                            "alist:" ++ show alist,
                            "blist:" ++ show blist,
                            "clist:",
                            --printULLs clist,
                            "dlist:",
                            --printULLs dlist,
                            "aalist:"] -- ,
                            --printULLs aalist ]

        cyclelistsUntrimmed = map (sortBySnd . convIndivCycle graph) cycles
        cyclelists = trimCycleList cyclelistsUntrimmed

        alist = map (aVarList cyclelists) [0..(-1 + length graph)]
        blist = map (bVarList cyclelists) [0..(-1 + length graph)]

        clist   = map listToULLs (zipWith cVarList alist blist)
        dlist   = map listToULLs (zipWith dVarList alist blist)
        aalist' = map (listToULLs . map (const 1)) alist
        aalist  = listFirstAnd aalist' aalist' dlist

        dict = [
         (":maxpos",     maxpos),
         (":endhere",    endhere),
         --(":starthere",  starthere),
         (":cstr",       cstr),
         (":carray",     carray),
         (":darray",     darray),
         (":xarray",     xarray),
         (":aarray",     aarray),
         (":fops_true",  fops_true),
         (":fops_false", fops_false),
         (":printouter", printouter),
         (":counter",    counter),
         (":sprinter",   sprinter),
         --(":fout",       fout),
         (":fputs",      fputs)]

        --":maxpos" static int maxpos = 2;
        maxpos = "static uint_fast32_t maxpos = " ++ show (-1 + length graph) ++ ";"

        --":endhere" static unsigned int endhere = 0;
        endhere = "static uint_fast32_t endhere = " ++ show end ++ ";" -- log2(maximum_value + 1)

        --":starthere" unsigned int starthere = 0;
        starthere = (\startplace ->"uint_fast32_t starthere = " ++ show (2 * startplace) ++ ";\n") :: Int -> String --The '2*' is to bitshift past the fixed '0' at position '0'.

        --":cstr" char str[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        cstr = "char str[" ++ show (10 + length graph) ++ "] = {" ++ trim (show $ replicate (10 + length graph) 0) ++ "};" --10 is not very magic, just count the chars in the output and leave a few to spare

        --":carray" static unsigned long long int C[3][1] = {{18446744073709551614LLU}, {18446744073709551614LLU}, {18446744073709551613LLU}};
        carray = "static uint_fast64_t C[" ++ show (length clist) ++ "][" ++ show (length $ head clist) ++ "] = " ++ replace "]" "}" (replace "[" "{" (addLLUs clist)) ++ ";"

        --":darray" static unsigned long long int D[3][1] = {{18446744073709551613LLU}, {18446744073709551613LLU}, {18446744073709551614LLU}};
        darray = "static uint_fast64_t D[" ++ show (length dlist) ++ "][" ++ show (length $ head dlist) ++ "] = " ++ replace "]" "}" (replace "[" "{" (addLLUs dlist)) ++ ";"

        --":xarray" unsigned int X[3] = {0, 0, 0};
        xarray = "uint_fast8_t X[" ++ show (length graph) ++ "] = {" ++ trim (show $ replicate (length graph) 0) ++ "};"

        --":aarray" unsigned long long int A[3][1] = {{18446744073709551615LLU}, {18446744073709551615LLU}, {18446744073709551615LLU}};
        aarray = "uint_fast64_t A[" ++ show (length graph) ++ "][" ++ show (length $ head aalist) ++ "] = " ++ replace "]" "}" (replace "[" "{" (addLLUs aalist)) ++ ";"

        --":fops_true" A[i][0] = A[i-1][0] & C[i][0];
        fops_true  = unlines $ map (\j -> "        A[i][" ++ show j ++ "] = A[i-1][" ++ show j ++ "] & C[i][" ++ show j ++ "];")  [0..(length $ init $ head aalist)]

        --":fops_false"  A[i][0] = A[i-1][0] & D[i][0];
        fops_false = unlines $ map (\j -> "        A[i][" ++ show j ++ "] = A[i-1][" ++ show j ++ "] & D[i][" ++ show j ++ "];")  [0..(length $ init $ head aalist)]

        --sprintf(str, "[               ,%5d]\n", this);
        printouter_sprint = "    sprintf(str, \"[" ++ replicate (length graph) ' '  ++ ",%5d]\\n\", this);"
        -- str[1] = X[0] ^ 48;
        printouter_xors = unlines ["    str[" ++ show i ++ "] = X[" ++ show (i-1) ++ "] ^ 48;" | i <- [1..(length graph)]]
        printouter = unlines ["void printout(){", printouter_sprint, printouter_xors, "}"]

        --":counter"    this += counter(A[maxpos][0]);
        counter = "    uint_fast64_t * thisbuf = A[maxpos];\n    this = counter(thisbuf);"
        --unlines $ map (\i -> concat ["    this += counter(A[maxpos][", show i, "]);"]) [0..(length $ tail $ head aalist)]

        --":sprinter"        sprintf(str, "[%d%d%d,%5d]\n", X[0], X[1], X[2],  this );
        sprinter = "        printout();"
        --"        sprintf(str, \"[" ++ (concat $ replicate' "%d" (length graph)) ++ ",%5d]\\n\", " ++ (concat (map (\x -> concat ["X[",show x,"],"]) [0..(-1 + length graph)])) ++ "this );"

        --":fout"    fout = fopen("test_0_0_out.txt", "w");
        fout = (\startplace ->"#define fopener fopen(\"" ++ filename ++ "_" ++ show startplace ++ "_" ++ show twotothesplitbits ++ "_out.txt\", \"w\")\n") :: Int -> String

        --":fputs"    fputs("[[0, 1], [1, 2], [0, 2]]\n", fout);
        fputs = "    fputs(\"" ++ show graph ++ "\\n\", fout);"

        introlist = ["#include <stdio.h>",
            "#include <stdint.h>",
            "FILE * fout;"]
            --"static unsigned long long int ONES = 18446744073709551615LLU;",
            --unsigned int starthere = 0;
            -- ":starthere",
        codelist =  ["uint_fast64_t y;",
            "uint_fast32_t best = 1;",
            "uint_fast32_t i;",
            "uint_fast32_t this;",
            --static int maxpos = 2;
            ":maxpos",
            --static unsigned int endhere = 0;
            ":endhere",
            --char str[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
            ":cstr",
            --"FILE * fout;",
            "",
            --static unsigned long long int C[3][1] = {{18446744073709551614LLU}, {18446744073709551614LLU}, {18446744073709551613LLU}};
            ":carray",
            "",
            --static unsigned long long int D[3][1] = {{18446744073709551613LLU}, {18446744073709551613LLU}, {18446744073709551614LLU}};
            ":darray",
            "",
            --unsigned int X[3] = {0, 0, 0};
            ":xarray",
            "",
            --unsigned long long int A[3][1] = {{18446744073709551615LLU}, {18446744073709551615LLU}, {18446744073709551615LLU}};
            ":aarray",
            "",
            "#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.",
            makeAsmCounter (length graph),
            "#elif UINTPTR_MAX == 0xffffffff // 32-bit",
            "int counter (unsigned long long i)",
            "{",
            "  unsigned int i1 = i, i2 = i >> 32;",
            "  i1 = i1 - ((i1 >> 1) & 0x55555555);",
            "  i2 = i2 - ((i2 >> 1) & 0x55555555);",
            "  i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);",
            "  i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);",
            "  i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;",
            "  i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;",
            "  return ((i1 + i2) * 0x1010101) >> 24;",
            "}",
            "",
            "#else",
            "#error \"this cpu doesn't seem to be 32-bit or 64-bit. I don't know how to deal with this.\"",
            "#endif",
--          Commented out below is the previous version of the 'f' function, which computes the next "which cycles remain" (A[i]), with
--              the original code and some intermediate steps on the way to the current version (marked by '//'). Note that a variable ('y')
--              and five operations have been removed. I did consider an inplicit branch, but found that most possible implementations would
--              have added a few more operations than the branch did on its own. Furthermore, a branch is ~3 cycles (?) and I've removed at
--              least that many.
--            void f(int i, int y0){
--                if(y0){
--                    //  y = ONES;
--                    //  A[i][0] = A[i-1][0] & (0    | C[i][0]) & (ONES | D[i][0]);
--                    //  A[i][0] = A[i-1][0] & (       C[i][0]) & (ONES          );
--                    //  A[i][0] = A[i-1][0] & (       C[i][0])                   ;
--                    A[i][0] = A[i-1][0] & C[i][0];
--                } else {
--                    // y = 0;
--                    // A[i][0] = A[i-1][0] & (ONES | C[i][0]) & (0    | D[i][0]);
--                    // A[i][0] = A[i-1][0] & (ONES          ) & (       D[i][0]);
--                    // A[i][0] = A[i-1][0]                    & (       D[i][0]);
--                    A[i][0] = A[i-1][0] & D[i][0];
--                }
--                // A[i][0] = A[i-1][0] & (~y | C[i][0]) & (y | D[i][0]);
--            }
           "void f(uint_fast8_t i, uint_fast8_t y0){",
            "    if(y0){",
            ":fops_true",
            "    } else {",
            ":fops_false",
            "    }",
            "}",
            "",
            ":printouter",
            "",
            "void checkifbest(){",
            --"    this = 0;",
            --    this += counter(A[maxpos][0]);
            ":counter",
            "",
            "    if(this == best){",
            --        sprintf(str, "[%d%d%d,%5d]\n", X[0], X[1], X[2],  this );
            ":sprinter",
            "        fwrite(str, 1, sizeof(str), fout);",
            "    }",
            "",
            "    if(this > best){",
            --        sprintf(str, "[%d%d%d,%5d]\n", X[0], X[1], X[2],  this );,
            ":sprinter",
            "        fwrite(str, 1, sizeof(str), fout);",
            "        best = this;",
            "    }",
            "",
            "}",
            "",
            "int r(){",
            "    goto startnocarry;",
            "    ",
            "    startnocarry:",
            "        if(i == maxpos){",
            "            if(X[i]){",
            "                X[i] = 0;",
            "                i--;",
            "                goto startcarry;",
            "            }else{",
            "                f(i, 0);",
            "                checkifbest();",
            "                X[i] = 1;",
            "                f(i, 1);",
            "                checkifbest();",
            "                X[i] = 0;",
            "                i--;",
            "                goto startcarry;",
            "            }",
            "        }else{",
            "            f(i, X[i]);",
            "            i++;",
            "            goto startnocarry;",
            "        }",
            "        ",
            "    startcarry:",
            "        if(X[i] && (i != endhere)){",
            "            X[i] = 0;",
            "            i--;",
            "            goto startcarry;",
            "        }else{",
            "            if(i == endhere){",
            "                goto end;",
            "            }else{",
            "                X[i] = 1;",
            "                f(i, 1);",
            "                i++;",
            "                goto startnocarry;",
            "            }",
            "        }",
            "",
            "    end:",
            "        return 0;",
            "}",
            "int main(){",
            -- fout = fopen("test_0_0_out.txt", "w");
            "fout = fopener;",
            --":fout",
            -- fputs("[[0, 1], [1, 2], [0, 2]]\n", fout);
            ":fputs",
            "    if(endhere){",
            "        uint_fast8_t bitpos = 0;",
            "        uint_fast8_t thisbit;",
            "        while(starthere){",
            "            thisbit = starthere & 1;",
            "            X[bitpos] = thisbit;",
            "            f(bitpos, thisbit);",
            "            bitpos++;",
            "            starthere >>= 1;",
            "        }",
            "        i = endhere;",
            "        r();",
            "    }else{",
            "        i = 0;",
            "        r();",
            "    }",
            "    fwrite(\"FINISHED.\", 1, 9, fout);",
            "    fclose(fout);",
            "    return 0;",
            "}",
            ""]

-- | This generates the inline assembly for the popcount of four 64-bit unsigned integers
makeAsmCounter4 :: Int -> String
makeAsmCounter4 j = unlines  ["    __asm__(",
                              "            \"popcnt %4, %4 \\n\\t\"",
                              "            \"add %4, %0    \\n\\t\"",
                              "            \"popcnt %5, %5 \\n\\t\"",
                              "            \"add %5, %1    \\n\\t\"",
                              "            \"popcnt %6, %6 \\n\\t\"",
                              "            \"add %6, %2    \\n\\t\"",
                              "            \"popcnt %7, %7 \\n\\t\"",
                              "            \"add %7, %3    \\n\\t\"",
                              "            : \"+r\" (cnt[" ++ j0 ++ "]), \"+r\" (cnt[" ++ j1 ++ "]), \"+r\" (cnt[" ++ j2 ++ "]), \"+r\" (cnt[" ++ j3 ++ "])",
                              "            : \"r\" (buf[" ++ j0 ++ "]), \"r\" (buf[" ++ j1 ++ "]), \"r\" (buf[" ++ j2 ++ "]), \"r\" (buf[" ++ j3 ++ "]));"]
  where
    j0 = show (j+0)
    j1 = show (j+1)
    j2 = show (j+2)
    j3 = show (j+3)

-- | This generates the inline assembly for the popcount of two 64-bit unsigned integers
makeAsmCounter2 :: Int -> String
makeAsmCounter2 j = unlines  ["    __asm__(",
                              "            \"popcnt %2, %2  \\n\\t\"",
                              "            \"add %2, %0     \\n\\t\"",
                              "            \"popcnt %3, %3  \\n\\t\"",
                              "            \"add %3, %1     \\n\\t\"",
                              "            : \"+r\" (cnt[" ++ j0 ++ "]), \"+r\" (cnt[" ++ j1 ++ "])",
                              "            : \"r\" (buf[" ++ j0 ++ "]), \"r\" (buf[" ++ j1 ++ "]));"]
  where
    j0 = show (j+0)
    j1 = show (j+1)

-- | This generates the inline assembly for the popcount of one 64-bit unsigned integer
makeAsmCounter1 :: Int -> String
makeAsmCounter1 j = unlines  ["    __asm__(",
                              "           \"popcnt %1, %1  \\n\\t\"",
                              "           \"add %1, %0     \\n\\t\"",
                              "            : \"+r\" (cnt[" ++ j0 ++ "])",
                              "            : \"r\" (buf[" ++ j0 ++ "]));"]
  where
    j0 = show (j+0)

-- | This generates the inline assembly for the popcount of arbitrarily many 64-bit unsigned integers
makeAsmCounterN :: Int -> String
makeAsmCounterN n = expand ([], 0, n)
    where
      expand (code, at, max)
          | (max - at) >= 4 = expand (code ++ makeAsmCounter4 at, at + 4, max)
          | (max - at) >= 2 = expand (code ++ makeAsmCounter2 at, at + 2, max)
          | (max - at) >= 1 = expand (code ++ makeAsmCounter1 at, at + 1, max)
          | otherwise      = code

-- | This generates the C code for a function utilizing inline assembly to find the total popcount of a length 'n' uint64_t buffer
makeAsmCounter n = unlines ["int counter (uint64_t * buf){",
                            "    uint64_t cnt[" ++ show n ++ "];",
                            unlines ["    cnt[" ++ show i ++ "] = 0;" | i <- [0..(n-1)]],
                            makeAsmCounterN n,
                            "",
                            concat $ "    return cnt[0]" : [" + cnt[" ++ show k ++ "]" | k <- [1..(n-1)]] ++ [";"],
                            "}"]

-- | This makes a CULLong into a more or less readable string for debugging
listFromULL :: CULLong -> String
listFromULL 0 = []
listFromULL x = listFromULL (div x 2) ++ show (x .&. 1)

-- | This makes a [[CULLong]] into a more or less readable string for debugging
printULLs :: [[CULLong]] -> String
printULLs = unlines . map (show . map listFromULL)

-- | This sorts a list of tuples by the snd element
sortBySnd :: Ord b => [(a,b)] -> [(a,b)]
sortBySnd = sortBy (compare `Data.Function.on` snd)
