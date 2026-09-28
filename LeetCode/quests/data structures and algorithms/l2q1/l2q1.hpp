#include <algorithm>
#include <numeric>
#include <vector>

struct Solution
{
    static std::vector<int> findErrorNums(std::vector<int>& _nums)
    {
        std::vector<int> ans(2);
        std::ranges::sort(_nums);

        ans[0] = *std::ranges::adjacent_find(_nums);

        auto [first, last] = std::ranges::unique(_nums);
        _nums.erase(first, last);

        /*
         * Algorithm explanation: Sum Formula (Gauss's Formula)
         */
        long long n = _nums.size() + 1;
        long long expectedSum = (n * (n + 1)) / 2;
        long long actualSum = std::accumulate(_nums.begin(), _nums.end(), 0LL);

        ans[1] = static_cast<int>(expectedSum - actualSum);

        return ans;
    }
};
