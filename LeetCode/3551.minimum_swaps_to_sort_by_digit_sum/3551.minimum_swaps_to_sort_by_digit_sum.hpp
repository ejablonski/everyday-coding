#include <algorithm>
#include <vector>

/**
 * Learning Journal — LeetCode 3551: Minimum Swaps to Sort by Digit Sum
 * ====================================================================
 *
 * 1. PATTERN: PERMUTATION CYCLE DECOMPOSITION
 * -------------------------------------------
 * Finding the minimum number of swaps to transform an array into a sorted order
 * is a classic graph theory problem.
 *
 * Any permutation of N elements can be uniquely decomposed into a set of disjoint,
 * non-overlapping CYCLES.
 * - Each index 0..N-1 represents a slot in the array.
 * - An element currently at index `i` belongs at target sorted index `target_i`.
 * - Drawing a directed edge `i -> target_i` creates a functional directed graph
 *   where every node has indegree = 1 and outdegree = 1.
 * - Such a graph ALWAYS decomposes into independent closed cycles (loops).
 *
 * 2. THE L - 1 THEOREM (WHY A CYCLE OF LENGTH L TAKES L - 1 SWAPS)
 * ----------------------------------------------------------------
 * Consider a cycle of length L:
 * - A cycle of length L = 1 (element already at its target index): 1 - 1 = 0 swaps.
 * - A cycle of length L = 2 (e.g. 0 <-> 1): Swapping index 0 with index 1 places
 *   BOTH elements into their correct homes simultaneously! Takes 2 - 1 = 1 swap.
 * - A cycle of length L = 3 (e.g. 0 -> 1 -> 2 -> 0): Swapping index 0 with index 1
 *   places one element in its home, reducing the remaining loop to length 2.
 *   The next swap resolves the remaining 2 elements. Total: 3 - 1 = 2 swaps.
 *
 * In general: Every single swap between two elements in a cycle can place at least
 * one element into its final destination while shrinking the remaining cycle by 1.
 * Therefore, resolving a cycle of length L ALWAYS requires exactly (L - 1) swaps.
 *
 * Total Minimum Swaps = sum_{cycles} (L_k - 1) = N - (number of cycles).
 *
 * 3. STEP-BY-STEP STRATEGY
 * ------------------------
 * 1. Compute digit sums and store each item as (original_index, digit_sum).
 * 2. Sort according to problem rules: primary key is digit sum ascending,
 *    secondary key is original numerical value ascending.
 * 3. After sorting, `idx_of_sums[target_pos].first` tells us which original index
 *    belongs at `target_pos`.
 * 4. Use a `swapped` (visited) boolean array to trace each cycle from start to end,
 *    accumulating `jumps - 1` swaps for each unvisited cycle.
 *
 * 4. COMPLEXITY
 * -------------
 * - Time Complexity: O(N log N)
 *   - Computing digit sums: O(N * log10(max(nums))) = O(N) since nums[i] <= 10^9.
 *   - Sorting: O(N log N) for sorting N pairs.
 *   - Cycle Traversal: O(N) because every index is visited exactly once across
 *     the entire outer loop.
 * - Space Complexity: O(N)
 *   - O(N) for `idx_of_sums` and the `swapped` boolean array.
 */

struct Solution
{
    /**
     * Helper: Computes the sum of base-10 digits of an integer.
     * Operates in O(log10(n)) time (at most 10 iterations for n <= 10^9).
     */
    [[nodiscard]]
    static int digitSum(int _n)
    {
        int sum = 0;
        while (_n > 0) {
            sum += _n % 10;
            _n /= 10;
        }
        return sum;
    }

    [[nodiscard]]
    static int minSwaps(std::vector<int>& _nums)
    {
        // --------------------------------------------------------------------
        // Step 1: Pair each original index with its computed digit sum.
        // idx_of_sums[i] = (original_index, digit_sum)
        // --------------------------------------------------------------------
        std::vector<std::pair<int, int>> idx_of_sums{};
        idx_of_sums.reserve(_nums.size());

        for (int i = 0; i < _nums.size(); i++) {
            idx_of_sums.emplace_back(std::make_pair(i, digitSum(_nums[i])));
        }

        // --------------------------------------------------------------------
        // Step 2: Sort into the target order.
        // - Primary criterion: digit sum ascending (a.second < b.second).
        // - Tie-breaker: original value ascending (_nums[a.first] < _nums[b.first]).
        //
        // After sorting:
        // Index `k` in `idx_of_sums` represents the TARGET position.
        // `idx_of_sums[k].first` is the ORIGINAL index of the number that belongs at `k`.
        // --------------------------------------------------------------------
        std::ranges::sort(idx_of_sums, [_nums](std::pair<int, int> a, std::pair<int, int> b) {
            return a.second != b.second ? a.second < b.second : _nums[a.first] < _nums[b.first];
        });

        // Tracks which indices have already been processed into a resolved cycle.
        std::vector<bool> swapped(_nums.size(), false);
        int swaps = 0;

        // --------------------------------------------------------------------
        // Step 3: Decompose the permutation into disjoint cycles.
        // --------------------------------------------------------------------
        for (int i = 0; i < swapped.size(); i++) {
            // If already visited, or already in its correct position (cycle of length 1),
            // no swaps are needed for this element.
            if (swapped[i] || idx_of_sums[i].first == i) {
                continue;
            }

            int jumps = 0;
            int curr = i;

            // Follow the chain of directed edges: jump from index to target index
            // until returning to the starting index `i`, marking each index visited.
            do {
                swapped[curr] = true;
                curr = idx_of_sums[curr].first;
                jumps++;
            } while (i != curr);

            // A cycle of length `jumps` is resolved in exactly (jumps - 1) swaps.
            swaps += jumps - 1;
        }

        return swaps;
    }
};
