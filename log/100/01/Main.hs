-- {{{ Import

import Control.Monad
import Data.ByteString.Char8 qualified as BS
import Data.Char
import Data.Maybe

-- }}}

solve s =
  let s' = filter isAsciiUpper s
   in s'

main :: IO ()
main = do
  s <- getLine
  putStrLn $ solve s

-- {{{ Prelude

getInt :: IO Int
getInt = fst . fromJust . BS.readInt <$> BS.getLine

getInts :: IO [Int]
getInts = map read . words <$> getLine :: IO [Int]

-- }}}

-- https://atcoder.jp/contests/abc402/submissions/65063255
