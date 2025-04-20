-- {{{ Import
import Data.Maybe
import Control.Monad
import Data.ByteString.Char8 qualified as BS
-- }}}

solve :: Int -> Int -> Int -> String -> String
solve a b c s
    = show (a + b + c) ++ " " ++ s

main :: IO ()
main = do
    a <- getInt
    [b, c] <- getInts
    s <- getLine
    putStrLn $ solve a b c s

-- {{{ Prelude

getInt :: IO Int
getInt = fst . fromJust . BS.readInt <$> BS.getLine

getInts :: IO [Int]
getInts = map read . words <$> getLine :: IO [Int]
-- }}}
