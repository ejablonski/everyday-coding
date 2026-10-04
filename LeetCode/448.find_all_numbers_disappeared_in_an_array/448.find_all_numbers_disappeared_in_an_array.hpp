#include <algorithm>
#include <ranges>
#include <vector>

struct Solution
{
    static std::vector<int> findDisappearedNumbers(std::vector<int>& _nums)
    {
        std::ranges::sort(_nums);
        std::vector<int> diff;
        std::ranges::set_difference(std::views::iota(1u, _nums.size() + 1), _nums,
                                    std::back_inserter(diff));

        return diff;
    }
};
