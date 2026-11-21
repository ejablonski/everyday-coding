#include <vector>

namespace LC2196 {

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _x) : val(_x), left(nullptr), right(nullptr) {}
    TreeNode(int _x, TreeNode* _left, TreeNode* _right) : val(_x), left(_left), right(_right) {}
};

struct Solution
{
    [[nodiscard]] static TreeNode* createBinaryTree(std::vector<std::vector<int>>& _descriptions) noexcept
    {
        return nullptr;
    }
};

} // namespace LC2196
