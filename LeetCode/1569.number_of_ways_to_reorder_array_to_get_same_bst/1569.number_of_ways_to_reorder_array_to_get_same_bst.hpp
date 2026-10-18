#include <ranges>
#include <vector>

/**
 * Learning Journal:
 *
 * - Problem: LeetCode 1569 - Number of Ways to Reorder Array to Get Same BST
 * - Pattern: Divide & Conquer (BST Invariant) + Combinatorics (Pascal's Triangle DP)
 *
 * - Core Invariant:
 *   When constructing a BST by sequential insertion, the very first element inserted
 *   must always serve as the root. Any value smaller than the root is routed to the
 *   left subtree, and any value larger is routed to the right subtree.
 *
 * - Aha! Moment (Interleaving Independence):
 *   To keep the exact same tree structure:
 *   1. The relative order within the left subtree elements must be strictly preserved.
 *   2. The relative order within the right subtree elements must be strictly preserved.
 *   3. However, elements of the left subtree and elements of the right subtree can be
 *      freely interleaved without affecting each other!
 *   Therefore, out of (L + R) available remaining positions, we choose L positions
 *   for the left subtree in C(L + R, L) ways. The right elements automatically occupy
 *   the remaining R positions in their fixed order.
 *
 * - Recurrence Relation:
 *   ways(nums) = C(|left| + |right|, |left|) * ways(left) * ways(right) % MOD
 *
 * - Base Case:
 *   For any sub-array with size <= 2, there is only 1 valid ordering that produces
 *   that identical BST structure. Returning 1 ensures the multiplicative identity
 *   is preserved across the recursive chain.
 *
 * - Top-Level Adjustment:
 *   The problem asks for the number of ways to *reorder* nums (i.e., permutations
 *   other than the original sequence). Hence, we subtract 1 from the total orderings:
 *   (total_ways - 1 + MOD) % MOD.
 *
 * - Numerical Pitfalls & Traps:
 *   1. Constant Value: MOD = 1e9 + 7 = 1,000,000,007 (avoid '10e9 + 7' which is 10^10 + 7).
 *   2. 32-bit Integer Overflow: Multiplying two numbers modulo 10^9 can yield up to
 *      10^18, exceeding 32-bit INT_MAX (~2.14 * 10^9). Intermediate products must be
 *      evaluated using 64-bit integers (long long) before applying '% MOD'.
 *
 * - Complexity:
 *   - Time: O(N^2) total:
 *     * O(N^2) to precompute Pascal's triangle table.
 *     * O(N^2) worst-case recursive partitioning (for degenerate/skewed trees),
 *       or O(N log N) on average for balanced trees.
 *   - Space: O(N^2) to store the 2D Pascal triangle combination table, plus O(N^2)
 *     for vector allocations along the recursive branches.
 */
struct Solution
{
    static constexpr long long MOD = 1e9 + 7;

    /**
     * Precomputes binomial coefficients C(n, k) modulo 10^9 + 7 using Pascal's Triangle:
     *   C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
     * This avoids costly factorials and modular inverse divisions.
     */
    [[nodiscard]]
    static std::vector<std::vector<int>> buildPascalsTriangle(int _n)
    {
        std::vector<std::vector<int>> triangle(_n + 1);

        for (int i = 0; i < _n + 1; i++) {
            // Boundaries C(i, 0) and C(i, i) are always 1
            triangle[i].resize(i + 1, 1);

            for (int j = 1; j < i; j++) {
                triangle[i][j] = (triangle[i - 1][j - 1] + triangle[i - 1][j]) % MOD;
            }
        }

        return triangle;
    }

    /**
     * Recursively computes the total number of ordering sequences that yield the exact
     * same BST structure as the input sequence.
     */
    [[nodiscard]]
    static long long buildBranch(const std::vector<int>& _branch,
                                 const std::vector<std::vector<int>>& _triangle)
    {
        // Arrays of size <= 2 have exactly 1 permutation yielding the same BST
        if (_branch.size() <= 2) {
            return 1;
        }

        int root = _branch[0];
        long long total = 0;

        // Partition elements into left (< root) and right (> root) subtrees,
        // preserving their original relative order using C++23 range views.
        auto left = _branch | std::views::drop(1) |
                    std::views::filter([&root](int n) { return n < root; }) |
                    std::ranges::to<std::vector>();
        auto right = _branch | std::views::drop(1) |
                     std::views::filter([&root](int n) { return n > root; }) |
                     std::ranges::to<std::vector>();

        // Recursively solve for left and right subtrees
        long long left_ways = buildBranch(left, _triangle);
        long long right_ways = buildBranch(right, _triangle);

        int left_length = left.size();
        int right_length = right.size();

        // Interleave left and right elements: choose left_length slots out of (left_length +
        // right_length) Note: 64-bit 'total' prevents 32-bit integer overflow during multiplication
        // before '% MOD'
        total = (_triangle[left_length + right_length][left_length] * left_ways) % MOD;
        total = (total * right_ways) % MOD;

        return total;
    }

    /**
     * Main entry point:
     * Calculates total identical BST sequences and subtracts 1 to exclude the original array.
     */
    [[nodiscard]]
    static int numOfWays(std::vector<int>& _nums)
    {
        return buildBranch(_nums, buildPascalsTriangle(_nums.size())) - 1;
    }
};
