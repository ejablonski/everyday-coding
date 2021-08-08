# Formin a magic square

We define a [magic square](https://en.wikipedia.org/wiki/Magic_square) to be an `n x n` matrix of distinct positive integers from `1` to `n2` where the sum of any row, column, or diagonal (of length `n`) is always equal to the same number (i.e., the magic constant).

Consider a `3 x 3` matrix, `s`, of integers in the inclusive range `[1, 9]`. We can convert any digit, `a`, to any other digit, `b`, in the range `[1, 9]` at cost `|a - b|`.

Given `s`, convert it into a magic square at *minimal* cost by changing zero or more of its digits. Then print this cost on a new line.

**Note:** The resulting magic square must contain distinct integers in the inclusive range `[1, 9]`.

## HackerRank

This problem comes from [https://www.hackerrank.com/challenges/magic-square-forming/problem](https://www.hackerrank.com/challenges/magic-square-forming/problem)

Author [pkacprzak](https://www.hackerrank.com/pkacprzak)