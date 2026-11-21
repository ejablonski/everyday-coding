#include "77.combinations.hpp"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC77;

namespace {

std::vector<std::vector<int>> normalizeCombinations(std::vector<std::vector<int>> combos)
{
    for (auto& combo : combos) {
        std::sort(combo.begin(), combo.end());
    }
    std::sort(combos.begin(), combos.end());
    return combos;
}

} // namespace

TEST_CASE("LeetCode 77 - Combinations", "[LeetCode][77][backtracking]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 4, k = 2")
    {
        std::vector<std::vector<int>> expected = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
        REQUIRE(normalizeCombinations(Solution::combine(4, 2)) == normalizeCombinations(expected));
    }

    SECTION("Example 2: n = 1, k = 1")
    {
        std::vector<std::vector<int>> expected = {{1}};
        REQUIRE(normalizeCombinations(Solution::combine(1, 1)) == normalizeCombinations(expected));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum k = 1 with multiple choices: n = 4, k = 1")
    {
        std::vector<std::vector<int>> expected = {{1}, {2}, {3}, {4}};
        REQUIRE(normalizeCombinations(Solution::combine(4, 1)) == normalizeCombinations(expected));
    }

    SECTION("Full selection k = n: n = 5, k = 5")
    {
        std::vector<std::vector<int>> expected = {{1, 2, 3, 4, 5}};
        REQUIRE(normalizeCombinations(Solution::combine(5, 5)) == normalizeCombinations(expected));
    }

    SECTION("Choose n - 1 elements: n = 4, k = 3")
    {
        std::vector<std::vector<int>> expected = {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}};
        REQUIRE(normalizeCombinations(Solution::combine(4, 3)) == normalizeCombinations(expected));
    }

    SECTION("Symmetric middle binomial coefficient: n = 5, k = 3")
    {
        std::vector<std::vector<int>> expected = {{1, 2, 3}, {1, 2, 4}, {1, 2, 5}, {1, 3, 4},
                                                  {1, 3, 5}, {1, 4, 5}, {2, 3, 4}, {2, 3, 5},
                                                  {2, 4, 5}, {3, 4, 5}};
        REQUIRE(normalizeCombinations(Solution::combine(5, 3)) == normalizeCombinations(expected));
    }

    SECTION("Maximum constraint boundary: n = 20, k = 19")
    {
        std::vector<std::vector<int>> expected;
        for (int omitted = 1; omitted <= 20; ++omitted) {
            std::vector<int> combo;
            combo.reserve(19);
            for (int v = 1; v <= 20; ++v) {
                if (v != omitted) {
                    combo.push_back(v);
                }
            }
            expected.push_back(combo);
        }
        REQUIRE(normalizeCombinations(Solution::combine(20, 19)) ==
                normalizeCombinations(expected));
    }
}
