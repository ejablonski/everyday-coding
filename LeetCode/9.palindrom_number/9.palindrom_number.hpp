#include <algorithm>
#include <ranges>
#include <string>

namespace LC9 {

struct Solution
{
    static bool isPalindrome(int _x)
    {
        std::string s = std::to_string(_x);
        return std::ranges::equal(s, s | std::views::reverse);
    }
};

} // namespace LC9
