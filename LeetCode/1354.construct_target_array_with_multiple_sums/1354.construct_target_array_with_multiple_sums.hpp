#include <queue>
#include <vector>

namespace LC1354 {

struct Solution
{
    [[nodiscard]] static bool isPossible(std::vector<int>& _target) noexcept
    {
        std::priority_queue<int> pq{};
        long total_sum = 0;

        pq.push_range(_target);

        for (auto n : _target) {
            total_sum += n;
        }

        // Case A (rest_sum == 0): If the largest element is already 1 (like target = [1]), you're
        // already at all 1s (true). Otherwise, if there's only 1 element (rest_sum == 0), max_val %
        // 0 would crash with division by zero—and [1] can never reach [2] anyway—so rest_sum == 0
        // immediately means false. Case B (max_val <= rest_sum): Spot-on. Every element is at least
        // 1, so max_val = old_val + rest_sum forces max_val > rest_sum. If max_val <= rest_sum,
        // return false. Case C (max_val % rest_sum == 0): Exactly. In [2, 4], subtracting 2 goes 4
        // → 2 → 0, jumping right over 1. Case D TBC

        return false;
    }
};

} // namespace LC1354
