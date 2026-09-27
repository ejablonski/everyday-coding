#include <vector>

struct Solution
{
    static std::vector<int> getConcatenation(std::vector<int>& _nums)
    {
#ifdef __cpp_lib_containers_ranges
        _nums.append_range(_nums);
#else
        _nums.insert(_nums.end(), _nums.cbegin(), _nums.cend());
#endif
        return _nums;
    }
};
