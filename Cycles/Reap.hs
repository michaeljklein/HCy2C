module Cycles.Reap where

import Cycles.Aux (trim, orientGraph)
import Cycles.IO
--import Data.GList

import Control.Monad (mapM_, unless, liftM2, when)
import Data.Foldable (foldlM)
import Data.List (reverse)
import Data.ByteString (hGetContents, readFile, writeFile, init, tail, ByteString)--(readFile, null, ByteString, read, init, tail, split, first, last)
import qualified Data.ByteString.Char8 as C8
import System.Directory (renameFile, getDirectoryContents)
import System.IO

import Debug.Trace (traceShow) -- debug lines marked DEBUG

--import qualified Prelude as P

--  Here are the functions for reaping the results of computing the maximally cyclic orientations of various graphs.
--  This includes functions for:
--    trimming all results in a directory
--    checking all results in a directory
--    collecing all results, given a list (GList) of names associated with each graph

-- Since the outlines are fixed length, I could just detect the length of one and then easily filter/parse the rest...
-- How about read/write where I get the second line, detect length -> find range in which there's a solution, skip to last result and get bestval
-- then iterate through lines replacing the non-best lines with all 0's (except the '\n's). next, collect all chars, skipping 0's or '\n's that are
-- two in a row.


trimAllResults :: String -> IO ()
trimAllResults dir = do
  files <- getDirectoryContents dir
  let resultFiles = Prelude.filter isresult files
  mapM_ trimResult resultFiles
  where
    isresult name = isgraph name && istxt name
    isgraph name = Prelude.take 8 name == "graphNum"
    istxt name = Prelude.take 3 (Data.List.reverse name) == "txt"

-- | This function trims a single result (removes all non-optimal values and saves the file)
trimResult :: FilePath -> IO ()
trimResult filename = do
  --filestr <- catch (readFile filename) handler -- <- openFile filename ReadWriteMode
--  file <- Data.ByteString.readFile filename :: IO ByteString
  handle <- openFile filename ReadMode
  file <- Data.ByteString.hGetContents handle
  Data.ByteString.writeFile tempFileName $ trimByteStringResult file
  removeIfExists filename
  renameFile tempFileName filename
    where
      tempFileName = filename ++ "_temp"
  -- where
  --   handler :: SomeException -> IO String
  --   handler _ = error "The results have disappeared under my nose."

trimBS = Data.ByteString.init . Data.ByteString.tail

justThat (Just x) = x
justThat Nothing = error "some Int I was supposed to read was nothing"

trimSpaces :: ByteString -> ByteString
trimSpaces = C8.filter (/= ' ')
trimNulls = C8.filter (/= '\NUL')

cutAfterComma :: ByteString -> ByteString
cutAfterComma bstr
  | C8.null bstr = C8.empty
  | C8.head bstr == ',' = C8.tail bstr
  | otherwise = cutAfterComma $ C8.tail bstr


parseSolution :: ByteString -> Int
parseSolution solution
  | C8.null solution = 0
  | otherwise = fst $ justThat $ C8.readInt $ trimSpaces $ C8.init $ cutAfterComma solution
--  | otherwise = readSoln $ C8.unpack $ C8.init $ cutAfterComma solution
    where
--      readSoln bstr = read bstr :: Int

trimByteStringResult :: ByteString -> ByteString
trimByteStringResult results = if finished then trimNulls $ C8.unlines (graph ++ filtered ++ [C8.pack "FINISHED."]) else results
  where
    filtered = Prelude.filter (\s ->parseSolution s == best) solutions
    rlines = C8.lines results :: [ByteString]
    graph = [Prelude.head rlines]
    finished = Prelude.last rlines == C8.pack "\NULFINISHED." --error "somehow not read as finished"
    solutions = if finished then Prelude.tail $ Prelude.init rlines else [] :: [ByteString]
    best = parseSolution $ Prelude.last solutions



-- Here are the functions for collecting several outputs into one, consolidating, matching with something from GList,
-- converting binary orientations into digraphs, and outputting into a single file

-- justPosition :: Eq a => a -> [a] -> Int
-- justPosition e list
--   | Prelude.null list = error "none of these lists should be empty"
--   | Prelude.head list == e = 0
--   | otherwise = 1 + justPosition e (Prelude.tail list)
-- splitAt :: Char -> String -> [String]
-- splitAt c str
--   | c `notElem` str = [str]
--   | otherwise = fst splitted : Cycles.Reap.splitAt c (snd splitted)
--     where
--       splitted = Prelude.splitAt (1 + justPosition c str) str

cutUntilChar :: Char -> String -> String
cutUntilChar c str
  | c `notElem` str = error "splitAt will only call this function if c is in the string, and now there is no c in the string"
  | Prelude.head str == c = []
  | otherwise = Prelude.head str : cutUntilChar c (Prelude.tail str)

cutAfterChar :: Char -> String -> String
cutAfterChar c str
  | c `notElem` str = error "see error for cutUntilChar"
  | Prelude.head str == c = Prelude.tail str
  | otherwise = cutAfterChar c (Prelude.tail str)

splitAt :: Char -> String -> [String]
splitAt c str
  | c `notElem` str = [str]
  | otherwise = cutUntilChar c str : Cycles.Reap.splitAt c (cutAfterChar c str)

-- | 'collectBy' takes a checking function and a list and returns ([x | f x], [x | not f x])
collectBy :: (a -> Bool) -> [a] -> ([a],[a])
collectBy f = foldl collector ([],[])
  where
--    collector :: ([a],[a]) -> a -> ([a],[a])
    collector sofar next = if f next
                              then (next : fst sofar, snd sofar)
                              else (fst sofar, next : snd sofar)

onlyJustFst Nothing = error "failed to read number from graph result"
onlyJustFst (Just x) = fst x

-- | This function takes a maxcy filename and a list of files and outputs (matching graphs, non-matching graphs)
-- Note: This function throws out files that are part of an incomplete series.
-- For example, if we input graphNum_..._0_2_out.txt but don't have graphNum_..._1_2_out.txt,
-- the output will be of the form: ([], [leftovers])
collectMatchingGraphs :: FilePath -> [FilePath] -> ([FilePath], [FilePath])
collectMatchingGraphs graphname filelist = checkMatches collected
  where
    graphnum = splitname graphname !! 2 :: String
    checkMatches (matches, leftover) = if length matches == onlyJustFst (C8.readInt (C8.pack (splitname graphname !! 4)))
                                          then (matches, leftover)
                                          else ([], leftover)
    collected = collectBy (\l -> (splitname l !! 2) == graphnum) filelist :: ([String], [String])
--    splitname filename = Prelude.init $ splitAt_ (drop 9 filename) :: [String]-- [number of edges, graph number, nth, out of m]
    splitname = splitAt_
    splitAt_ = Cycles.Reap.splitAt '_'

-- | This will group results into a lists of matching results
groupMatchingGraphs :: [FilePath] -> [[FilePath]]
groupMatchingGraphs filelist
  | null filelist = []
  | otherwise = fst headCollected : groupMatchingGraphs (snd headCollected)
    where
      headCollected = collectMatchingGraphs (Prelude.head filelist) filelist
--      headCollected = collectMatchingGraphs (Prelude.head filelist) (Prelude.tail filelist)
-- The above wrong line caused a lot of pain debugging, as it resulted in no groups with more than one element,
--   while being a simple typo and collectMatchingGraphs working fine.

checkAllFinished :: [FilePath] -> IO Bool
checkAllFinished filelist = do
  checks <- mapM checkOneFinished filelist
  foldlM (\x y ->return $ x && y) True checks
  where
    checkOneFinished :: FilePath -> IO Bool
    checkOneFinished file = do
      handle <- openFile file ReadMode
      contents <- Data.ByteString.hGetContents handle
      let lastLine = Prelude.last $ C8.lines contents
      return $ C8.elem 'F' lastLine && C8.elem 'D' lastLine

allEq :: Eq a => [a] -> Bool
allEq list
  | length list < 2 = True
  | head list == list !! 1 = allEq (Prelude.tail list)
  | head list /= list !! 1 = False

checkAllMatching :: [FilePath] -> IO Bool
checkAllMatching filelist = do
  checks <- mapM getHeader filelist
  return $ allEq checks
    where
      getHeader :: FilePath -> IO ByteString
      getHeader file = do
        handle <- openFile file ReadMode
        contents <- Data.ByteString.hGetContents handle
        return $ Prelude.head $ C8.lines contents

-- | "xyMap f list" is equivalent to "zip (map f list) list".
-- Example: "xyMap (*2) [1,2,3] = [(1,2),(2,4),(3,6)]"
xyMap :: (a -> b) -> [a] -> [(a,b)]
xyMap f = map (\x ->(x, f x))

reapResult :: [FilePath] -> IO [ByteString]
reapResult [] = return [C8.empty]
reapResult filelist = do --when allGood (do
  allFinished <- checkAllFinished filelist -- :: IO Bool
  allMatching <- checkAllMatching filelist -- :: IO Bool
  let allGood = allFinished && allMatching
--  unless allGood (error "somehow a bad solution file got in. (error passed from reapResult in Cycles.Reap)")
  files <- mapM C8.readFile filelist :: IO [ByteString]
  let graph = Prelude.head $ C8.lines $ Prelude.head files :: ByteString
  let results = concatMap (trim . C8.lines) files :: [ByteString]
  let parsedTuples = xyMap parseSolution results :: [(ByteString, Int)]
  when (null (map snd parsedTuples)) (error "line 205")
  let best = maximum $ map snd parsedTuples :: Int
  let bestTuples = filter (\b ->snd b == best) parsedTuples :: [(ByteString, Int)]
  let bests = map fst bestTuples :: [ByteString]
  (sluiceByteStrings allGood) (graph : bests)
  -- Here, convert graphs to digraphs

readBinList :: ByteString -> [Int]
readBinList bstr
  | C8.null bstr = []
  | C8.head bstr == '0' = 0 : readBinList (C8.tail bstr)
  | C8.head bstr == '1' = 1 : readBinList (C8.tail bstr)
  | otherwise = error "Attempted to read a binary list of form "0101010010" from a ByteString that contains characters other than '0' and '1'."

onlyJust Nothing = error "Input a ByteString without a proper number result into Cycles.Reap.processResult."
onlyJust (Just x) = fst x

processResult :: ByteString -> ([Int],Int)
processResult result = (list, number)
  where
    list = readBinList listBStr
    listBStr = Prelude.head resultPair
    number = onlyJust $ C8.readInt $ Prelude.head $ Prelude.tail resultPair
    resultPair = C8.split ',' resultTrimmed
    resultTrimmed = trimBS $ trimSpaces result

processGraph :: ByteString -> [[Int]]
processGraph bstr = read (C8.unpack bstr)

sluiceByteStrings :: Bool -> [ByteString] -> IO [ByteString]
sluiceByteStrings open bstr = if open then return bstr else return [C8.empty]

sluiceByteString :: Bool -> ByteString -> IO ByteString
sluiceByteString open bstr = if open then return bstr else return C8.empty

polishResult :: [ByteString] -> IO ByteString
polishResult resultList = do
  when (Prelude.null resultList) (error "polishResult")
  let rawGraph = Prelude.head resultList :: ByteString
  let graph = processGraph rawGraph :: [[Int]]
  let rawResults = Prelude.tail resultList :: [ByteString]
  let processedResults = map processResult rawResults :: [([Int],Int)]
  let digraphResults = map (\tup ->(orientGraph (fst tup) graph, snd tup)) processedResults :: [([[Int]],Int)]
  checks <- mapM checkResult digraphResults
  allGood <- foldlM (\x y ->return $ x && y) True checks
  let finalResults = C8.unlines [rawGraph, showResults digraphResults]
  sluiceByteString allGood finalResults
    where
      showResults :: [([[Int]],Int)] -> ByteString
      showResults results = C8.unlines (map (C8.pack . show) results)
      checkResult :: ([[Int]],Int) -> IO Bool
      -- checkResult result = liftM2 (==) (graphToNumCycles (traceShow result (fst result)) True) (return (snd result))
      checkResult result = liftM2 (==) (graphToNumCycles (fst result) True) (return (snd result))


-- DEBUG

reapAndPolishResult :: [FilePath] -> IO ByteString
reapAndPolishResult [] = return C8.empty
reapAndPolishResult fileList = do
  when (length fileList < 1) (error "reapAndPolishResult1")
  when (length (Prelude.head fileList) < 1) (error "reapAndPolishResult2")
  let graphNum = read (Prelude.head $ Prelude.tail $ splitname (Prelude.head fileList)) :: Int
  let graphName = fst $ gList !! graphNum
  reapedResult <- reapResult fileList
  polishedResult <- polishResult reapedResult
  return $ C8.concat [C8.pack "[\"", C8.pack graphName, C8.pack "\",", polishedResult, C8.pack "]"]
    where
      splitname filename = Prelude.init $ splitAt_ (drop 9 filename) :: [String]-- [number of edges, graph number, nth, out of m]
      splitAt_ = Cycles.Reap.splitAt '_'

reapAllResults :: FilePath -> FilePath -> IO ()
reapAllResults dir outFileName = do
  files <- getDirectoryContents dir
  let resultFiles = Prelude.filter isresult files
  let graphGroups = groupMatchingGraphs resultFiles
--  putStrLn $ show $ map Prelude.length graphGroups
  polishedResultsList <- mapM reapAndPolishResult graphGroups
  let polishedResults = C8.unlines polishedResultsList
  C8.writeFile outFileName polishedResults
  where
    isresult name = isgraph name && istxt name
    isgraph name = Prelude.take 8 name == "graphNum"
    istxt name = Prelude.take 3 (Data.List.reverse name) == "txt"


gList :: [(String, [[Int]])]
gList = map (\s -> (s, [[1]])) $ map show [0..]
