#include <stack>
#include <vector>

/**
 * Learning Journal:
 * - Pattern: Monotonic Stack (Next Greater Element - Distance/Span Variant).
 * - Aha! Moment: Pre-initializing the result vector with zeros (`warmer(n, 0)`) automatically
 *   handles days that never find a warmer temperature without needing post-processing.
 *   Storing indices on the stack allows calculating the wait distance (`i - day_indexes.top()`)
 *   directly.
 * - Invariant: The stack maintains indices of unresolved days in decreasing (non-increasing)
 *   temperature order. An incoming strictly warmer day (`_temperatures[top] < _temperatures[i]`)
 *   cascades and resolves all eligible days, maintaining O(N) time since each index is pushed
 *   and popped at most once.
 */
struct Solution
{
    [[nodiscard]]
    static std::vector<int> dailyTemperatures(std::vector<int>& _temperatures)
    {
        std::vector<int> warmer(_temperatures.size(), 0);
        std::stack<int> day_indexes{};

        for (int i = 0; i < _temperatures.size(); i++) {
            while (!day_indexes.empty() && _temperatures[day_indexes.top()] < _temperatures[i]) {
                warmer[day_indexes.top()] = i - day_indexes.top();
                day_indexes.pop();
            }

            day_indexes.push(i);
        }
        return warmer;
    }
};
