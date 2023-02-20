module DifferenceOfSquares exposing (difference, squareOfSum, sumOfSquares)

squareOfSum : Int -> Int
squareOfSum n =
    (List.sum(List.range 0 n)) ^ 2

sumOfSquares : Int -> Int
sumOfSquares n =
    if n == 0 then 0
    else (n^2) + sumOfSquares (n - 1)

difference : Int -> Int
difference n =
    squareOfSum n - sumOfSquares n
