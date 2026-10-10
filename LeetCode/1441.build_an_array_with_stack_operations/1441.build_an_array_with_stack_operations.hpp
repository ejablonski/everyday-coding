#include <ranges>
#include <string>
#include <vector>

/**
 * Learning Journal:
 * - Pattern: Array Traversal / Two Pointers
 * - Aha! Moment: We don't need to re-verify the entire accepted prefix of the stack, nor do we need
 * to store the stack in memory. The target array is strictly increasing, so we only need a single
 * pointer (`idx`) to verify against the current stream number.
 * - Trap: Remember the distinction between Total Space and Auxiliary Space. By removing the
 * temporary stack vector and directly building the answer, the Auxiliary Space drops from O(N) down
 * to O(1).
 */

struct Solution
{

    [[nodiscard]]
    static std::vector<std::string> buildArray(std::vector<int>& _target, int _n)
    {
        std::vector<std::string> operations = {};
        int target_size = _target.size();
        int idx = 0;

        for (const auto n : std::views::iota(1, _n + 1)) {
            operations.emplace_back("Push");

            const auto are_equal = _target[idx] == n;

            if (!are_equal) {
                operations.emplace_back("Pop");
            } else {
                idx++;
            }

            if (are_equal && idx == target_size) {
                break;
            }
        }

        return operations;
    }
};
