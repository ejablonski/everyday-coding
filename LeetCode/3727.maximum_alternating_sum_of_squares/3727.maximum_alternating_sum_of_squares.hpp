#include <algorithm>
#include <ranges>
#include <vector>
/**
 * Learning Journal:
 * - Pattern: Greedy sorting & alternating array partition.
 * - Insight: Squaring numbers eliminates sign polarity (x^2 >= 0). To maximize an
 *   alternating sum (+ / -), greedily assign the largest squares to the positive
 *   slots and the smallest squares to the negative slots.
 * - Invariants & Slices: In an array of size n, exactly floor(n / 2) elements are
 *   subtracted and ceil(n / 2) elements are added. Sorting ascending places the
 *   smallest elements at the front. Thus, taking the first n / 2 elements yields the
 *   subtracted items, while dropping n / 2 yields the remaining ceil(n / 2) added items.
 * - Complexity: O(N log N) time due to sorting, O(1) auxiliary space (in-place mutation).
 */
struct Solution
{
    [[nodiscard]]
    static long long maxAlternatingSum(std::vector<int>& _nums)
    {
        long long ans = 0;
        std::ranges::for_each(_nums, [](auto& n) { n *= n; });
        std::ranges::sort(_nums);
        std::ranges::for_each(_nums | std::views::take(_nums.size() / 2),
                              [&](const int& n) { ans -= n; });
        std::ranges::for_each(_nums | std::views::drop(_nums.size() / 2),
                              [&](const int& n) { ans += n; });

        return ans;
    }
};
