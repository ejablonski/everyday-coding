namespace LC138 {

class Node
{
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

struct Solution
{
    [[nodiscard]] static Node* copyRandomList(Node* _head) noexcept
    {
        return nullptr;
    }
};

} // namespace LC138
