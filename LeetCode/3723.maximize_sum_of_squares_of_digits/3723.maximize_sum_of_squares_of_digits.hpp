#include <string>

/**
 * Learning Journal:
 * - Pattern: Greedy construction & convex optimization.
 * - Insight: Because f(x) = x^2 is strictly convex, maximizing the sum of squared digits
 *   requires concentrating digit values into extremes (as many 9s and 0s as possible),
 *   avoiding balanced distributions.
 * - Ordering: Placing digits in descending order (9s first, followed by the remainder, then 0s)
 *   simultaneously maximizes the numerical value among all integers achieving the maximal score.
 * - Boundary Check: If 9 * num < sum, no num-digit integer can attain sum, immediately returning
 * "".
 * - Complexity: O(num) time to construct the string, O(1) auxiliary space beyond the output.
 */

struct Solution
{
    [[nodiscard]]
    static std::string maxSumOfSquares(int _num, int _sum)
    {
        if (9 * _num < _sum) {
            return "";
        }

        int nines = _sum / 9;
        int reminder = _sum % 9;
        int zeros = _num - nines - (reminder > 0 ? 1 : 0);

        return std::string(nines, '9') + (reminder > 0 ? std::to_string(reminder) : "") +
               (zeros > 0 ? std::string(zeros, '0') : "");
    }
};
