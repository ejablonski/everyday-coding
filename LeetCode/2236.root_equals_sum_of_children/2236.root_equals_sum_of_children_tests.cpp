#include "2236.root_equals_sum_of_children.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace LC2236;

TEST_CASE("LeetCode 2236 - Root Equals Sum of Children", "[LeetCode][2236][tree][binary-tree]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: root = [10,4,6]")
    {
        TreeNode left(4);
        TreeNode right(6);
        TreeNode root(10, &left, &right);
        REQUIRE(Solution::checkTree(&root));
    }

    SECTION("Example 2: root = [5,3,1]")
    {
        TreeNode left(3);
        TreeNode right(1);
        TreeNode root(5, &left, &right);
        REQUIRE_FALSE(Solution::checkTree(&root));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("All zero values: [0,0,0]")
    {
        TreeNode left(0);
        TreeNode right(0);
        TreeNode root(0, &left, &right);
        REQUIRE(Solution::checkTree(&root));
    }

    SECTION("Negative values summing to root: [-10,-4,-6]")
    {
        TreeNode left(-4);
        TreeNode right(-6);
        TreeNode root(-10, &left, &right);
        REQUIRE(Solution::checkTree(&root));
    }

    SECTION("Opposite boundary values canceling to zero: [0,-100,100]")
    {
        TreeNode left(-100);
        TreeNode right(100);
        TreeNode root(0, &left, &right);
        REQUIRE(Solution::checkTree(&root));
    }

    SECTION("Maximum boundary values unequal: [100,100,100]")
    {
        TreeNode left(100);
        TreeNode right(100);
        TreeNode root(100, &left, &right);
        REQUIRE_FALSE(Solution::checkTree(&root));
    }

    SECTION("Minimum boundary off-by-one mismatch: [-100,-50,-49]")
    {
        TreeNode left(-50);
        TreeNode right(-49);
        TreeNode root(-100, &left, &right);
        REQUIRE_FALSE(Solution::checkTree(&root));
    }
}
