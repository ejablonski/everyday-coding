#include "106.construct_binary_tree_from_inorder_and_postorder_traversal.hpp"

#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <queue>
#include <vector>

using namespace LC106;

namespace {

void freeTree(TreeNode* _node) noexcept
{
    if (_node == nullptr) {
        return;
    }
    freeTree(_node->left);
    freeTree(_node->right);
    delete _node;
}

struct TreeGuard
{
    TreeNode* root;
    ~TreeGuard() { freeTree(root); }
};

std::vector<std::optional<int>> serializeLevelOrder(const TreeNode* _root)
{
    std::vector<std::optional<int>> result;
    if (_root == nullptr) {
        return result;
    }

    std::queue<const TreeNode*> q;
    q.push(_root);
    while (!q.empty()) {
        const TreeNode* current = q.front();
        q.pop();
        if (current != nullptr) {
            result.push_back(current->val);
            q.push(current->left);
            q.push(current->right);
        } else {
            result.push_back(std::nullopt);
        }
    }

    while (!result.empty() && !result.back().has_value()) {
        result.pop_back();
    }

    return result;
}

} // namespace

TEST_CASE("LeetCode 106 - Construct Binary Tree from Inorder and Postorder Traversal",
          "[LeetCode][106][array][hash-table][divide-and-conquer][tree][binary-tree]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]")
    {
        std::vector<int> inorder = {9, 3, 15, 20, 7};
        std::vector<int> postorder = {9, 15, 7, 20, 3};
        TreeGuard guard{Solution::buildTree(inorder, postorder)};
        REQUIRE(guard.root != nullptr);
        std::vector<std::optional<int>> expected = {
            3, 9, 20, std::nullopt, std::nullopt, 15, 7};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Example 2: inorder = [-1], postorder = [-1]")
    {
        std::vector<int> inorder = {-1};
        std::vector<int> postorder = {-1};
        TreeGuard guard{Solution::buildTree(inorder, postorder)};
        REQUIRE(guard.root != nullptr);
        std::vector<std::optional<int>> expected = {-1};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Left-skewed tree")
    {
        std::vector<int> inorder = {1, 2, 3, 4};
        std::vector<int> postorder = {1, 2, 3, 4};
        TreeGuard guard{Solution::buildTree(inorder, postorder)};
        REQUIRE(guard.root != nullptr);
        std::vector<std::optional<int>> expected = {
            4, 3, std::nullopt, 2, std::nullopt, 1};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Right-skewed tree")
    {
        std::vector<int> inorder = {1, 2, 3, 4};
        std::vector<int> postorder = {4, 3, 2, 1};
        TreeGuard guard{Solution::buildTree(inorder, postorder)};
        REQUIRE(guard.root != nullptr);
        std::vector<std::optional<int>> expected = {
            1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Complete binary tree with boundary values (-3000 to 3000)")
    {
        std::vector<int> inorder = {-2000, -3000, -1000, 0, 1000, 3000, 2000};
        std::vector<int> postorder = {-2000, -1000, -3000, 1000, 2000, 3000, 0};
        TreeGuard guard{Solution::buildTree(inorder, postorder)};
        REQUIRE(guard.root != nullptr);
        std::vector<std::optional<int>> expected = {
            0, -3000, 3000, -2000, -1000, 1000, 2000};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Zig-zag tree (alternating left and right children)")
    {
        std::vector<int> inorder = {5, 6, 8, 10};
        std::vector<int> postorder = {6, 8, 5, 10};
        TreeGuard guard{Solution::buildTree(inorder, postorder)};
        REQUIRE(guard.root != nullptr);
        std::vector<std::optional<int>> expected = {
            10, 5, std::nullopt, std::nullopt, 8, 6};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Two-node tree with only left child")
    {
        std::vector<int> inorder = {2, 1};
        std::vector<int> postorder = {2, 1};
        TreeGuard guard{Solution::buildTree(inorder, postorder)};
        REQUIRE(guard.root != nullptr);
        std::vector<std::optional<int>> expected = {1, 2};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Two-node tree with only right child")
    {
        std::vector<int> inorder = {1, 2};
        std::vector<int> postorder = {2, 1};
        TreeGuard guard{Solution::buildTree(inorder, postorder)};
        REQUIRE(guard.root != nullptr);
        std::vector<std::optional<int>> expected = {1, std::nullopt, 2};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }
}
