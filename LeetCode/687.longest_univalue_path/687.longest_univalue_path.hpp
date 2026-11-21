namespace LC687 {

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
    [[nodiscard]] static int longestUnivaluePath(TreeNode* _root) noexcept
    {
        return 0;
    }
};

} // namespace LC687
