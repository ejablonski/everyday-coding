#include "932.beautiful_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <vector>

using namespace LC932;

namespace {
[[nodiscard]] bool isBeautifulArray(const std::vector<int>& nums, int n)
{
    if (n < 1 || nums.size() != static_cast<std::size_t>(n)) {
        return false;
    }

    std::vector<int> pos(static_cast<std::size_t>(n) + 1, -1);
    for (int i = 0; i < n; ++i) {
        int val = nums[static_cast<std::size_t>(i)];
        if (val < 1 || val > n || pos[static_cast<std::size_t>(val)] != -1) {
            return false;
        }
        pos[static_cast<std::size_t>(val)] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            int sum = nums[static_cast<std::size_t>(i)] + nums[static_cast<std::size_t>(j)];
            if (sum % 2 == 0) {
                int mid = sum / 2;
                int k = pos[static_cast<std::size_t>(mid)];
                if (i < k && k < j) {
                    return false;
                }
            }
        }
    }

    return true;
}
} // namespace

TEST_CASE("LeetCode 932 - Beautiful Array", "[LeetCode][932][array][math][divide-and-conquer]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 4")
    {
        std::vector<int> result = Solution::beautifulArray(4);
        REQUIRE(isBeautifulArray(result, 4));
    }

    SECTION("Example 2: n = 5")
    {
        std::vector<int> result = Solution::beautifulArray(5);
        REQUIRE(isBeautifulArray(result, 5));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint value: n = 1")
    {
        std::vector<int> result = Solution::beautifulArray(1);
        REQUIRE(result == std::vector<int>{1});
    }

    SECTION("Two elements: n = 2")
    {
        std::vector<int> result = Solution::beautifulArray(2);
        REQUIRE(isBeautifulArray(result, 2));
    }

    SECTION("Smallest non-trivial size with arithmetic triple: n = 3")
    {
        std::vector<int> result = Solution::beautifulArray(3);
        REQUIRE(isBeautifulArray(result, 3));
    }

    SECTION("Power of two: n = 8")
    {
        std::vector<int> result = Solution::beautifulArray(8);
        REQUIRE(isBeautifulArray(result, 8));
    }

    SECTION("Odd composite length: n = 15")
    {
        std::vector<int> result = Solution::beautifulArray(15);
        REQUIRE(isBeautifulArray(result, 15));
    }

    SECTION("Maximum constraint value: n = 1000")
    {
        std::vector<int> result = Solution::beautifulArray(1000);
        REQUIRE(isBeautifulArray(result, 1000));
    }
}
