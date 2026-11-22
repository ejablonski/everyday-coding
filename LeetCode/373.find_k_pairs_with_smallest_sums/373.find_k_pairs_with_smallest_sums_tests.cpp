#include "373.find_k_pairs_with_smallest_sums.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

using namespace LC373;

TEST_CASE("LeetCode 373 - Find K Pairs with Smallest Sums",
          "[LeetCode][373][array][heap][priority-queue]")
{
    using Catch::Matchers::UnorderedEquals;
    using Pairs = std::vector<std::vector<int>>;

    // --- Official Markdown Examples ---
    SECTION("Example 1: nums1 = [1, 7, 11], nums2 = [2, 4, 6], k = 3")
    {
        std::vector<int> nums1{1, 7, 11};
        std::vector<int> nums2{2, 4, 6};
        const Pairs expected{{1, 2}, {1, 4}, {1, 6}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 3), UnorderedEquals(expected));
    }

    SECTION("Example 2: nums1 = [1, 1, 2], nums2 = [1, 2, 3], k = 2")
    {
        std::vector<int> nums1{1, 1, 2};
        std::vector<int> nums2{1, 2, 3};
        const Pairs expected{{1, 1}, {1, 1}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 2), UnorderedEquals(expected));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single-element arrays with k = 1")
    {
        std::vector<int> nums1{5};
        std::vector<int> nums2{3};
        const Pairs expected{{5, 3}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 1), UnorderedEquals(expected));
    }

    SECTION("All possible pairs requested: k equals nums1.size() * nums2.size()")
    {
        std::vector<int> nums1{1, 2};
        std::vector<int> nums2{3, 4};
        const Pairs expected{{1, 3}, {1, 4}, {2, 3}, {2, 4}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 4), UnorderedEquals(expected));
    }

    SECTION("Interleaved smallest sums across both arrays with tied sums")
    {
        std::vector<int> nums1{1, 2, 4};
        std::vector<int> nums2{1, 3, 5};
        const Pairs expected{{1, 1}, {2, 1}, {1, 3}, {2, 3}, {4, 1}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 5), UnorderedEquals(expected));
    }

    SECTION("Duplicate elements across both arrays")
    {
        std::vector<int> nums1{2, 2, 2};
        std::vector<int> nums2{3, 3};
        const Pairs expected{{2, 3}, {2, 3}, {2, 3}, {2, 3}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 4), UnorderedEquals(expected));
    }

    SECTION("Negative and mixed-sign values")
    {
        std::vector<int> nums1{-10, -5, 2};
        std::vector<int> nums2{-3, 0, 4};
        const Pairs expected{{-10, -3}, {-10, 0}, {-5, -3}, {-10, 4}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 4), UnorderedEquals(expected));
    }

    SECTION("Asymmetric lengths: single-element nums1 with larger nums2")
    {
        std::vector<int> nums1{1};
        std::vector<int> nums2{2, 5, 8, 12};
        const Pairs expected{{1, 2}, {1, 5}, {1, 8}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 3), UnorderedEquals(expected));
    }

    SECTION("Asymmetric lengths: larger nums1 with single-element nums2")
    {
        std::vector<int> nums1{2, 5, 8, 12};
        std::vector<int> nums2{1};
        const Pairs expected{{2, 1}, {5, 1}, {8, 1}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 3), UnorderedEquals(expected));
    }

    SECTION("Extreme boundary values: -10^9 and 10^9")
    {
        std::vector<int> nums1{-1000000000, 1000000000};
        std::vector<int> nums2{-1000000000, 1000000000};
        const Pairs expected{
            {-1000000000, -1000000000}, {-1000000000, 1000000000}, {1000000000, -1000000000}};
        REQUIRE_THAT(Solution::kSmallestPairs(nums1, nums2, 3), UnorderedEquals(expected));
    }
}
