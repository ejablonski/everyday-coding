#include <queue>
#include <vector>

namespace LC373 {

struct Solution
{
    [[nodiscard]] static std::vector<std::vector<int>>
    kSmallestPairs(std::vector<int>& _nums1, std::vector<int>& _nums2, int _k) noexcept
    {
        using tuple = std::tuple<int, int, int>;
        std::priority_queue<tuple, std::vector<tuple>, std::greater<>> pq{};
        std::vector<std::vector<int>> ans{};

        for (int i = 0; i <= std::min(static_cast<int>(_nums1.size()), _k) - 1; i++) {
            pq.emplace(+_nums1[i] + _nums2[0], i, 0);
        }

        while (ans.size() < _k && !pq.empty()) {
            auto smallest = pq.top();
            pq.pop();
            int nums1_idx = std::get<1>(smallest);
            int nums2_idx = std::get<2>(smallest);
            ans.push_back({_nums1[nums1_idx], _nums2[nums2_idx]});

            if (nums2_idx + 1 < _nums2.size()) {
                pq.emplace(+_nums1[nums1_idx] + _nums2[nums2_idx + 1], nums1_idx, nums2_idx + 1);
            }
        }

        return ans;
    }
};

} // namespace LC373
