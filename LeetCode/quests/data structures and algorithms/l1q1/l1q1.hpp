#include <vector>

struct Solution
{
    static std::vector<int> getConcatenation(std::vector<int>& nums)
    {
#ifdef __cpp_lib_containers_ranges
        nums.append_range(nums);
#else
        nums.insert(nums.end(), nums.cbegin(), nums.cend());
#endif
        return nums;
    }
};
