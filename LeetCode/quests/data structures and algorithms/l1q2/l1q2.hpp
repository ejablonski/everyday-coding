#include <vector>

struct Solution
{
    static std::vector<int> shuffle(std::vector<int>& _nums, int _n)
    {
        std::vector<int> ans{};
        for (int i = 0; i < _n; i++) {
            ans.push_back(_nums[i]);
            ans.push_back(_nums[_n + i]);
        }

        return ans;
    }
};
