#include <queue>
#include <vector>

/**
 * Thanks to std::priority_queue this problem is trivial
 */
struct Solution
{
    [[nodiscard]] static int lastStoneWeight(std::vector<int>& _stones) noexcept
    {
        std::priority_queue<int> pq(_stones.begin(), _stones.end());

        while (pq.size() >= 2) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            int new_stone = std::abs(s1 - s2);

            if (new_stone > 0) {
                pq.push(new_stone);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
