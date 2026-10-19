#include <algorithm>
#include <vector>

struct Solution
{
    [[nodiscard]]
    static std::vector<int> targetIndices(std::vector<int>& _nums, int _target)
    {
        std::ranges::sort(_nums);
        std::vector<int> indices{};

        for (int i = 0; i < _nums.size(); i++) {
            if (_nums[i] == _target) {
                indices.push_back(i);
            }

            if (_nums[i] > _target) {
                break;
            }
        }

        return indices;
    }
};
