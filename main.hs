import Control.Exception
import Control.Monad
import Data.Bits
import Data.List
import Data.List.Split
import Data.Maybe
import Data.String.Utils
import Foreign.C.Types
import System.Directory
import System.IO
import System.Process
import Text.Regex
--import Control.Exception.Assert

--For Debugging
import Data.Typeable
import System.IO.Unsafe

--For cleaning up files
--http://stackoverflow.com/questions/8502201/remove-file-if-it-exists
import Prelude hiding (catch)
import System.Directory
import System.IO.Error hiding (catch)

removeIfExists :: FilePath -> IO ()
removeIfExists fileName = removeFile fileName `catch` handleExists
  where handleExists e
         | isDoesNotExistError e = return ()
         | otherwise = throwIO e

removeDirIfExists :: FilePath -> IO ()
removeDirIfExists foldername = removeDirectoryRecursive foldername `catch` handleExists
  where handleExists e
         | isDoesNotExistError e = return ()
         | otherwise = throwIO e

---------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------
--      TODO:
--
--      Warning: no synopsis given. You should edit the .cabal file and add one.
--      You may want to edit the .cabal file and add a Description field.
--
--      profile!:
--              consider whether to optimize r() further
--              consider rolling my own 'sprinter' (should be a peice of cake, but maybe not worth it) DONE
--                  use "str[i] = X[i] ^ 48" (48 is '0', 49 is '1') DONE
--                  use "A ^ B" instead of "A /= B"
--                  instead of "this = 0;\n this += ...", use "this = a + b + c;" NO, because that would require an additional register?
--                  get rid of "if (this < best)" case DONE
--              NO-LONGER:use papi get_real_cycles() to interpolate the number of cpu-cycles for a e-edge, c-cycle graph
--                  use "#include <x86intrin.h>" and "unsigned long long c0 = __rdtsc();" unstead of papi.
--              write-up number of steps (something like ceiling(forms/64)*2^numedges) and find constant of ~how many cycles per asympt. step
--                profile and lightly optimize the haskell code -> current state: ghc breaks the printing of 2nd/2 code files and ghci works
--
--      (long)
--              write an interface to compile, run and feedback results into haskell
--                  implemented for findcy w/o justCount -> should be simple mod for w/
--              add support for QuickCheck
--              write an unfolder to unfold n loops of findcy's tree search
--              write an interface to opencl to run in one thread at a time or auto-split work among threads (manager and push 'medium' tasks to others)
--              write a more formal interface to the whole thing, incl. a general graph -> minimal nontrivial parts -> complete solution
--                still need solution files to graph
--
--      (mild)
--              remove 'ONES' if not needed
--              fix other functions to not use a state variable
--              make variables for repetitive operations (e.g. length - 1, show something, etc.)
--              "The -ddump-minimal-imports option to ghc writes the cleaned-up list to M.imports, where M is the module being compiled."
--              add option to only print new bests?
--
--      (fun)
--              consider porting to accelerate (with TemplateHaskell?) (partial version in '4gpu' folder)
--
--FIXED/DONE:
--      converting vertex cycles to edge cycles misses edges (probably from the a/prepending
--      converting a [1,0] list to a ULL doesn't pad properly. It outputs [1,1..stuff] instead of [stuff,1,1..1]
--      specifically important for this fix is the aalist essentailly treating all start values as 0. not good.
--      the bits seem to be inverted in the various bitlists
--      make sure that sorting the indexed cycles does not affect the results
--      fixed problem (quite persistent) caused by not initializing A[0] as anything other than all ones (bitwise)
--      fix length' to not use a state/sofar variable
--      write a function that outputs one of http://www.dalkescientific.com/writings/diary/archive/2011/11/02/faster_popcount_update.html according to option
--      write a 'trim output' C function (should be easy to make a general one) and add both that and the rem0s function to the end of the program:
--          -> going to just have Haskell do that instead
--      add count-only option to findcy
--      implement split-bits
--
---------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------

--Assuming variables are unlimited width for the purposes of explaining the logic: (1 is true, 0 is false) (i is the variable index, j is the digit index)
--	a[i][j] := is the ith edge in the jth cycle?
--	b[i][j] := is the ith edge backward in the jth cycle? (forward is [x,y] -> x<y )
--	c[i][j] := ~a[i][j] | ~b[i][j]
--	d[i][j] := ~a[i][j] |  b[i][j]
--	A[i][j] := (up to and inc. the ith var/edge) is it still possible that this digraph has the jth cycle?
--	A[0][j] := 1 if j < number of cycles
--	y[i][j] := is ith edge backward? (so 0 is forward, 1 is backward)
--	A[i][j] := A[i-1][j] & (~y[j] | c[i][j]) & (y[j] | d[i][j]

----First convert vertex cycles to (forward? Bool , edge index) tuple list

goodGraphList :: Integral a => [[a]] -> Bool
goodGraphList list = ((length (filter (\x -> x!!0 >= x!!1) list)) == 0) && ((minimum $ map minimum list) == 0)
--assert (goodGraphList [[0,2],[3,4],[5,6],[7,8],[10,100]]) ()

trimList :: Integral a => [a] -> [a]
trimList list = if (last list) == 0 then trimList (init list) else list
--byEq assert "Integral a => [a]" (trimList [1,2,3,0,0,1,0,0,0,0,0,0]) [1,2,4,0,0,1] ()

-- | 'wrapAround' appends the first element to the list
wrapAround :: [a] -> [a]
wrapAround [] = []
wrapAround (x:xs) = [x] ++ xs ++ [x]

-- | 'elemIndex'' is the same as 'elemIndex', except it allows for any Integral type as the index and has no Maybe
elemIndex' :: (Eq a, Integral b) => a -> [a] -> b -> b
elemIndex' _ [] _ = error "you tried to get the index of an element from an empty list"
elemIndex' x (y:ys) p = if x == y then p else elemIndex' x ys (p + 1)

--elist is edge list and vlist is cycle vertex list
convIndivCycle :: (Integral a, Bits a) => [[a]] -> [a] -> [(Bool, a)]
convIndivCycle elist vlist = loop elist tvlist []
                        where
                            loop :: Integral a => [[a]] -> [a] -> [(Bool, a)] -> [(Bool, a)]
                            loop _ [] output = output
                            loop elist' vlist' output = loop elist' (tail vlist') (if (length vlist') < 2
                                                                                    then output
                                                                                    else (vlist'!!0 < vlist'!!1, elemIndex' (sort (take 2 vlist')) elist' 0):output )
                            tvlist = wrapAround $ trimList vlist
--byEq assert "Integral a => [(Bool, a)]" (convIndivCycle [[0,1],[1,2],[0,2]] [0,1,2,0,0,0,0]) [(True,0),(True,1),(False,2)] ()


----Now, make variable lists

bool :: Integral a => Bool -> a
bool x = if x then 1 else 0
--assert ((bool True) == 1) ()

--aVarList is a[var][j], likewise for bVarList
aVarList :: (Integral a, Bits a, Integral b, Bits b) => [[(Bool, a)]] -> a -> [b]
aVarList cyclelists var = map (\x ->bool $ elem var x) (map (\y -> map (\x -> snd x) y) cyclelists)

bVarList :: (Integral a, Bits a) => [[(Bool, a)]] -> a -> [a]
bVarList cyclelists var = map gettf (map (\y -> (filter (\x -> (snd x) == var) y)) cyclelists)
                    where
                        gettf :: Integral a => [(Bool, a)] -> a
                        gettf list = if list == []
                                        then 0
                                        else bool $ fst $ head $ list

--Note: (1-x) == ~x for x <- [0,1]
cVarList :: (Integral a, Bits a) => [a] -> [a] -> [a]
cVarList avlist bvlist = zipWith (\a b -> (1-a) .|. (1-b) ) avlist bvlist

dVarList :: (Integral a, Bits a) => [a] -> [a] -> [a]
dVarList avlist bvlist = zipWith (\a b -> (1-a) .|.    b  ) avlist bvlist

----The next step is to make binary value builders

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

-- | 'listToULL' converts a length <= 64 list of 0,1 values into a single 'CULLong'
listToULL :: Integral a => [a] -> CULLong
listToULL list = if (length list) > 64
                    then error "You want to use listToULLs for this (You're using listToULL)."
                    else foldl' (.|.) 0 (zipWith (\x y -> if x == 0 then 0 else bit y) (padMod list 0 64) [0..])

-- | 'listToULLs' converts a list of length > 64 to a list of 'CULLong' values
listToULLs :: Integral a => [a] -> [CULLong]
listToULLs list = map listToULL (chunksOf 64 (padMod list 0 64))


----Now all we need to do before building is make the variable text generators
--
--I will be using a custom formatter: each line that needs more info filled in will be marked ":[name of thing to insert]"
--
--Here's a list of everything that needs to be generated:
{-    maxpos    static int maxpos = 2;
      endhere   static unsigned int endhere = 0;
      starthere unsigned int starthere = 0;
      cstr      char str[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
      carray    static unsigned long long int C[3][1] = {{18446744073709551614LLU}, {18446744073709551614LLU}, {18446744073709551613LLU}};
      darray    static unsigned long long int D[3][1] = {{18446744073709551613LLU}, {18446744073709551613LLU}, {18446744073709551614LLU}};
      xarray    unsigned int X[3] = {0, 0, 0};
      aarray    unsigned long long int A[3][1] = {{18446744073709551615LLU}, {18446744073709551615LLU}, {18446744073709551615LLU}};
      counter   this += counter(A[maxpos][0]);
      sprinter  sprintf(str, "[%d%d%d,%5d]\n", X[0], X[1], X[2],  this );
      fout      fout = fopen("test_0_0_out.txt", "w");
      fputs     fputs("[[0, 1], [1, 2], [0, 2]]\n", fout);
-}

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
removeExtraNewlines string | (length string) < 2 = string
removeExtraNewlines string
  | (length string) < 2  = string
  | (x == y) && (x == '\n') =     removeExtraNewlines (y:zs)
  | otherwise            = x : removeExtraNewlines (y:zs)
    where
      x  = head string
      y  = head $ tail string
      zs = tail $ tail string

addULLs :: String -> String
addULLs text = subRegex (mkRegex patc) (subRegex (mkRegex patb) text "\\1LLU}") "\\1LLU,"
            where
                patc = "([0-9]{3})(,)"
                patb = "([0-9]{3})(})"

-- | 'listFirstAnd' replaces a!!0 with b!!0 .&. c!!0
listFirstAnd :: [[CULLong]] -> [[CULLong]] -> [[CULLong]] -> [[CULLong]]
listFirstAnd [] _  _  = []
listFirstAnd a  [] _  = a
listFirstAnd a  _  [] = a
listFirstAnd a  b  c  = (zipWith (.&.) (head b) (head c)):(tail a)

--generateCode :: (Integral a, Bits a, Show a) => [[a]] -> [[a]] -> a -> a -> a -> a -> String
generateMaxCyCode :: [[Int]] -> [[Int]] -> Int -> Int -> Int -> (String, String)
generateMaxCyCode graph cycles start end splitbits = (removeExtraNewlines $ unlines $ map (\s -> formatByDict s dict) codelist, printout)

    where
        twotothesplitbits = 2^splitbits
        printout = unlines ["graph:" ++ (show graph),
                            "cycles:" ++ (show cycles),
                            "cyclelists:" ++ (show cyclelists),
                            "alist:" ++ (show alist),
                            "blist:"++(show blist),
                            "clist:",
                            printULLs clist,
                            "dlist:",
                            printULLs dlist,
                            "aalist:",
                            printULLs aalist ]

        cyclelists = map sortBySnd (map (\c -> convIndivCycle graph c) cycles)

        alist = map (\var -> aVarList cyclelists var) [0..(-1 + length' graph)]
        blist = map (\var -> bVarList cyclelists var) [0..(-1 + length' graph)]

        clist   = map listToULLs (map (\var -> cVarList (fst var) (snd var)) (zip alist blist))
        dlist   = map listToULLs (map (\var -> dVarList (fst var) (snd var)) (zip alist blist))
        aalist' = map listToULLs (map (\var -> map (\_ -> 1) var)                 alist       )
        aalist  = listFirstAnd aalist' aalist' dlist
--        aalist = map listToULLs (replicate (length alist) (replicate (length $ head alist) 1))

        dict = [
         (":maxpos",     maxpos),
         (":endhere",    endhere),
         (":starthere",  starthere),
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
         (":fout",       fout),
         (":fputs",      fputs)]

        --":maxpos" static int maxpos = 2;
        maxpos = "static uint_fast32_t maxpos = " ++ (show (-1 + length' graph)) ++ ";"

        --":endhere" static unsigned int endhere = 0;
        endhere = "static uint_fast32_t endhere = " ++ (show end) ++ ";" -- log2(maximum_value + 1)

        --":starthere" unsigned int starthere = 0;
        starthere = "uint_fast32_t starthere = " ++ (show $ 2 * start) ++ ";" --The '2*' is to bitshift past the fixed '0' at position '0'.

        --":cstr" char str[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        cstr = "char str[" ++ (show $ 10 + length graph) ++ "] = {" ++ (trim $ show $ replicate (10 + length graph) 0) ++ "};" --10 is not very magic, just count the chars in the output and leave a few to spare

        --":carray" static unsigned long long int C[3][1] = {{18446744073709551614LLU}, {18446744073709551614LLU}, {18446744073709551613LLU}};
        carray = addULLs ("static uint_fast64_t C[" ++ (show $ length clist) ++ "][" ++ (show $ length $ head clist) ++ "] = " ++ (replace "]" "}" (replace "[" "{" (show clist))) ++ ";")

        --":darray" static unsigned long long int D[3][1] = {{18446744073709551613LLU}, {18446744073709551613LLU}, {18446744073709551614LLU}};
        darray = addULLs ("static uint_fast64_t D[" ++ (show $ length dlist) ++ "][" ++ (show $ length $ head dlist) ++ "] = " ++ (replace "]" "}" (replace "[" "{" (show dlist))) ++ ";")

        --":xarray" unsigned int X[3] = {0, 0, 0};
        xarray = "uint_fast8_t X[" ++ (show $ length graph) ++ "] = {" ++ (trim $ show $ replicate (length graph) 0) ++ "};"

        --":aarray" unsigned long long int A[3][1] = {{18446744073709551615LLU}, {18446744073709551615LLU}, {18446744073709551615LLU}};
        aarray = addULLs ("uint_fast64_t A[" ++ (show $ length graph) ++ "][" ++ (show $ length $ head aalist) ++ "] = " ++ (replace "]" "}" (replace "[" "{" (show aalist))) ++ ";")

        --":fops_true" A[i][0] = A[i-1][0] & C[i][0];
        fops_true  = unlines $ map (\j -> "        A[i][" ++ (show j) ++ "] = A[i-1][" ++ show j ++ "] & C[i][" ++ show j ++ "];")  [0..(length' $ init $ head aalist)]

        --":fops_false"  A[i][0] = A[i-1][0] & D[i][0];
        fops_false = unlines $ map (\j -> "        A[i][" ++ (show j) ++ "] = A[i-1][" ++ show j ++ "] & D[i][" ++ show j ++ "];")  [0..(length' $ init $ head aalist)]

        --sprintf(str, "[               ,%5d]\n", this);
        printouter_sprint = "    sprintf(str, \"[" ++ (replicate (length graph) ' ')  ++ ",%5d]\\n\", this);"
        -- str[1] = X[0] ^ 48;
        printouter_xors = unlines ["    str[" ++ (show i) ++ "] = X[" ++ (show (i-1)) ++ "] ^ 48;" | i <- [1..(length graph)]]
        printouter = unlines ["void printout(){", printouter_sprint, printouter_xors, "}"]

        --":counter"    this += counter(A[maxpos][0]);
        counter = "    uint_fast64_t * thisbuf = A[maxpos];\n    this = counter(thisbuf);"
        --unlines $ map (\i -> concat ["    this += counter(A[maxpos][", show i, "]);"]) [0..(length $ tail $ head aalist)]

        --":sprinter"        sprintf(str, "[%d%d%d,%5d]\n", X[0], X[1], X[2],  this );
        sprinter = "        printout();"
        --"        sprintf(str, \"[" ++ (concat $ replicate' "%d" (length graph)) ++ ",%5d]\\n\", " ++ (concat (map (\x -> concat ["X[",show x,"],"]) [0..(-1 + length graph)])) ++ "this );"

        --":fout"    fout = fopen("test_0_0_out.txt", "w");
        fout = "    fout = fopen(\"runner_" ++ (show start) ++ "_" ++ (show twotothesplitbits) ++ "_out.txt\", \"w\");"

        --":fputs"    fputs("[[0, 1], [1, 2], [0, 2]]\n", fout);
        fputs = "    fputs(\"" ++ (show graph) ++ "\\n\", fout);"

        codelist = ["#include <stdio.h>",
            "#include <stdint.h>",
            --"static unsigned long long int ONES = 18446744073709551615LLU;",
            "uint_fast64_t y;",
            "uint_fast32_t best = 1;",
            "uint_fast32_t i;",
            "uint_fast32_t this;",
            --static int maxpos = 2;
            ":maxpos",
            --static unsigned int endhere = 0;
            ":endhere",
            --unsigned int starthere = 0;
            ":starthere",
            --char str[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
            ":cstr",
            "FILE * fout;",
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
            --"int main(int argc, const char * argv[]) {",
            "int main(){",
            --    fout = fopen("test_0_0_out.txt", "w");
            ":fout",
            --    fputs("[[0, 1], [1, 2], [0, 2]]\n", fout);
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

{-
testgraph :: [[Int]]
testgraph = [[0,1],[1,2],[0,2]]

testcycles :: [[Int]]
testcycles = [[0,1,2,0,0],[1,0,2,0,0,0]]
-}

-- k4g :: [[Int]]
-- k4g = [[0,1],[0,2],[0,3],[1,2],[1,3],[2,3]]

-- k4c :: [[Int]]
-- k4c = [[0,1,2,0],[0,1,2,3],[0,1,3,0],[0,1,3,2],[0,2,1,0],[0,2,1,3],[0,2,3,0],[0,2,3,1],[0,3,1,0],[0,3,1,2],[0,3,2,0],[0,3,2,1],[1,2,3,0],[1,3,2,0]]

-- main :: IO ()
-- main = if goodGraphList k4g
        -- then do
            -- writeFile "test.c" (fst (generateMaxCyCode k4g k4c 0 1 0))
            -- putStrLn (snd (generateMaxCyCode k4g k4c 0 1 0))
        -- else putStrLn "not a good graph"



------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------
--Following is the generator for a one-time use C program to find all cycles in a graph.
--
--      The general program will work with directed and undirected graphs and will find all *directed* cycles in the graph
--      I plan to modify the original program to work with graphs and digraphs and each modification to optinally only count cycles instead of listing them
--      This cannot be solved in O(V+E) time because even planar graphs can have O(2^v) cycles and listing/counting a graph cycle takes at least 1 CPU cycle
--
--      The algorithm performs a depth first search from an arbitrary vertex, marking seen vertices on the way, and only outputting cycles through
--              \ the initial vertex. As all cycles through that vertex have been found by the end, it is removed and the process repeated.
--              \ This way, there is no need to check if a cycle has been found yet and there are no sources of repetition.
--
--      The only weaknesses of this algorithm that I know are:
--              1) It requires full out-adjacency lists for each vertex (best fit for directed, sparse graphs)
--              2) For undirected graphs, if the cycles are considered to be undirected, it outputs one "forward" and one "backward" copy of each cycle
--                      N.B. For the purposes of inputting the cycles into the Max-Cycles part of the code, this is a strength as the algorithm needs both
--              3) Although the output file is formatted, it is annoying to integrate generating, compiling, running, and parsing into a single function
--              4) The generated code is in C. Yeah, I said it. On the plus side, unless you're running this on very big graphs
--                      \ (where it would take an obscene amount of time to finish), you shouldn't run into overflow issues.
--
--      The biggest plus? This algorithm is stupid-fast. Last test I ran outputted ~1.5GB of cycles from ~2k strongly-connected graphs, |E|<=36  in under 30s.
--              I can't wait to see how far I can push the count-only version heheheh..
--
------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------

-- graph (edgelist), cfilename, are assumed variables

-- 's' is the string, 'l' is how long to make the final one
padStrLeft0s :: (Integral a) => String -> a -> String
padStrLeft0s s t = if (length' s) >= t then s else padStrLeft0s ('0':s) t

-- Number of decimal digits in n
digLen10 :: (Num a, Integral a, Eq a) => a -> a
digLen10 0 = 0
digLen10 n = 1 + digLen10 (div n 10)

-- Get first element of l that's not equal to a (assuming no repetitons)
otherElem :: Eq a => a -> [a] -> a
otherElem a l = if (head l) == a then head $ tail l else head l

unlines' :: [[Char]] -> [Char]
unlines' s = foldr (\a b -> a ++ "\n" ++ b) "" s

trim :: [a] -> [a]
trim list = init $ tail list

hStringToCList :: String -> String
hStringToCList string = "[" ++ (trim string) ++ "]"

generateFindCyCode :: [[Int]] -> [Char] -> Bool-> [Char]
generateFindCyCode graph cfilename justCount = unlines $ map (\s -> formatByDict s dict) codelist
    where
        glen = length graph
        gmax = length $ tail graph
        maxd = digLen10 glen
        outfilename = (init cfilename) ++ "txt"

        dict = [(":print_cycle",   print_cycle),
                (":init_lookup",   init_lookup),
                (":init_str",      init_str),
                (":init_strs",     init_strs),
                (":fwrite_str",    fwrite_str),
                -- (":adj_lists",    adj_lists),
                -- (":cadj_lists",   cadj_lists),
                (":voss",          voss),
                (":init_vos",      init_vos),
                (":init_vomax",    init_vomax),
                (":init_paths",    init_paths),
                (":init_fresh",    init_fresh),
                (":init_file",     init_file),
                (":fwrite_graph",  fwrite_graph),
                (":assign_fresh",  assign_fresh),
                (":assign_cpath",  assign_cpath),
                (":assign_apath",  assign_apath),
                (":put_cycle",     put_cycle),
                (":fwrite_finish", fwrite_finish)]

        --"void print_cycle(outfileFILE * outfile, unsigned int * this_current_path){",
        print_cycle = if not justCount then "void print_cycle(FILE * outfile, unsigned int * this_current_path){" else "void print_cycle(unsigned int * this_current_path){"

        -- :init_lookup   char lookup[4][1] = {"0","1","2","3"};
        init_lookup_list = "    char lookup[" ++ (show glen) ++ "][" ++ (show maxd) ++ "] = {" ++ (tail $ init $ show vallist) ++ "};"
                where
                    vallist = map (\n -> padStrLeft0s (show n) maxd) [0..(gmax)]

        -- :init_str      char str[13] = "[_,_,_,_]\n"; -- Note that there could be multiple '_'s
        init_str_list = "    char str[" ++ show (3 + glen * maxd + glen - 1) ++ "] = \"[" ++ (init $ concat $ replicate (length graph) ((concat (replicate (digLen10 $ length graph) "_")) ++ ",")) ++ "]\\n\";"

        {- :init_strs
            str[1] = lookup[this_current_path[0]][0];
            str[3] = lookup[this_current_path[1]][0];
            str[5] = lookup[this_current_path[2]][0];
            str[7] = lookup[this_current_path[3]][0];
        -}
        -- POSSIBLE ERRORS IN FOLLOWING LINE:
        init_strs_list = unlines $ map (\pathpos -> unlines $ map (\digpos -> "    str[" ++ show (pathpos * (maxd+1) + digpos + 1) ++ "] = lookup[this_current_path[" ++ (show pathpos) ++ "]][" ++ (show digpos) ++ "];") [0..(maxd-1)]) [0..(glen-1)]
        -- numparts = \j -> "    str[" ++ (show (j * (maxd + 1) + i
        -- pathparts = \i -> unlines $ map numparts [0..(maxd-1)]
        -- init_strs_list = unlines $ map pathparts [0..(glen-1)]
        -- :fwrite_str    fwrite(str, 1, 13, outfile);
        fwrite_str_list = "    fwrite(str, 1, " ++ show (3 + (length graph) * (digLen10 $ length graph) + (length graph) - 1) ++ ", outfile);"

        init_lookup = if not justCount then init_lookup_list else ""
        init_str    = if not justCount then init_str_list else ""
        init_strs   = if not justCount then init_strs_list else ""
        fwrite_str  = if not justCount then fwrite_str_list else "    count++;"
        init_file   = if not justCount then init_file_write else ""
        fwrite_graph= if not justCount then fwrite_graph_write else ""
        {- :init_vos
                          const unsigned int vo0[3] = {1, 2, 3};
                          const unsigned int vo1[1] = {2};
                          const unsigned int vo2[1] = {3};
                          const unsigned int vo3[1] = {1};
                          const unsigned int * vos[4] = {vo0,vo1,vo2,vo3};
        -}

        adj_lists = map (\v ->sort $ map (otherElem v) (filter (\e -> elem v e) graph)) [0..(glen - 1)]
        cadj_lists = unlines' $ zipWith (\l i -> "    const unsigned int vo" ++ (show i) ++ "[" ++ (show $ length l) ++ "] = {" ++ (trim $ show l) ++ "};") adj_lists [0..]
        voss = "    const unsigned int * vos[" ++ (show glen) ++ "] = {" ++ (tail $ concat $ zipWith (++) [",vo" | x <- [0..]] (map show [0..(gmax)])) ++ "};"
--        (init $ tail $ tail $ zipWith (++) [",vo" | x <- [0..]] (map show [0..gmax])) ++ "};"
        init_vos = (cadj_lists ++ voss)

        -- :init_vomax    const unsigned int vomax[4] = {3, 1, 1, 1};
        init_vomax = "    const unsigned int vomax[" ++ (show glen) ++ "] = {" ++ (trim $ show $ map length adj_lists) ++ "};"

        -- :init_paths    unsigned int current_path[4];
        --                unsigned int adjacency_path[4];
        init_paths = "    unsigned int current_path[" ++ (show glen) ++ "];\n    unsigned int adjacency_path[" ++ show glen ++ "];"

        -- :init_fresh    unsigned char fresh[4] = {1,1,1,1};
        --                unsigned char inplay[4] = {1,1,1,1};
        init_fresh = "    unsigned char fresh[" ++ (show glen) ++ "] = {" ++ (trim $ show $ replicate glen 1) ++ "};\n    unsigned char inplay[" ++ (show glen) ++ "] = {" ++ (trim $ show $ replicate glen 1) ++ "};"

        -- :init_file     FILE * outfile = fopen("checking.txt", "w");
        init_file_write = "    FILE * outfile = fopen(\"" ++ outfilename ++ "\", \"w\");"

        -- :fwrite_graph  fwrite("[[0,1],[0,2],[0,3],[1,2],[3,1],[2,3]]\n",1,39,outfile);
        fwrite_graph_write = "    fwrite(\"" ++ (show graph) ++ "\\n\", 1," ++ (show $ (length' $ '0':(show graph))) ++ ",outfile);"

        -- :assign_fresh  fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3];
        assign_fresh = "    " ++ (concat $ map (\i -> "fresh[" ++ show i ++ "] = inplay[" ++ show i ++ "]; ") [0..(glen - 1)])

        -- :assign_cpath  current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0;
        assign_cpath = "    current_path[0] = start; " ++ (concat $ map (\i -> "current_path[" ++ show i ++ "] = 0; ") [1..(glen-1)])

        -- :assign_apath  adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0;,
        assign_apath = "    " ++ (concat $ map (\i -> "adjacency_path[" ++ show i ++ "] = 0; ") [0..(glen-1)])

        --"                                    print_cycle(outfile, current_path);",
        put_cycle = if not justCount then "                                    print_cycle(outfile, current_path);" else "                                    print_cycle(current_path);"

        -- :fwrite_finish            fwrite(\"DONE.\", 1, 5, outfile);
        fwrite_finish = if not justCount
                           then "            fwrite(\"DONE.\", 1, 5, outfile);\n            fclose(outfile);"
                           else "            printf(\"%llu\\n\", count);\n"--            fwrite(str, 1, 21, outfile);\n            fwrite(\"DONE.\", 1, 5, outfile);"
        codelist = ["#include <stdio.h>",
                    "unsigned long long count = 0;",
                    "",
                    --"void print_cycle(outfileFILE * outfile, unsigned int * this_current_path){",
                    ":print_cycle",
                    ":init_lookup",
                    ":init_str",
                    ":init_strs",
                    ":fwrite_str",
                    -- :init_lookup   char lookup[4][1] = {"0","1","2","3"};
                    -- :init_str      char str[13] = "[_,_,_,_]\n";
                    {- :init_strs
                        str[1] = lookup[this_current_path[0]][0];
                        str[3] = lookup[this_current_path[1]][0];
                        str[5] = lookup[this_current_path[2]][0];
                        str[7] = lookup[this_current_path[3]][0];
                    -}
                    -- :fwrite_str    fwrite(str, 1, 13, outfile);

                    "}",
                    "",
                    "int main(int argc, const char * argv[]) {",
                    ":init_vos",
                    ":init_vomax",
                    {- :init_vos
                                      const unsigned int vo0[3] = {1, 2, 3};
                                      const unsigned int vo1[1] = {2};
                                      const unsigned int vo2[1] = {3};
                                      const unsigned int vo3[1] = {1};
                                      const unsigned int * vos[4] = {vo0,vo1,vo2,vo3};
                    -}
                    -- :init_vomax    const unsigned int vomax[4] = {3, 1, 1, 1};

                    ":init_paths",
                    -- :init_paths    unsigned int current_path[4];
                    --                unsigned int adjacency_path[4];

                    "    register unsigned int path_position = 0;",
                    ":init_fresh",
                    -- :init_fresh    unsigned char fresh[4] = {1,1,1,1};
                    --                unsigned char inplay[4] = {1,1,1,1};

                    "    register unsigned int start = 0;",
                    "    register unsigned int fresh_found;",
                    "    register unsigned int fresh_found_adjacency;",
                    "",
                    "    register unsigned int possible_fresh;",
                    "    register unsigned int possible_fresh_adjacency;",
                    "    register unsigned int local_max;",
                    ":init_file",
                    -- :init_file     FILE * outfile = fopen("checking.txt", "w");
                    ":fwrite_graph",
                    -- :fwrite_graph  fwrite("[[0,1],[0,2],[0,3],[1,2],[3,1],[2,3]]\n",1,39,outfile);

                    "",
                    "    starter_loop:",
                    "    if (start != 2 ) {",
                    "        inplay[start] = 0;",
                    ":assign_fresh",
                    ":assign_cpath",
                    ":assign_apath",
                    -- :assign_fresh  fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3];
                    -- :assign_cpath  current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0;
                    -- :assign_apath  adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0;,

                    "",
                    "        fresh_found = 0;",
                    "        fresh_found_adjacency = 0;",
                    "        path_position = 0;",
                    "        begin_stepper:{",
                    "                local_max = vomax[current_path[path_position]];",
                    "                possible_fresh_adjacency = adjacency_path[path_position];",
                    "                begin_find_fresh:{",
                    "                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];",
                    "                    if (possible_fresh_adjacency != local_max) {",
                    "                        if (possible_fresh == start) {",
                    "                                if (path_position > 1) {",
                    --"                                    print_cycle(outfile, current_path);",
                    ":put_cycle",
                    "                                } else {",
                    "                                        ;",
                    "                                }",
                    "                                possible_fresh_adjacency++;",
                    "                                goto begin_find_fresh;",
                    "                        } else {",
                    "                            if (fresh[possible_fresh] && (possible_fresh_adjacency >= adjacency_path[path_position])) {",
                    "                                fresh_found = possible_fresh;",
                    "                                fresh_found_adjacency = possible_fresh_adjacency;",
                    "                                possible_fresh_adjacency++;",
                    "                                goto begin_check_for_cycle;",
                    "                            }",
                    "                        }",
                    "                        possible_fresh_adjacency++;",
                    "                        goto begin_find_fresh;",
                    "                    } else {",
                    "                        goto end_find_fresh;",
                    "                    }",
                    "                }end_find_fresh: goto step_back;",
                    "            begin_check_for_cycle:{",
                    "                if (possible_fresh_adjacency != local_max) {",
                    "                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];",
                    "                    if (possible_fresh == start) {",
                    "                            if (path_position > 1) {",
                    --"                                    print_cycle(outfile, current_path);",
                    ":put_cycle",
                    "                            } else {",
                    "                                    ;",
                    "                            }",
                    "                            goto end_check_for_cycle;",
                    "                    }",
                    "                    possible_fresh_adjacency++;",
                    "                    goto begin_check_for_cycle;",
                    "                } else {",
                    "                    goto end_check_for_cycle;",
                    "                }",
                    "            }end_check_for_cycle: goto step_forward;",
                    "            step_forward:",
                    "                adjacency_path[path_position] = fresh_found_adjacency;",
                    "                path_position++;",
                    "                current_path[path_position] = fresh_found;",
                    "                fresh[fresh_found] = 0;",
                    "                goto begin_stepper;",
                    "            step_back:",
                    "                if (path_position == 0) {",
                    "                    goto end_stepper;",
                    "                } else {",
                    "                    fresh[current_path[path_position]] = 1;",
                    "                    current_path[path_position] = 0;",
                    "                    adjacency_path[path_position] = 0;",
                    "                    path_position--;",
                    "                    adjacency_path[path_position]++;",
                    "                    goto begin_stepper;",
                    "                }",
                    "        }end_stepper:;",
                    "    ",
                    "        start++;",
                    "        goto starter_loop;",
                    "    } else {",
                    "",
                    ":fwrite_finish",
                    --"            fwrite(\"DONE.\", 1, 5, outfile);",
                    "            return 0;",
                    "    }",
                    "    return 0;",
                    "}",
                    ""]


------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------
-- The following is wrapping together the two code-generators so that:
--    compilation may be automatic (at least for findcy)
--    can automatically pipe graph -> findcy -> cycles -> maxcy -> (compile/run) -> collect results
--
------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------

ifElseError :: Bool -> t -> t
ifElseError bool thn = if bool then thn else error "Output file unfinished or unmatched to graph."

graphToNumCycles :: [[Int]] -> IO Int
graphToNumCycles graphlist = do
  removeIfExists "countcy_temp.c"
  removeIfExists "countcy_temp"
  let tempfilename = "countcy_temp.c"
  let code = generateFindCyCode graphlist tempfilename True
  cfile <- openFile "countcy_temp.c" WriteMode
  write <- hPutStr cfile code
  hClose cfile
  comp_results <- readProcess "gcc" ["countcy_temp.c", "-O3", "-o", "countcy_temp"] []
  when ((length comp_results) > 1) (putStrLn comp_results)
  run_results <- readProcess "./countcy_temp" [] []
  let numcy = read run_results :: Int
  when ((length run_results) > 12) (putStrLn ("results:" ++ run_results)) -- magic number 6 is one less than the shortest c error I found after little checking
  return numcy

processCycles :: [Char] -> [[Int]] -> [[Int]]
processCycles cycles_string graph = ifElseError good ((\s ->(map read_cy $ trim $ lines s)) cycles_string)

    --liftM3 if good
    --                                then liftM (\s ->(map read_cy $ trim $ lines s)) cycles_string
    --                                else error "Output file is either unfinished or unmatched to the current graph."
  where
    good             = (&&) finished good_graph
    finished         = (\s ->eq_done $ last $ lines s) cycles_string
    eq_done s        = "DONE." == s
    good_graph       = (\s ->eq_graph graph $ head $ lines s) cycles_string
    eq_graph graph s = (show graph) == s
    read_cy cy       = trimList $ read cy

graphToCycles :: [[Int]] -> IO [[Int]]
graphToCycles graphlist = do
  removeIfExists "findcy_temp.c"
  removeIfExists "findcy_temp"
  removeIfExists "findcy_temp.txt"
  let tempfilename = "findcy_temp.c"
  let code = generateFindCyCode graphlist tempfilename False
  cfile <- openFile "findcy_temp.c" WriteMode
  write <- hPutStr cfile code
  hClose cfile
  comp_results <- readProcess "gcc" ["findcy_temp.c", "-O3", "-o", "findcy_temp"] []
  putStrLn comp_results
  run_results <- readProcess "./findcy_temp" [] []
  putStrLn run_results
  cycles_str <- catch (readFile "findcy_temp.txt") handler
  let cycles = processCycles cycles_str graphlist
  return cycles
    where
      handler :: SomeException -> IO String
      handler _ = error "The results have disappeared under my nose."

--myMapM_ :: (t -> t1) -> [t] -> ()
-- myMapM_ f []     = ()
-- myMapM_ f (x:xs) = do
--   evaluate $ f x
--   liftM2 myMapM_ f xs

--graphToMaxcyCode :: [[Int]] -> Int -> [Char] -> [Char] -- IO ()
graphToMaxcyCode graphlist splitbits name = do
  -- putStrLn "1"
  let cycles = graphToCycles graphlist
  -- putStrLn "2"
  let endhere = splitbits
-- ???????????????????????
  -- putStrLn "3"
  let startmap = \start ->liftM (\cy -> (show start, fst $ generateMaxCyCode graphlist cy start endhere splitbits)) cycles
  let codelist = map startmap  [0..(2^splitbits)-1] :: [IO (String, String)]
  removeDirIfExists name
  mkdir_results <- readProcess "mkdir" [name] []
  -- putStrLn "4"
  --writeC (head codelist)
  mapM_ writeC codelist
  return "Done."
    where
      -- writeC :: IO (String, String) ->IO (IO ())
      writeC input = do
        start <- input >>= return . fst :: IO [Char]
        code <- input >>= return . snd :: IO [Char]
        -- startline <- return $ (\st ->"start:" ++ st) start
        -- putStrLn startline
        let maxfilenum = (2^splitbits)
        -- putStrLn "5"
        let outfilenamefun = \s ->name ++ "/runner_" ++ s ++ "_" ++ (show (maxfilenum - 1)) ++ ".c"
        -- putStrLn "6"
        let outfilename = outfilenamefun start
        -- outfilenameline <- return $ (\ofn ->"7\n" ++ ofn) outfilename
        -- putStrLn outfilenameline
        outfile <- (\filename ->openFile filename WriteMode) outfilename
        -- putStrLn "8"
        hPutStr outfile code
        -- putStrLn "9"
        hClose outfile
        return start
-- generateMaxCyCode graph cycles start end splitbits

k4g :: [[Int]]
k4g = [[0,1],[0,2],[0,3],[1,2],[1,3],[2,3]]

k4c :: [[Int]]
k4c = [[0,1,2,0],[0,1,2,3],[0,1,3,0],[0,1,3,2],[0,2,1,0],[0,2,1,3],[0,2,3,0],[0,2,3,1],[0,3,1,0],[0,3,1,2],[0,3,2,0],[0,3,2,1],[1,2,3,0],[1,3,2,0]]

main :: IO ()
main = do
--  a <- putStrLn $ liftM show $ typeOf processCycles
--  let out_string = show $ unsafePerformIO $ graphToCycles $ completeGraph 4
--  putStr $ out_string
  let str = graphToMaxcyCode (completeGraph 6) 1 "ttest"
  putStrLn $ unsafePerformIO str
  putStrLn "\nDone."

------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------
--The following is for debugging purposes.
--
--
------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------

listFromULL :: CULLong -> String
listFromULL 0 = []
listFromULL x = (listFromULL $ div x 2) ++ (show (x .&. 1))

printULLs :: [[CULLong]] -> String
printULLs l = unlines $  map (\x -> show $ map listFromULL x) l

sortBySnd :: Ord b => [(a,b)] -> [(a,b)]
sortBySnd list = sortBy (\a b -> compare (snd a) (snd b)) list

completeGraph :: Integral a => a -> [[a]]
completeGraph n = [[a,b] | a <- [0..n-1], b <- [0..n-1], a<b]

-- processCycles :: [Char] -> [[Int]] -> [[Int]]
-- processCycles cycles_str graph = if (done /= "DONE.") || (graph /= (show graph))
                                    -- then error "Output file is either unfinished or unmatched to the current graph."
                                    -- else map (\l ->trimList $ read l :: [Int]) cycles
  -- where
  --   cycles = trim $ lines cycles_str
    -- graph  = head $ lines cycles_str
    -- done   = last $ lines cycles_str

makeAsmCounter4 :: Int -> [Char]
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

makeAsmCounter2 :: Int -> [Char]
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

makeAsmCounter1 :: Int -> [Char]
makeAsmCounter1 j = unlines  ["    __asm__(",
                              "           \"popcnt %1, %1  \\n\\t\"",
                              "           \"add %1, %0     \\n\\t\"",
                              "            : \"+r\" (cnt[" ++ j0 ++ "])",
                              "            : \"r\" (buf[" ++ j0 ++ "]));"]
  where
    j0 = show (j+0)

makeAsmCounterN :: Int -> [Char]
makeAsmCounterN n = expand ([], 0, n)
    where
      expand (code, at, max)
          | (max - at) >= 4 = expand (code ++ (makeAsmCounter4 at), at + 4, max)
          | (max - at) >= 2 = expand (code ++ (makeAsmCounter2 at), at + 2, max)
          | (max - at) >= 1 = expand (code ++ (makeAsmCounter1 at), at + 1, max)
          | otherwise      = code

makeAsmCounter n = unlines ["int counter (uint64_t * buf){",
                            "    uint64_t cnt[" ++ (show n) ++ "];",
                            unlines ["    cnt[" ++ (show i) ++ "] = 0;" | i <- [0..(n-1)]],
                            makeAsmCounterN n,
                            "",
                            foldl (++) "" $ "    return cnt[0]" : [" + cnt[" ++ (show k) ++ "]" | k <- [1..(n-1)]] ++ [";"],
                            "}"]

-- int counter2 (uint64_t* buf){
--     uint64_t cnt[buflen];
--     for (int i = 0; i < (buflen); i++) {
--         cnt[i] = 0;
--     }
--     __asm__(
--             "popcnt %4, %4  \n\t"
--             "add %4, %0     \n\t"
--             "popcnt %5, %5  \n\t"
--             "add %5, %1     \n\t"
--             "popcnt %6, %6  \n\t"
--             "add %6, %2     \n\t"
--             "popcnt %7, %7  \n\t"
--             "add %7, %3     \n\t" // +r means input/output, r means intput
--             : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
--             : "r"  (buf[0]), "r"  (buf[1]), "r"  (buf[2]), "r"  (buf[3]));
--     __asm__(
--             "popcnt %2, %2  \n\t"
--             "add %2, %0     \n\t"
--             "popcnt %3, %3  \n\t"
--             "add %3, %1     \n\t"
--             : "+r" (cnt[4]), "+r" (cnt[5])
--             : "r"  (buf[4]), "r"  (buf[5]));
--     __asm__(
--             "popcnt %1, %1  \n\t"
--             "add %1, %0     \n\t"
--             : "+r" (cnt[6])
--             : "r"  (buf[6]));

--     return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6];
-- }
