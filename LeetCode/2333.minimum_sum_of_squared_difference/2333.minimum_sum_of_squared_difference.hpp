#include <cmath>
#include <vector>

/**
 * Learning Journal:
 * - Pattern: Greedy Optimization ("Shaving the Peaks") via Frequency Buckets.
 * - Time Complexity: O(N) where N is the length of the arrays. The bucket array loop is bounded by O(max_diff) which is O(1) constant.
 * - Space Complexity: O(1) constant. The bucket array size (100,001) is strictly bounded and does not grow with N.
 * - Aha! Moment: When minimizing a sum of squares, always reduce the absolute largest numbers first to get the highest ROI (since squares grow exponentially). 
 * - Optimization: If budget `k` is massive (10^9), never simulate reductions one by one. Group identical differences into a bucket/frequency array and reduce them in bulk!
 * - Trap: Beware of 32-bit integer overflow! The product `i * i` can exceed the limit of a 32-bit `uint` when `i` is 100,000, so it must be cast or typed to a 64-bit `long long` before squaring.
 */

struct Solution
{
    [[nodiscard]]
    static long long minSumSquareDiff(std::vector<int>& _nums1, std::vector<int>& _nums2, int _k1,
                                      int _k2)
    {
        // Max size comes from problem's constrains
        std::vector<long long> tally(100001, 0);
        long long reductions = _k1 + _k2;
        long long ans = 0;

        for (uint i = 0; i < _nums1.size(); i++) {
            tally[std::abs(_nums1[i] - _nums2[i])]++;
        }

        for (uint i = tally.size() - 1; i > 0; --i) {
            if (reductions == 0) {
                break;
            }

            if (tally[i] != 0) {
                if (tally[i] >= reductions) {
                    tally[i] -= reductions;
                    tally[i - 1] += reductions;
                    reductions = 0;
                }
                if (tally[i] < reductions) {
                    tally[i - 1] += tally[i];
                    reductions -= tally[i];
                    tally[i] = 0;
                }
            }
        }

        for (long long i = 1; i < tally.size(); i++) {
            ans += tally[i] > 0 ? tally[i] * (i * i) : 0;
        }

        return ans;
    }
};
