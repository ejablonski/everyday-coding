#include <ranges>
#include <vector>

struct Solution
{
    static std::vector<int> selfDividingNumbers(int _left, int _right)
    {
        /*
         * ALGORITHM EXPLANATION: Numeric Digit Extraction
         *
         * Because our decimal number system is base-10 (e.g., 128 = 100 + 20 + 8),
         * we can peel numbers apart digit-by-digit using basic arithmetic instead of
         * slow string allocations (std::to_string).
         *
         * 1. Modulo 10 (temp % 10): Gives the remainder of division by 10, which
         *    always perfectly isolates the last digit in the "ones" column.
         * 2. Divide by 10 (temp /= 10): In C++ integer math, fractions are truncated.
         *    Dividing by 10 essentially shifts the entire number to the right,
         *    cleanly chopping off the last digit.
         */
        return std::views::iota(_left, _right + 1) | std::views::filter([](int _x) {
                   int temp = _x;
                   while (temp > 0) {
                       int digit = temp % 10;

                       if (digit == 0 || _x % digit != 0) {
                           return false;
                       }

                       temp /= 10;
                   }
                   return true;
               }) |
               std::ranges::to<std::vector<int>>();
    }
};
