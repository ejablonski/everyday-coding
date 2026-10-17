#include <vector>

/**
 * Learning Journal — LeetCode 2916: Subarrays Distinct Element Sum of Squares II
 * ==============================================================================
 *
 * 1. WHY O(N^2) HITS TLE & THE SWEEP-LINE PERSPECTIVE SHIFT
 * ---------------------------------------------------------
 * With N <= 10^5, there are N * (N + 1) / 2 ~ 5 * 10^9 subarrays, so checking
 * every (i, j) pair explicitly is far too slow.
 *
 * Instead of fixing the start index and expanding right, we sweep the RIGHT
 * endpoint j from 1 to N (using 1-based indexing) and conceptually maintain an
 * array D[1..j], where D[i] is the number of distinct elements in the subarray
 * nums[i..j].
 *
 * When j advances by 1 and reveals x = nums[j - 1]:
 *   - Let p = last_seen[x] be the previous 1-based index where x appeared
 *     (or p = 0 if x has never appeared before).
 *   - Any subarray starting at i <= p ALREADY contains the earlier copy of x at
 *     index p, so its distinct count D[i] does NOT change.
 *   - Any subarray starting at i in [p + 1, j] has NOT seen x yet, so every
 *     D[i] in the contiguous range [left, right] = [p + 1, j] increases by +1.
 *
 * Example trace on nums = [5, 7, 3, 7]:
 *   j = 1 (x = 5, p = 0): +1 on [1..1] -> D = [1, 0, 0, 0], sum of squares = 1
 *   j = 2 (x = 7, p = 0): +1 on [1..2] -> D = [2, 1, 0, 0], sum of squares = 5
 *   j = 3 (x = 3, p = 0): +1 on [1..3] -> D = [3, 2, 1, 0], sum of squares = 14
 *   j = 4 (x = 7, p = 2): +1 on [3..4] -> D = [3, 2, 2, 1], sum of squares = 18
 *
 * 2. THE ALGEBRAIC SHORTCUT FOR SUM OF SQUARES
 * --------------------------------------------
 * At each step j, we need the sum of squares: S_j = sum_{i=1..j} (D[i])^2.
 * When every D[i] in the range [left, right] increases by +1, each individual
 * square changes according to the binomial identity:
 *
 *   (D[i] + 1)^2 = D[i]^2 + 2 * D[i] + 1
 *
 * Summing this change over all i in [left, right] (where length = right - left + 1):
 *
 *   Delta(S) = sum_{i=left..right} (2 * D[i] + 1)
 *            = 2 * (sum_{i=left..right} D[i]) + length
 *
 * Crucial takeaway: We NEVER need to store or update squares inside our data
 * structure! To know how much the sum of squares grows when D[left..right]
 * increments by +1, we only need the PLAIN sum of D[left..right] prior to the
 * increment.
 *
 * 3. HOW THE BINARY INDEXED TREE (FENWICK TREE) WORKS
 * ---------------------------------------------------
 * A Binary Indexed Tree (BIT) is a flat 1-indexed array `tree[1..N]` where each
 * slot `tree[idx]` stores the sum of a power-of-two block of elements ending at
 * `idx`. The size of the block stored at `tree[idx]` is the largest power of 2
 * that divides `idx`, extracted in two's-complement binary via:
 *
 *   lowest_bit = idx & (-idx)
 *
 *   - Odd indices (1, 3, 5, 7) -> lowest_bit = 1 (stores 1 element)
 *   - Indices 2, 6, 10         -> lowest_bit = 2 (stores 2 elements)
 *   - Indices 4, 12            -> lowest_bit = 4 (stores 4 elements)
 *   - Index 8                  -> lowest_bit = 8 (stores 8 elements)
 *
 *   * Prefix Sum (`queryBit(idx)`): Peel off blocks from right to left by
 *     repeatedly subtracting `lowest_bit` (`idx -= idx & -idx`) in O(log N) jumps.
 *   * Point Update (`addToBit(idx, val)`): Update all enclosing blocks by
 *     repeatedly adding `lowest_bit` (`idx += idx & -idx`) in O(log N) jumps.
 *
 * 4. RANGE-ADD & RANGE-SUM USING TWO BITs (bit1 AND bit2)
 * -------------------------------------------------------
 * A single BIT naturally supports point updates and prefix sums. To support
 * BOTH range additions (+v on [left, right]) and range sum queries on D[1..N],
 * we define a difference array d[1..N] where D[i] = sum_{m=1..i} d[m].
 * Adding +v to D[left..right] only changes two points in d[]:
 *   d[left] += v,   d[right + 1] -= v
 *
 * Now rewrite the prefix sum of D[1..k] in terms of d[]:
 *   prefixSum(k) = sum_{i=1..k} D[i]
 *                = sum_{i=1..k} sum_{m=1..i} d[m]
 *                = sum_{m=1..k} d[m] * (k - m + 1)
 *                = (sum_{m=1..k} d[m]) * k - sum_{m=1..k} d[m] * (m - 1)
 *
 * We maintain those two sums in two separate BITs:
 *   - `bit1` stores d[m]
 *   - `bit2` stores d[m] * (m - 1)
 * Then `prefixSum(k) = queryBit(bit1, k) * k - queryBit(bit2, k)` in O(log N)!
 *
 * 5. COMPLEXITY
 * -------------
 * - Time Complexity: O(N log N) — N steps, each doing a constant number of
 *   O(log N) BIT queries and updates.
 * - Space Complexity: O(N + max(nums)) — two BIT vectors of size N + 2 and a
 *   `last_seen` lookup table.
 */

namespace {
using namespace std;

struct Solution
{
    static const long long MOD = 1000000007;

    // --- Part 1: Basic Single-BIT Operations ---

    /**
     * Point-adds `value` at 1-based position `index` inside a BIT and propagates
     * the change upward to all power-of-two blocks that cover `index`.
     *
     * Hop sequence example for N = 8, starting at index = 3:
     *   index = 3 (lowest_bit = 1) -> updates tree[3], jumps to 3 + 1 = 4
     *   index = 4 (lowest_bit = 4) -> updates tree[4], jumps to 4 + 4 = 8
     *   index = 8 (lowest_bit = 8) -> updates tree[8], jumps to 8 + 8 = 16 > N (stop)
     */
    static void addToBit(vector<long long>& tree, int index, long long value, int N)
    {
        // Normalize `value` into [0, MOD - 1] because rangeAdd passes negative
        // deltas (like `-value`) when canceling the effect past `right + 1`.
        value = (value % MOD + MOD) % MOD;
        while (index <= N) {
            tree[index] = (tree[index] + value) % MOD;
            int lowest_bit = index & (-index);
            index = index + lowest_bit;
        }
    }

    /**
     * Returns the prefix sum of elements [1..index] represented by `tree` in
     * O(log N) hops by accumulating non-overlapping power-of-two blocks.
     *
     * Hop sequence example for index = 7 (binary 0111):
     *   index = 7 (lowest_bit = 1) -> adds tree[7] (covers [7..7]), jumps to 7 - 1 = 6
     *   index = 6 (lowest_bit = 2) -> adds tree[6] (covers [5..6]), jumps to 6 - 2 = 4
     *   index = 4 (lowest_bit = 4) -> adds tree[4] (covers [1..4]), jumps to 4 - 4 = 0 (stop)
     */
    static long long queryBit(const vector<long long>& tree, int index)
    {
        long long total = 0;
        while (index > 0) {
            total = (total + tree[index]) % MOD;
            int lowest_bit = index & (-index);
            index = index - lowest_bit;
        }
        return total;
    }

    // --- Part 2: Range-Add & Range-Sum Using Two BITs ---

    /**
     * Adds `value` to every element in D[left..right] in O(log N) time.
     *
     * In the underlying difference array d[]:
     *   - d[left] increases by +value
     *   - d[right + 1] decreases by -value (ending the range effect after `right`)
     *
     * To keep `prefixSum(k) = sum(d[m]) * k - sum(d[m] * (m - 1))` accurate:
     *   - `bit1` records +value at `left` and -value at `right + 1`
     *   - `bit2` records +value * (left - 1) at `left` and -value * right at `right + 1`
     */
    static void rangeAdd(vector<long long>& bit1, vector<long long>& bit2, int left, int right,
                         long long value, int N)
    {
        addToBit(bit1, left, value, N);
        addToBit(bit1, right + 1, -value, N);

        long long val1 = (value * (left - 1)) % MOD;
        addToBit(bit2, left, val1, N);

        long long val2 = (-value * right) % MOD;
        addToBit(bit2, right + 1, val2, N);
    }

    /**
     * Computes the prefix sum D[1] + D[2] + ... + D[index] in O(log N) time
     * using the identity:
     *   sum_{i=1..index} D[i] = queryBit(bit1, index) * index - queryBit(bit2, index)
     */
    static long long prefixSum(const vector<long long>& bit1, const vector<long long>& bit2,
                               int index)
    {
        long long term1 = (queryBit(bit1, index) * index) % MOD;
        long long term2 = queryBit(bit2, index);
        // Add MOD before second modulo to prevent negative results from subtraction
        return (term1 - term2 + MOD) % MOD;
    }

    /**
     * Computes the contiguous range sum D[left] + D[left + 1] + ... + D[right]
     * by subtracting prefixSum(left - 1) from prefixSum(right).
     */
    static long long rangeSum(const vector<long long>& bit1, const vector<long long>& bit2,
                              int left, int right)
    {
        long long sumRight = prefixSum(bit1, bit2, right);
        long long sumLeft = prefixSum(bit1, bit2, left - 1);
        return (sumRight - sumLeft + MOD) % MOD;
    }

    // --- Part 3: Main Loop for Problem 2916 ---

    static int sumCounts(vector<int>& nums)
    {
        int N = nums.size();

        // 1-based indexing requires size N + 2 to safely handle `right + 1` when right == N
        vector<long long> bit1(N + 2, 0);
        vector<long long> bit2(N + 2, 0);

        // Stores the most recent 1-based index where each value appeared (0 if never seen).
        // Constraints guarantee 1 <= nums[i] <= 10^5.
        vector<int> last_seen(100005, 0);

        // Tracks sum_{i=1..j} (D[i])^2 for the current right endpoint j
        long long current_squares_sum = 0;

        // Accumulates current_squares_sum across all right endpoints j = 1..N
        long long grand_total = 0;

        for (int j = 1; j <= N; ++j) {
            int x = nums[j - 1];

            // Subarrays starting after `last_seen[x]` (from `left` to `right = j`)
            // see `x` as a brand-new distinct element, so their D[i] increases by +1.
            int left = last_seen[x] + 1;
            int right = j;
            long long length = right - left + 1;

            // 1. Query the old plain sum of D[left..right] BEFORE adding +1
            long long plain_sum = rangeSum(bit1, bit2, left, right);

            // 2. Apply (c + 1)^2 - c^2 = 2c + 1 across the range [left..right]:
            //    Total increase in sum of squares = 2 * sum(D[left..right]) + length
            long long increase = (2 * plain_sum + length) % MOD;
            current_squares_sum = (current_squares_sum + increase) % MOD;
            grand_total = (grand_total + current_squares_sum) % MOD;

            // 3. Increment D[left..right] by +1 in the BITs and record the new position of `x`
            rangeAdd(bit1, bit2, left, right, 1, N);
            last_seen[x] = j;
        }

        return grand_total;
    }
};
} // namespace
