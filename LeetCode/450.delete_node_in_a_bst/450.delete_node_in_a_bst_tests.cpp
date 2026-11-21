#include "450.delete_node_in_a_bst.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <optional>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace LC450;

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

struct TreeOwner
{
    TreeNode* root = nullptr;

    ~TreeOwner()
    {
        freeTree(root);
    }
};

void inorderDfs(const TreeNode* node, std::vector<int>& out)
{
    if (node == nullptr) {
        return;
    }
    inorderDfs(node->left, out);
    out.push_back(node->val);
    inorderDfs(node->right, out);
}

// A binary tree with unique values is a valid BST containing the exact expected
// values if and only if its inorder traversal equals the strictly sorted list.
std::vector<int> collectInorder(const TreeNode* root)
{
    std::vector<int> values;
    inorderDfs(root, values);
    return values;
}

} // namespace

TEST_CASE("LeetCode 450 - Delete Node in a BST",
          "[LeetCode][450][tree][binary-search-tree][binary-tree]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: delete node with two children (key = 3)")
    {
        TreeOwner owner{buildTree({5, 3, 6, 2, 4, std::nullopt, 7})};
        TreeNode* result = Solution::deleteNode(owner.root, 3);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{2, 4, 5, 6, 7});
    }

    SECTION("Example 2: key not found in tree (key = 0)")
    {
        TreeOwner owner{buildTree({5, 3, 6, 2, 4, std::nullopt, 7})};
        TreeNode* result = Solution::deleteNode(owner.root, 0);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{2, 3, 4, 5, 6, 7});
    }

    SECTION("Example 3: empty tree")
    {
        TreeNode* result = Solution::deleteNode(nullptr, 0);
        TreeOwner owner{result};

        REQUIRE(result == nullptr);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Delete the only node in a single-node tree")
    {
        TreeNode* root = buildTree({5});
        TreeNode* result = Solution::deleteNode(root, 5);
        TreeOwner owner{result};

        REQUIRE(result == nullptr);
    }

    SECTION("Single-node tree when key does not match")
    {
        TreeOwner owner{buildTree({5})};
        TreeNode* result = Solution::deleteNode(owner.root, -5);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{5});
    }

    SECTION("Delete root node with two children")
    {
        TreeOwner owner{buildTree({5, 3, 6, 2, 4, std::nullopt, 7})};
        TreeNode* result = Solution::deleteNode(owner.root, 5);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{2, 3, 4, 6, 7});
    }

    SECTION("Delete a leaf node")
    {
        TreeOwner owner{buildTree({5, 3, 6, 2, 4, std::nullopt, 7})};
        TreeNode* result = Solution::deleteNode(owner.root, 7);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{2, 3, 4, 5, 6});
    }

    SECTION("Delete a node with only a right child")
    {
        TreeOwner owner{buildTree({5, 3, 6, 2, 4, std::nullopt, 7})};
        TreeNode* result = Solution::deleteNode(owner.root, 6);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{2, 3, 4, 5, 7});
    }

    SECTION("Delete a node with only a left child at value constraint bounds")
    {
        TreeOwner owner{buildTree({0, -50'000, 100'000, -100'000})};
        TreeNode* result = Solution::deleteNode(owner.root, -50'000);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{-100'000, 0, 100'000});
    }
}
