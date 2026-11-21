namespace LC83 {

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _x) : val(_x), next(nullptr) {}
    ListNode(int _x, ListNode* _next) : val(_x), next(_next) {}
};

struct Solution
{
    [[nodiscard]] static ListNode* deleteDuplicates(ListNode* _head) noexcept
    {
        return nullptr;
    }
};

} // namespace LC83
