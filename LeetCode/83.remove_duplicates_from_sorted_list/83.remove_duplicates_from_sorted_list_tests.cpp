#include "83.remove_duplicates_from_sorted_list.hpp"

#include <catch2/catch_test_macros.hpp>
#include <unordered_set>
#include <vector>

using namespace LC83;

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

    std::unordered_set<ListNode*> origSet(allocated.begin(), allocated.end());
    bool reusesOriginal = false;
    for (ListNode* node : visited) {
        if (origSet.contains(node)) {
            reusesOriginal = true;
            break;
        }
    }

    for (ListNode* node : visited) {
        delete node;
    }

    // Only free original nodes when the result is null (e.g., stub) or built a separate list;
    // an in-place solution may already have deleted removed duplicate nodes.
    if (result == nullptr || !reusesOriginal) {
        for (ListNode* node : allocated) {
            if (!visited.contains(node)) {
                delete node;
            }
        }
    }

    return info;
}
} // namespace

TEST_CASE("LeetCode 83 - Remove Duplicates from Sorted List", "[LeetCode][83][linked-list]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: head = [1, 1, 2]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({1, 1, 2}, allocated);
        ListNode* result = Solution::deleteDuplicates(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{1, 2});
    }

    SECTION("Example 2: head = [1, 1, 2, 3, 3]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({1, 1, 2, 3, 3}, allocated);
        ListNode* result = Solution::deleteDuplicates(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{1, 2, 3});
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Empty list: head = []")
    {
        ListNode* result = Solution::deleteDuplicates(nullptr);
        ListResult info = extractAndFree(result, {});

        REQUIRE(info.isNull);
        REQUIRE(info.values.empty());
    }

    SECTION("Single node: head = [42]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({42}, allocated);
        ListNode* result = Solution::deleteDuplicates(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{42});
    }

    SECTION("All elements identical: head = [0, 0, 0, 0, 0]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({0, 0, 0, 0, 0}, allocated);
        ListNode* result = Solution::deleteDuplicates(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{0});
    }

    SECTION("No duplicates present: head = [-5, -1, 0, 3, 10]")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({-5, -1, 0, 3, 10}, allocated);
        ListNode* result = Solution::deleteDuplicates(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{-5, -1, 0, 3, 10});
    }

    SECTION("Constraint boundary values with duplicates at ends and middle")
    {
        std::vector<ListNode*> allocated;
        ListNode* head = buildList({-100, -100, -50, 0, 0, 0, 100, 100}, allocated);
        ListNode* result = Solution::deleteDuplicates(head);
        ListResult info = extractAndFree(result, allocated);

        REQUIRE_FALSE(info.isNull);
        REQUIRE_FALSE(info.hasCycle);
        REQUIRE(info.values == std::vector<int>{-100, -50, 0, 100});
    }
}
