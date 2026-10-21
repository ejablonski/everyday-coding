#include <algorithm>
#include <string>

struct Solution
{
    [[nodiscard]]
    static int minOperations(std::string& _s)
    {
        bool is_sorted = std::ranges::is_sorted(_s);

        if (is_sorted) {
            return 0;
        }

        const auto min = std::ranges::min(_s);
        const auto max = std::ranges::max(_s);
        const auto size = _s.size();
        const auto first = _s[0];
        const auto last = _s[_s.size() - 1];

        if (!is_sorted && size <= 2) {
            return -1;
        }

        if (first == min || last == max) {
            return 1;
        }

        const auto min_only_at_end = (_s.find(min) == _s.size() - 1);
        const auto max_only_at_start = (_s.rfind(max) == 0);

        if (min_only_at_end && max_only_at_start) {
            return 3;
        }

        return 2;
    }
};
