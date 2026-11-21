#include "2196.create_binary_tree_from_descriptions.hpp"

#include <catch2/catch_test_macros.hpp>
#include <queue>
#include <vector>

using namespace LC2196;

namespace {

constexpr int kNull = -1;

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

std::vector<int> serializeLevelOrder(const TreeNode* root)
{
    if (root == nullptr) {
        return {};
    }

    std::vector<int> result;
    std::queue<const TreeNode*> pending;
    pending.push(root);

    while (!pending.empty()) {
        const TreeNode* current = pending.front();
        pending.pop();

        if (current == nullptr) {
            result.push_back(kNull);
        } else {
            result.push_back(current->val);
            pending.push(current->left);
            pending.push(current->right);
        }
    }

    while (!result.empty() && result.back() == kNull) {
        result.pop_back();
    }
    return result;
}

} // namespace

TEST_CASE("LeetCode 2196 - Create Binary Tree From Descriptions",
          "[LeetCode][2196][array][hash-table][tree][binary-tree]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]")
    {
        std::vector<std::vector<int>> descriptions = {
            {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
        TreeGuard guard{Solution::createBinaryTree(descriptions)};

        REQUIRE(guard.root != nullptr);
        std::vector<int> expected = {50, 20, 80, 15, 17, 19};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Example 2: descriptions = [[1,2,1],[2,3,0],[3,4,1]]")
    {
        std::vector<std::vector<int>> descriptions = {{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
        TreeGuard guard{Solution::createBinaryTree(descriptions)};

        REQUIRE(guard.root != nullptr);
        std::vector<int> expected = {1, 2, kNull, kNull, 3, 4};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint: single left-child description")
    {
        std::vector<std::vector<int>> descriptions = {{10, 5, 1}};
        TreeGuard guard{Solution::createBinaryTree(descriptions)};

        REQUIRE(guard.root != nullptr);
        std::vector<int> expected = {10, 5};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Minimum constraint: single right-child description")
    {
        std::vector<std::vector<int>> descriptions = {{10, 15, 0}};
        TreeGuard guard{Solution::createBinaryTree(descriptions)};

        REQUIRE(guard.root != nullptr);
        std::vector<int> expected = {10, kNull, 15};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Right-skewed chain provided in bottom-up order")
    {
        std::vector<std::vector<int>> descriptions = {{3, 4, 0}, {2, 3, 0}, {1, 2, 0}};
        TreeGuard guard{Solution::createBinaryTree(descriptions)};

        REQUIRE(guard.root != nullptr);
        std::vector<int> expected = {1, kNull, 2, kNull, 3, kNull, 4};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Left-skewed chain with root defined in the middle of descriptions")
    {
        std::vector<std::vector<int>> descriptions = {{30, 40, 1}, {10, 20, 1}, {20, 30, 1}};
        TreeGuard guard{Solution::createBinaryTree(descriptions)};

        REQUIRE(guard.root != nullptr);
        std::vector<int> expected = {10, 20, kNull, 30, kNull, 40};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }

    SECTION("Boundary node values 1 and 100000")
    {
        std::vector<std::vector<int>> descriptions = {{100000, 1, 1}, {100000, 99999, 0}};
        TreeGuard guard{Solution::createBinaryTree(descriptions)};

        REQUIRE(guard.root != nullptr);
        std::vector<int> expected = {100000, 1, 99999};
        REQUIRE(serializeLevelOrder(guard.root) == expected);
    }
}
