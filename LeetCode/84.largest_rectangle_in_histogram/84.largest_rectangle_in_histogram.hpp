#include <stack>
#include <vector>
/**
 * Learning Journal:
 * - Pattern: Monotonic Stack (increasing order of bar heights).
 * - What Stack Tracks: Indices of bars waiting for their right wall (the first shorter bar).
 * - Left Wall Intuition: Popping the current bar exposes the index sitting directly beneath it
 *   on the stack, which is guaranteed to be the nearest bar to the left shorter than itself.
 *   If the stack becomes empty after popping, the bar could stretch all the way to index 0.
 * - Width Calculation: width = stack.empty() ? right_wall : (right_wall - stack.top() - 1).
 * - Complexity: O(N) time and O(N) space, avoiding the naive O(N^2) expansion.
 */
struct Solution
{
    [[nodiscard]]
    static int largestRectangleArea(std::vector<int>& _heights)
    {
        std::stack<int> h_idx{};
        int max_area = 0;

        for (int i = 0; i < _heights.size(); i++) {
            while (!h_idx.empty() && _heights[i] <= _heights[h_idx.top()]) {
                int height = _heights[h_idx.top()];
                h_idx.pop();
                int width = h_idx.empty() ? i : i - h_idx.top() - 1;
                max_area = std::max(max_area, width * height);
            }
            h_idx.push(i);
        }

        while (!h_idx.empty()) {
            int height = _heights[h_idx.top()];
            h_idx.pop();
            int width = h_idx.empty() ? _heights.size() : _heights.size() - 1 - h_idx.top();
            max_area = std::max(max_area, width * height);
        }

        return max_area;
    }
};
