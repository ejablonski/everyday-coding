#include <algorithm>
#include <ranges>

struct Solution
{
    static int pivotInteger(int _n)
    {
        auto numbers = std::views::iota(1, _n + 1);

        for (int i = 1; i <= numbers.size(); ++i) {
            int a = std::ranges::fold_left(numbers | std::views::take(i), 0, std::plus<int>{});
            int b = std::ranges::fold_left(numbers | std::views::drop(i - 1), 0, std::plus<int>{});

            if (a == b) {
                return i;
            }
        }

        return -1;
    }
};
