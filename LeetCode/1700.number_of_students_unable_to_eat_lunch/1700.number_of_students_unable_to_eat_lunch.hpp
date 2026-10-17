#include <algorithm>
#include <vector>

struct Solution
{
    [[nodiscard]]
    static int countStudents(std::vector<int>& _students, std::vector<int>& _sandwiches)
    {
        auto s0 = std::ranges::count(_students, 0);
        auto s1 = std::ranges::count(_students, 1);

        for (const auto s : _sandwiches) {
            if (s == 0) {
                if (s0 > 0) {
                    s0--;
                } else {
                    break;
                }
            } else {
                if (s1 > 0) {
                    s1--;
                } else {
                    break;
                }
            }
        }

        return s0 + s1;
    }
};
