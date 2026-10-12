#include <vector>
/**
 * Learning Journal:
 * - Pattern: Bit Manipulation + Greedy (Bit Conservation & Redistribution).
 * - Bit Invariant: Replacing (x, y) with (x & y, x | y) preserves the total count of 1-bits at
 *   every position, migrating 1-bits from one number into the other (the OR result).
 * - Greedy Strategy: Because squaring is convex (x^2 + y^2 is maximized when values are as
 *   unequal as possible), we greedily concentrate available 1-bits to assemble the k largest
 *   possible numbers.
 * - Trap: Remember to explicitly initialize accumulators (val = 0), and perform products using
 *   64-bit integers (long long) before applying modulo 10^9 + 7 to prevent integer overflow.
 * - Complexity: O(32 * N + 32 * k) = O(N) time and O(1) auxiliary space.
 */
struct Solution
{
    static constexpr long long MOD = 1'000'000'007;

    [[nodiscard]]
    static int maxSum(std::vector<int>& _nums, int _k)
    {
        std::vector<int> bit_counts(32, 0);
        int ans = 0;

        for (const auto n : _nums) {
            for (int i = 0; i < bit_counts.size(); i++) {
                if (((n >> i) & 1) == 1) {
                    bit_counts[i]++;
                }
            }
        }

        for (int i = 0; i < _k; i++) {
            long long val = 0;

            for (int j = 0; j < bit_counts.size(); j++) {
                if (bit_counts[j] > 0) {
                    val |= (1LL << j);
                    bit_counts[j]--;
                }
            }

            ans = (ans + (val * val) % MOD) % MOD;
        }

        return ans;
    }
};
