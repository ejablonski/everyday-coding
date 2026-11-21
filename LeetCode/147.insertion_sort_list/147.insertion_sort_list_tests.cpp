#include "147.insertion_sort_list.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <memory>
#include <vector>

using namespace LC147;

namespace {
struct ManagedList
{
    std::vector<std::unique_ptr<ListNode>> nodes;

    [[nodiscard]] ListNode* build(const std::vector<int>& values)
    {
        nodes.clear();
        nodes.reserve(values.size());
        for (int val : values) {
            nodes.push_back(std::make_unique<ListNode>(val));
        }
        for (std::size_t i = 0; i + 1 < nodes.size(); ++i) {
            nodes[i]->next = nodes[i + 1].get();
        }
        return nodes.empty() ? nullptr : nodes.front().get();
    }
};

[[nodiscard]] std::vector<int> toVector(ListNode* head, std::size_t maxNodes)
{
    std::vector<int> result;
    ListNode* curr = head;
    while (curr != nullptr && result.size() <= maxNodes) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}
} // namespace

TEST_CASE("LeetCode 147 - Insertion Sort List", "[LeetCode][147][linked-list][sorting]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: head = [4,2,1,3]")
    {
        ManagedList list;
        ListNode* head = list.build({4, 2, 1, 3});
        ListNode* result = Solution::insertionSortList(head);
        REQUIRE(result != nullptr);
        std::vector<int> expected = {1, 2, 3, 4};
        REQUIRE(toVector(result, expected.size()) == expected);
    }

    SECTION("Example 2: head = [-1,5,3,4,0]")
    {
        ManagedList list;
        ListNode* head = list.build({-1, 5, 3, 4, 0});
        ListNode* result = Solution::insertionSortList(head);
        REQUIRE(result != nullptr);
        std::vector<int> expected = {-1, 0, 3, 4, 5};
        REQUIRE(toVector(result, expected.size()) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single node (minimum length)")
    {
        ManagedList list;
        ListNode* head = list.build({42});
        ListNode* result = Solution::insertionSortList(head);
        REQUIRE(result != nullptr);
        std::vector<int> expected = {42};
        REQUIRE(toVector(result, expected.size()) == expected);
    }

    SECTION("Two nodes reversed at value boundaries [-5000, 5000]")
    {
        ManagedList list;
        ListNode* head = list.build({5000, -5000});
        ListNode* result = Solution::insertionSortList(head);
        REQUIRE(result != nullptr);
        std::vector<int> expected = {-5000, 5000};
        REQUIRE(toVector(result, expected.size()) == expected);
    }

    SECTION("Already sorted ascending list")
    {
        ManagedList list;
        ListNode* head = list.build({-10, -5, 0, 5, 10});
        ListNode* result = Solution::insertionSortList(head);
        REQUIRE(result != nullptr);
        std::vector<int> expected = {-10, -5, 0, 5, 10};
        REQUIRE(toVector(result, expected.size()) == expected);
    }

    SECTION("Reverse sorted descending list")
    {
        ManagedList list;
        ListNode* head = list.build({5, 4, 3, 2, 1});
        ListNode* result = Solution::insertionSortList(head);
        REQUIRE(result != nullptr);
        std::vector<int> expected = {1, 2, 3, 4, 5};
        REQUIRE(toVector(result, expected.size()) == expected);
    }

    SECTION("Duplicate negative and positive values")
    {
        ManagedList list;
        ListNode* head = list.build({3, 1, 3, -2, 1, -2});
        ListNode* result = Solution::insertionSortList(head);
        REQUIRE(result != nullptr);
        std::vector<int> expected = {-2, -2, 1, 1, 3, 3};
        REQUIRE(toVector(result, expected.size()) == expected);
    }

    SECTION("All nodes identical")
    {
        ManagedList list;
        ListNode* head = list.build({0, 0, 0, 0});
        ListNode* result = Solution::insertionSortList(head);
        REQUIRE(result != nullptr);
        std::vector<int> expected = {0, 0, 0, 0};
        REQUIRE(toVector(result, expected.size()) == expected);
    }
}
