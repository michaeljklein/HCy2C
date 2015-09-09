module Cycles.IO where

import Cycles.Aux
import Cycles.Findcy
import Cycles.Maxcy

import Control.Exception ( SomeException, throwIO, catch )
import Control.Monad ( liftM, Monad((>>=), return), when, mapM_, mapM, filterM )
import System.Directory ( removeFile, removeDirectoryRecursive, getDirectoryContents )
import System.IO
    ( IO,
      FilePath,
      IOMode(WriteMode),
      IOMode(ReadMode),
      readFile,
      putStrLn,
      hPutStr,
      openFile,
      hClose )
import System.IO.Error ( isDoesNotExistError )
import System.Process ( readProcess )

-- | This function allows one to remove a file with included exception handling
removeIfExists :: FilePath -> IO ()
removeIfExists fileName = removeFile fileName `catch` handleExists
  where handleExists e
         | isDoesNotExistError e = return ()
         | otherwise = throwIO e

-- | Like 'removeIfExists', this function allows one to remove a file with included exception handling
removeDirIfExists :: FilePath -> IO ()
removeDirIfExists foldername = removeDirectoryRecursive foldername `catch` handleExists
  where handleExists e
         | isDoesNotExistError e = return ()
         | otherwise = throwIO e

-- | This function only prints a line when its length is > 2.
-- It's useful, because without it, many of these function print blank lines when there are no compile/run errors.
putStrLongLn :: [Char] -> IO ()
putStrLongLn string = when ((length string) > 2) (putStrLn string)

------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------
-- The following is wrapping together the two code-generators so that:
--    compilation may be automatic (at least for findcy)
--    can automatically pipe graph -> findcy -> cycles -> maxcy -> (compile/run) -> collect results
------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------

-- | This allows one to easily use monadic values for if-then
ifElseError :: Bool -> t -> t
ifElseError bool thn = if bool then thn else error "Output file unfinished or unmatched to graph."

-- | This function takes a graph and whether it is a digraph and returns the number of directed cycles in it
graphToNumCycles :: [[Int]] -> Bool -> IO Int
graphToNumCycles graphlist directed = do
  removeIfExists "countcy_temp.c"
  removeIfExists "countcy_temp"
  let tempfilename = "countcy_temp.c"
  let code = generateFindCyCode graphlist tempfilename True directed
  cfile <- openFile "countcy_temp.c" WriteMode
  write <- hPutStr cfile code
  hClose cfile
  comp_results <- readProcess "gcc" ["countcy_temp.c", "-O3", "-o", "countcy_temp"] []
--  when ((length comp_results) > 1) (putStrLongLn comp_results)
  putStrLongLn comp_results
  run_results <- readProcess "./countcy_temp" [] []
  let numcy = read run_results :: Int
--  when ((length run_results) > 12) (putStrLn ("results:" ++ run_results)) -- magic number 12 is one less than the shortest c error I found after little checking
  putStrLongLn ("results: " ++ run_results)
  return numcy

-- | This function takes an output from the FindCy C code, performs a basic check ('is there a "done" mark?'), 
-- makes sure the output agrees with the expected graph, and reads the cycles into an [Int]
processCycles :: [Char] -> [[Int]] -> [[Int]]
processCycles cycles_string graph = ifElseError good ((\s ->(map read_cy $ trim $ lines s)) cycles_string)
  where
    good             = (&&) finished good_graph
    finished         = (\s ->eq_done $ last $ lines s) cycles_string
    eq_done s        = "DONE." == s
    good_graph       = (\s ->eq_graph graph $ head $ lines s) cycles_string
    eq_graph graph s = (show graph) == s
    read_cy cy       = trimList $ read cy

-- | This function takes a graph and whether it is a digraph and returns a list of all directed cycles (somewhat slow, because it uses Haskell's read function)
graphToCycles :: [[Int]] -> Bool -> IO [[Int]]
graphToCycles graphlist directed = do
  removeIfExists "findcy_temp.c"
  removeIfExists "findcy_temp"
  removeIfExists "findcy_temp.txt"
  let tempfilename = "findcy_temp.c"
  let code = generateFindCyCode graphlist tempfilename False directed
  cfile <- openFile "findcy_temp.c" WriteMode
  write <- hPutStr cfile code
  hClose cfile
  comp_results <- readProcess "gcc" ["findcy_temp.c", "-O3", "-o", "findcy_temp"] []
  putStrLongLn comp_results
  run_results <- readProcess "./findcy_temp" [] []
  putStrLongLn run_results
  cycles_str <- catch (readFile "findcy_temp.txt") handler
  let cycles = processCycles cycles_str graphlist
  return cycles
    where
      handler :: SomeException -> IO String
      handler _ = error "The results have disappeared under my nose."

-- | This function takes a graph and automatically finds all cycles to output a string containing the C code to compute its maximally cyclic orientations
graphToMaxcyCode :: [[Int]] -> Int -> [Char] -> IO [Char]
graphToMaxcyCode graphlist splitbits name = do
  -- putStrLn "1"
  cycles <- graphToCycles graphlist False
  -- putStrLn "2"
  let endhere = splitbits
  -- putStrLn "3"
  let startmap = \start -> (show start, (fst $ generateMaxCyCodeAtStart graphlist cycles endhere splitbits) start)
  --let startmap = \start ->liftM (\cy -> (show start, fst $ generateMaxCyCode graphlist cy start endhere splitbits)) cycles
  let codelist = map startmap  [0..(2^splitbits)-1] :: [(String, String)]
  removeDirIfExists name
  mkdir_results <- readProcess "mkdir" [name] []
  -- putStrLn "4"
  --writeC (head codelist)
  mapM_ writeC (map return codelist)
  return "Done."
    where
      -- writeC :: IO (String, String) ->IO (IO ())
      writeC :: IO (String, String) -> IO [Char]
      writeC input = do
        start <- input >>= return . fst -- :: [Char]
        code <- input >>= return . snd -- :: [Char]
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

-- | This function does exactly what it says, for '.c' files
compileAllInDir :: [Char] -> IO ()
compileAllInDir dir = do
  files <- getDirectoryContents dir
  let cFile = \file ->((last file) == 'c') && ((last $ init file) == '.')
  code_files <- return $ filter cFile files
  let compile file = readProcess "gcc" [dir ++ "/" ++ file, "-O3", "-o", "findcy_temp"] [] >>= putStrLn
  mapM_ compile code_files

-- | This function runs all the files in a given directory, ascertained by those filenames that do not include a '.'
runAllInDir :: [Char] -> IO ()
runAllInDir dir = do
  files <- getDirectoryContents dir
  exec_files <- return $ filter execFile files
  let run file = readProcess ("./" ++ file) [] [] >>= putStrLn
  mapM_ run exec_files
    where
      execFile name
          | name == []         = True
          | (last name) == '.' = False
          | otherwise         = execFile $ init name
