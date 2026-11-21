namespace LC701 {

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
    [[nodiscard]] static TreeNode* insertIntoBST(TreeNode* _root, int _val) noexcept
    {
        return nullptr;
    }
};

} // namespace LC701
