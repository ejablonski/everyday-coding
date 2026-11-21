#include "206.reverse_linked_list.hpp"

#include <catch2/catch_test_macros.hpp>
#include <unordered_set>
#include <vector>

using namespace LC206;

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

TEST_CASE("LeetCode 206 - Reverse Linked List", "[LeetCode][206][linked-list][recursion]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: head = [1, 2, 3, 4, 5]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({1, 2, 3, 4, 5}, allocated);
        ListNode* result = Solution::reverseList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{5, 4, 3, 2, 1});
    }

    SECTION("Example 2: head = [1, 2]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({1, 2}, allocated);
        ListNode* result = Solution::reverseList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{2, 1});
    }

    SECTION("Example 3: head = []")
    {
        ListNode* result = Solution::reverseList(nullptr);
        ListResult info = extractAndFree(result, {});

        REQUIRE(info.isNull);
        REQUIRE(info.values.empty());
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single node: head = [42]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({42}, allocated);
        ListNode* result = Solution::reverseList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{42});
    }

    SECTION("Boundary values: head = [-5000, 0, 5000]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({-5000, 0, 5000}, allocated);
        ListNode* result = Solution::reverseList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{5000, 0, -5000});
    }

    SECTION("Palindrome list: head = [1, 2, 3, 2, 1]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({1, 2, 3, 2, 1}, allocated);
        ListNode* result = Solution::reverseList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{1, 2, 3, 2, 1});
    }

    SECTION("All identical negative values: head = [-7, -7, -7, -7]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({-7, -7, -7, -7}, allocated);
        ListNode* result = Solution::reverseList(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{-7, -7, -7, -7});
    }
}
