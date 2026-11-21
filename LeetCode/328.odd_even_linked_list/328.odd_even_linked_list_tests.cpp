#include "328.odd_even_linked_list.hpp"

#include <catch2/catch_test_macros.hpp>
#include <unordered_set>
#include <vector>

using namespace LC328;

namespace {
struct ListResult
{
    bool isNull = false;
    bool hasCycle = false;
    std::vector<int> values;
};

ListNode* buildList(const std::vector<int>& values, std::vector<ListNode*>& allocated)
{
    allocated.clear();
    allocated.reserve(values.size());

    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : values) {
        auto* node = new ListNode(val);
        allocated.push_back(node);
        tail->next = node;
        tail = node;
    }
    return dummy.next;
}

ListResult extractAndFree(ListNode* result, const std::vector<ListNode*>& allocated)
{
    ListResult info{};
    info.isNull = (result == nullptr);

    std::unordered_set<ListNode*> visited;
    ListNode* curr = result;
    while (curr != nullptr) {
        if (!visited.insert(curr).second) {
            info.hasCycle = true;
            break;
        }
        info.values.push_back(curr->val);
        curr = curr->next;
    }

    std::unordered_set<ListNode*> toDelete(allocated.begin(), allocated.end());
    toDelete.insert(visited.begin(), visited.end());
    for (ListNode* node : toDelete) {
        delete node;
    }

    return info;
}
} // namespace

TEST_CASE("LeetCode 328 - Odd Even Linked List", "[LeetCode][328][linked-list]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: head = [1, 2, 3, 4, 5]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({1, 2, 3, 4, 5}, allocated);
        ListNode* result = Solution::oddEvenList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{1, 3, 5, 2, 4});
    }

    SECTION("Example 2: head = [2, 1, 3, 5, 6, 4, 7]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({2, 1, 3, 5, 6, 4, 7}, allocated);
        ListNode* result = Solution::oddEvenList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{2, 3, 6, 7, 1, 5, 4});
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Empty list: head = []")
    {
        ListNode* result = Solution::oddEvenList(nullptr);
        ListResult info = extractAndFree(result, {});

        REQUIRE(info.isNull);
        REQUIRE(info.values.empty());
    }

    SECTION("Single node: head = [7]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({7}, allocated);
        ListNode* result = Solution::oddEvenList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{7});
    }

    SECTION("Two nodes: head = [10, 20]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({10, 20}, allocated);
        ListNode* result = Solution::oddEvenList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{10, 20});
    }

    SECTION("Even number of nodes: head = [1, 2, 3, 4, 5, 6]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({1, 2, 3, 4, 5, 6}, allocated);
        ListNode* result = Solution::oddEvenList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{1, 3, 5, 2, 4, 6});
    }

    SECTION("Boundary values and duplicates ordered strictly by index parity")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({-1000000, 1000000, 0, -1000000, 1000000, 0}, allocated);
        ListNode* result = Solution::oddEvenList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{-1000000, 0, 1000000, 1000000, -1000000, 0});
    }
}
