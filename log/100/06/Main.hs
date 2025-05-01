-- {{{ Import

import Control.Monad
import Data.Array.Unboxed
import Data.Bool
import Data.ByteString.Char8 qualified as BS
import Data.Char
import Data.List
import Data.Maybe

-- }}}
-- {{{ Solve

f :: Char -> Char -> Bool
f _ '?' = True
f c1 c2 = c1 == c2

solve :: String -> String -> Bool
solve t u = any (helper u) $ tails t

helper u t
  | length u <= length t = and $ zipWith f u t
  | otherwise = False

main :: IO ()
main = do
  t <- getLine
  u <- getLine
  putStrLn (yn (solve t u))

-- }}}
-- {{{ Prelude

yn :: Bool -> String
yn = bool "No" "Yes"

getInt :: IO Int
getInt = fst . fromJust . BS.readInt <$> BS.getLine

getInts :: IO [Int]
getInts = unfoldr (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine

getStringArray :: IO (UArray Int Char)
getStringArray = do
  s <- BS.getLine
  return $ listArray @UArray (1, BS.length s) (BS.unpack s)

-- }}}

-- https://atcoder.jp/contests/abc403/submissions/65368416
