#include "701.insert_into_a_binary_search_tree.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <optional>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace LC701;

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

TEST_CASE("LeetCode 701 - Insert into a Binary Search Tree",
          "[LeetCode][701][tree][binary-search-tree][binary-tree]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: root = [4,2,7,1,3], val = 5")
    {
        TreeOwner owner{buildTree({4, 2, 7, 1, 3})};
        TreeNode* result = Solution::insertIntoBST(owner.root, 5);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{1, 2, 3, 4, 5, 7});
    }

    SECTION("Example 2: root = [40,20,60,10,30,50,70], val = 25")
    {
        TreeOwner owner{buildTree({40, 20, 60, 10, 30, 50, 70})};
        TreeNode* result = Solution::insertIntoBST(owner.root, 25);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{10, 20, 25, 30, 40, 50, 60, 70});
    }

    SECTION("Example 3: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5")
    {
        TreeOwner owner{buildTree({4, 2, 7, 1, 3, std::nullopt, std::nullopt, std::nullopt,
                                   std::nullopt, std::nullopt, std::nullopt})};
        TreeNode* result = Solution::insertIntoBST(owner.root, 5);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{1, 2, 3, 4, 5, 7});
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Empty tree (minimum 0 nodes)")
    {
        TreeOwner owner{nullptr};
        TreeNode* result = Solution::insertIntoBST(owner.root, 42);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{42});
    }

    SECTION("Single-node tree inserting smaller negative value")
    {
        TreeOwner owner{buildTree({5})};
        TreeNode* result = Solution::insertIntoBST(owner.root, -5);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{-5, 5});
    }

    SECTION("Insert new global minimum at lower constraint bound (-10^8)")
    {
        TreeOwner owner{buildTree({0, -10, 10})};
        TreeNode* result = Solution::insertIntoBST(owner.root, -100'000'000);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{-100'000'000, -10, 0, 10});
    }

    SECTION("Insert new global maximum at upper constraint bound (10^8)")
    {
        TreeOwner owner{buildTree({0, -10, 10})};
        TreeNode* result = Solution::insertIntoBST(owner.root, 100'000'000);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{-10, 0, 10, 100'000'000});
    }

    SECTION("Insert interior value into left-skewed BST")
    {
        TreeOwner owner{buildTree({50, 40, std::nullopt, 30, std::nullopt, 20})};
        TreeNode* result = Solution::insertIntoBST(owner.root, 35);
        if (result != nullptr) {
            owner.root = result;
        }

        REQUIRE(result != nullptr);
        REQUIRE(collectInorder(result) == std::vector<int>{20, 30, 35, 40, 50});
    }
}
