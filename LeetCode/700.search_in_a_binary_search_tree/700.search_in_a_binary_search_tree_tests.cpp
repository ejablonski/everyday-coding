#include "700.search_in_a_binary_search_tree.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <optional>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace LC700;

namespace {

TreeNode* buildTree(const std::vector<std::optional<int>>& levelOrder)
{
    if (levelOrder.empty() || !levelOrder[0].has_value()) {
        return nullptr;
    }

    auto* root = new TreeNode(*levelOrder[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    std::size_t idx = 1;
    while (!q.empty() && idx < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (idx < levelOrder.size() && levelOrder[idx].has_value()) {
            current->left = new TreeNode(*levelOrder[idx]);
            q.push(current->left);
        }
        ++idx;

        if (idx < levelOrder.size() && levelOrder[idx].has_value()) {
            current->right = new TreeNode(*levelOrder[idx]);
            q.push(current->right);
        }
        ++idx;
    }

    return root;
}

void freeTree(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    std::vector<TreeNode*> stack{root};
    std::unordered_set<TreeNode*> visited{root};
    while (!stack.empty()) {
        TreeNode* node = stack.back();
        stack.pop_back();
        if (node->left != nullptr && visited.insert(node->left).second) {
            stack.push_back(node->left);
        }
        if (node->right != nullptr && visited.insert(node->right).second) {
            stack.push_back(node->right);
        }
    }

    for (TreeNode* node : visited) {
        delete node;
    }
}

struct TreeGuard
{
    TreeNode* root = nullptr;

    ~TreeGuard()
    {
        freeTree(root);
    }
};

std::vector<std::optional<int>> toLevelOrder(const TreeNode* root)
{
    if (root == nullptr) {
        return {};
    }

    std::vector<std::optional<int>> result;
    std::queue<const TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) {
            result.push_back(std::nullopt);
        } else {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
    }

    while (!result.empty() && !result.back().has_value()) {
        result.pop_back();
    }
    return result;
}

} // namespace

TEST_CASE("LeetCode 700 - Search in a Binary Search Tree",
          "[LeetCode][700][tree][binary-search-tree][binary-tree]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: root = [4,2,7,1,3], val = 2")
    {
        TreeGuard tree{buildTree({4, 2, 7, 1, 3})};
        TreeNode* result = Solution::searchBST(tree.root, 2);

        REQUIRE(result != nullptr);
        REQUIRE(toLevelOrder(result) == std::vector<std::optional<int>>{2, 1, 3});
    }

    SECTION("Example 2: root = [4,2,7,1,3], val = 5 (not found)")
    {
        TreeGuard tree{buildTree({4, 2, 7, 1, 3})};
        TreeNode* result = Solution::searchBST(tree.root, 5);

        REQUIRE(result == nullptr);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single-node tree where target matches minimum value")
    {
        TreeGuard tree{buildTree({1})};
        TreeNode* result = Solution::searchBST(tree.root, 1);

        REQUIRE(result != nullptr);
        REQUIRE(toLevelOrder(result) == std::vector<std::optional<int>>{1});
    }

    SECTION("Single-node tree where target does not match")
    {
        TreeGuard tree{buildTree({1})};
        TreeNode* result = Solution::searchBST(tree.root, 10'000'000);

        REQUIRE(result == nullptr);
    }

    SECTION("Target equals root value returns entire tree")
    {
        TreeGuard tree{buildTree({4, 2, 7, 1, 3})};
        TreeNode* result = Solution::searchBST(tree.root, 4);

        REQUIRE(result != nullptr);
        REQUIRE(toLevelOrder(result) == std::vector<std::optional<int>>{4, 2, 7, 1, 3});
    }

    SECTION("Deep leaf in left-skewed BST")
    {
        TreeGuard tree{buildTree({50, 40, std::nullopt, 30, std::nullopt, 20, std::nullopt, 10})};
        TreeNode* result = Solution::searchBST(tree.root, 10);

        REQUIRE(result != nullptr);
        REQUIRE(toLevelOrder(result) == std::vector<std::optional<int>>{10});
    }

    SECTION("Maximum value constraint (10^7) in right-skewed BST")
    {
        TreeGuard tree{buildTree({1, std::nullopt, 5'000'000, std::nullopt, 10'000'000})};
        TreeNode* result = Solution::searchBST(tree.root, 10'000'000);

        REQUIRE(result != nullptr);
        REQUIRE(toLevelOrder(result) == std::vector<std::optional<int>>{10'000'000});
    }

    SECTION("Missing target strictly between existing BST values")
    {
        TreeGuard tree{buildTree({10, 5, 15, 2, 7, 12, 20})};
        TreeNode* result = Solution::searchBST(tree.root, 6);

        REQUIRE(result == nullptr);
    }
}
