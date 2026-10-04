#include <ranges>
#include <string>
#include <vector>

struct Solution
{
    [[nodiscard]]
    static std::vector<int> factorials(int _n)
    {
        std::vector<int> fact(_n, 1);
        for (int i = 1; i < _n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        return fact;
    }

    /**
     * ALGORITHM EXPLANATION: Factorial Number System
     *
     * Because there are exactly n! permutations of n items, the factoradic representation
     * of k dictates exactly which item to pick at each step from a sorted list of remaining
     * available items.
     */
    [[nodiscard]]
    static std::string getPermutation(int _n, int _k)
    {
        auto nums = std::views::iota('1', '1' + _n) | std::ranges::to<std::string>();

        std::string result;
        int reminder = _k - 1;

        for (auto f : factorials(_n) | std::views::reverse) {
            int idx = reminder / f;
            result += nums[idx];
            nums.erase(nums.begin() + idx);
            reminder %= f;
        }

        return result;
    }
};
