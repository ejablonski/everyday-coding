#include <algorithm>
#include <iterator>
#include <vector>

/**
 * Solution explanation: In sorted array every prev element will be smaller so you just need to
 * find an index of an element in a sorted array. O(N log N) complexity.
 */
struct Solution
{
    static std::vector<int> smallerNumbersThanCurrent(std::vector<int>& _nums)
    {
        std::vector<int> ans{};
        ans.reserve(_nums.size());
        std::vector<int> v = _nums;
        std::ranges::sort(v);

        for (const auto n : _nums) {
            auto it = std::ranges::lower_bound(v, n);
            ans.push_back(static_cast<int>(std::distance(v.begin(), it)));
        }

        return ans;
    }
};
