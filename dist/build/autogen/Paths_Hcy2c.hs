module Paths_Hcy2c (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch

version :: Version
version = Version [0,1,1,0] []
bindir, libdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/Users/michaelklein/Desktop/Hcy2c/.cabal-sandbox/bin"
libdir     = "/Users/michaelklein/Desktop/Hcy2c/.cabal-sandbox/lib/x86_64-osx-ghc-7.8.3/Hcy2c-0.1.1.0"
datadir    = "/Users/michaelklein/Desktop/Hcy2c/.cabal-sandbox/share/x86_64-osx-ghc-7.8.3/Hcy2c-0.1.1.0"
libexecdir = "/Users/michaelklein/Desktop/Hcy2c/.cabal-sandbox/libexec"
sysconfdir = "/Users/michaelklein/Desktop/Hcy2c/.cabal-sandbox/etc"

getBinDir, getLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "Hcy2c_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "Hcy2c_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "Hcy2c_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "Hcy2c_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "Hcy2c_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
