#include <algorithm>
#include <ranges>
#include <vector>

struct Solution
{
    [[nodiscard]]
    static int sortableIntegers(std::vector<int>& _nums)
    {
        std::vector<int> ks{};
        int sum_of_ks = 0;
        for (int i = 1; i <= _nums.size(); i++) {
            if (_nums.size() % i == 0) {
                ks.push_back(i);
            }
        }

        for (const auto k : ks) {
            bool k_invalid = false;
            std::vector<std::pair<int, int>> min_max{};

            for (int i = 0; i < _nums.size() / k; i++) {
                const auto subarray{_nums | std::views::drop(i * k) | std::views::take(k) |
                                    std::ranges::to<std::vector>()};

                int drops = subarray.back() > subarray.front() ? 1 : 0;
                for (int j = 1; j < subarray.size(); j++) {
                    if (subarray[j] < subarray[j - 1]) {
                        drops++;
                    }

                    if (drops > 1) {
                        k_invalid = true;
                        break;
                    }
                }

                if (k_invalid) {
                    break;
                }

                min_max.push_back({std::ranges::min(subarray), std::ranges::max(subarray)});
            }

            if (!k_invalid) {
                bool is_sorted = true;
                for (int m = 0; m < min_max.size() - 1; m++) {
                    if (min_max[m].second > min_max[m + 1].first) {
                        is_sorted = false;
                        break;
                    }
                }

                if (is_sorted) {
                    sum_of_ks += k;
                }
            }
        }

        return sum_of_ks;
    }
};
