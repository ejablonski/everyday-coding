#include "687.longest_univalue_path.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <limits>
#include <queue>
#include <vector>

using namespace LC687;

namespace {

constexpr int kNull = std::numeric_limits<int>::min();

void destroyTree(TreeNode* root) noexcept
{
    if (root == nullptr) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

struct TreeGuard
{
    TreeNode* root;
    ~TreeGuard() noexcept
    {
        destroyTree(root);
    }
};

TreeNode* buildTree(const std::vector<int>& levelOrder)
{
    if (levelOrder.empty() || levelOrder[0] == kNull) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(levelOrder[0]);
    std::queue<TreeNode*> pending;
    pending.push(root);

    std::size_t idx = 1;
    while (!pending.empty() && idx < levelOrder.size()) {
        TreeNode* current = pending.front();
        pending.pop();

        if (idx < levelOrder.size() && levelOrder[idx] != kNull) {
            current->left = new TreeNode(levelOrder[idx]);
            pending.push(current->left);
        }
        ++idx;

        if (idx < levelOrder.size() && levelOrder[idx] != kNull) {
            current->right = new TreeNode(levelOrder[idx]);
            pending.push(current->right);
        }
        ++idx;
    }
    return root;
}

} // namespace

TEST_CASE("LeetCode 687 - Longest Univalue Path",
          "[LeetCode][687][tree][depth-first-search][binary-tree][dp-on-trees]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: root = [5,4,5,1,1,null,5]")
    {
        TreeGuard guard{buildTree({5, 4, 5, 1, 1, kNull, 5})};
        REQUIRE(Solution::longestUnivaluePath(guard.root) == 2);
    }

    SECTION("Example 2: root = [1,4,5,4,4,null,5]")
    {
        TreeGuard guard{buildTree({1, 4, 5, 4, 4, kNull, 5})};
        REQUIRE(Solution::longestUnivaluePath(guard.root) == 2);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint: empty tree (nullptr)")
    {
        REQUIRE(Solution::longestUnivaluePath(nullptr) == 0);
    }

    SECTION("Single node tree has path length 0")
    {
        TreeGuard guard{buildTree({7})};
        REQUIRE(Solution::longestUnivaluePath(guard.root) == 0);
    }

    SECTION("All distinct node values yield 0")
    {
        TreeGuard guard{buildTree({1, 2, 3, 4, 5})};
        REQUIRE(Solution::longestUnivaluePath(guard.root) == 0);
    }

    SECTION("All nodes share minimum boundary value -1000 in full binary tree")
    {
        TreeGuard guard{buildTree({-1000, -1000, -1000, -1000, -1000, -1000, -1000})};
        REQUIRE(Solution::longestUnivaluePath(guard.root) == 4);
    }

    SECTION("Longest path passes through root with maximum boundary value 1000")
    {
        TreeGuard guard{buildTree({1000, 1000, 1000, 1000, kNull, kNull, 1000})};
        REQUIRE(Solution::longestUnivaluePath(guard.root) == 4);
    }

    SECTION("Longest inverted-V path lies strictly inside a non-root subtree")
    {
        TreeGuard guard{buildTree({2, 1, 2, 1, 1, kNull, kNull, 1, kNull, kNull, 1})};
        REQUIRE(Solution::longestUnivaluePath(guard.root) == 4);
    }
}
