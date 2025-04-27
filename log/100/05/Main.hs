-- {{{ Import

import Control.Monad
import Data.ByteString.Char8 qualified as BS
import Data.Char
import Data.List
import Data.Maybe

-- }}}

solve n xs =
  sum [x | (i, x) <- zip [0 ..] xs, even i]

main :: IO ()
main = do
  n <- getInt
  a <- getInts
  let res = solve n a
  print res

-- {{{ Prelude

getInt :: IO Int
getInt = fst . fromJust . BS.readInt <$> BS.getLine

getInts :: IO [Int]
getInts = unfoldr (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine

-- }}}

-- https://atcoder.jp/contests/abc403/submissions/65300669
