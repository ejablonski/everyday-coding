hello_worlds 1 = putStrLn "Hello World"
hello_worlds x = do putStrLn "Hello World"
                    hello_worlds (x-1)
main = do
   n <- readLn :: IO Int
   hello_worlds n