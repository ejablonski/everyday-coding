# Exceptional Server

Your friend set up a small computational server that performs complex calculations. 
It has a function that takes `2` large numbers as its input and returns a numeric result. Unfortunately, there are various exceptions that may occur during execution.

Complete the code in your editor so that it prints appropriate error messages, should anything go wrong. The expected behavior is defined as follows:

 - If the compute function runs fine with the given arguments, then print the result of the function call.
 - If it fails to allocate the memory that it needs, print `Not enough memory`.
 - If any other standard C++ exception occurs, print `Exception: S` where `S` is the exception's error message.
 - If any non-standard exception occurs, print `Other Exception`.

## HackerRank

This problem comes from [https://www.hackerrank.com/challenges/exceptional-server/problem](https://www.hackerrank.com/challenges/exceptional-server/problem)

Author [Dalimil](https://www.hackerrank.com/Dalimil)