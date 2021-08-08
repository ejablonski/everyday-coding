# Beetwen two sets

Consider two sets of positive integers, `A = {a0, a1,..., an-1}` and `B = {b0, b1,..., bm-1}`. We say that a positive integer, `x`, is between sets `A` and `B` if the following conditions are satisfied:

- All elements in `A` are factors of `x`.
- `x` is a factor of all elements in `B`.

In other words, some `x` is between `A` and `B` if that value of `x` satisfies `x mod a(i) = 0` for every `a(i)` in `A` and also satisfies `b(i) mod x = 0` for every `b(i)` in `B`. For example, if `A = {2, 6}` and `B = {12}`, then our possible `x` values are `6` and `12`.

Given `A` and `B`, find and print the number of integers (i.e., possible `x`'s) that are between the two sets.

## HackerRank

This problem comes from [https://www.hackerrank.com/challenges/bon-appetit/problem](https://www.hackerrank.com/challenges/bon-appetit/problem)

Author [shashank21j](https://www.hackerrank.com/shashank21j)