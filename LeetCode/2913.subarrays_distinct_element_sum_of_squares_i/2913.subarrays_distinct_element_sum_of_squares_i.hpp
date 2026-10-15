#include <unordered_set>
#include <vector>

struct Solution
{
    [[nodiscard]]
    static int sumCounts(std::vector<int>& _nums)
    {
        int sum = 0;
        for (int i = 0; i < _nums.size(); i++) {
            std::unordered_set<int> uniques{};
            for (int j = i; j < _nums.size(); j++) {
                uniques.insert(_nums[j]);
                sum += uniques.size() * uniques.size();
            }
        }
        return sum;
    }
};
