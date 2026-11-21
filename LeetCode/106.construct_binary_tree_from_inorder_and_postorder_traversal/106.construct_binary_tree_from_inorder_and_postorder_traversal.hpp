#include <vector>

namespace LC106 {

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
    [[nodiscard]] static TreeNode* buildTree(std::vector<int>& _inorder, std::vector<int>& _postorder) noexcept
    {
        return nullptr;
    }
};

} // namespace LC106
