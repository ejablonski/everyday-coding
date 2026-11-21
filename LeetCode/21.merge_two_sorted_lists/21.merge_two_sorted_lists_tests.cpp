#include "21.merge_two_sorted_lists.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <unordered_set>
#include <vector>

using namespace LC21;

namespace {

struct ListGuard
{
    std::vector<ListNode*> allocated;
    ListNode* result = nullptr;

    ListNode* makeList(const std::vector<int>& values)
    {
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int v : values) {
            auto* node = new ListNode(v);
            allocated.push_back(node);
            tail->next = node;
            tail = node;
        }
        return dummy.next;
    }

    ~ListGuard()
    {
        std::unordered_set<ListNode*> toDelete(allocated.begin(), allocated.end());
        ListNode* curr = result;
        while (curr != nullptr && toDelete.insert(curr).second) {
            curr = curr->next;
        }
        for (ListNode* node : toDelete) {
            delete node;
        }
    }
};

std::vector<int> toVector(ListNode* head, std::size_t maxNodes = 200)
{
    std::vector<int> values;
    std::unordered_set<ListNode*> visited;
    ListNode* curr = head;
    while (curr != nullptr && values.size() < maxNodes && visited.insert(curr).second) {
        values.push_back(curr->val);
        curr = curr->next;
    }
    return values;
}

} // namespace

TEST_CASE("LeetCode 21 - Merge Two Sorted Lists", "[LeetCode][21][linked-list][recursion]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: list1 = [1,2,4], list2 = [1,3,4]")
    {
        ListGuard guard;
        ListNode* list1 = guard.makeList({1, 2, 4});
        ListNode* list2 = guard.makeList({1, 3, 4});

        guard.result = Solution::mergeTwoLists(list1, list2);
        REQUIRE(guard.result != nullptr);
        REQUIRE(toVector(guard.result) == std::vector<int>{1, 1, 2, 3, 4, 4});
    }

    SECTION("Example 2: list1 = [], list2 = []")
    {
        ListGuard guard;
        guard.result = Solution::mergeTwoLists(nullptr, nullptr);
        REQUIRE(guard.result == nullptr);
    }

    SECTION("Example 3: list1 = [], list2 = [0]")
    {
        ListGuard guard;
        ListNode* list2 = guard.makeList({0});

        guard.result = Solution::mergeTwoLists(nullptr, list2);
        REQUIRE(guard.result != nullptr);
        REQUIRE(toVector(guard.result) == std::vector<int>{0});
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Second list empty: list1 = [-5,0,5], list2 = []")
    {
        ListGuard guard;
        ListNode* list1 = guard.makeList({-5, 0, 5});

        guard.result = Solution::mergeTwoLists(list1, nullptr);
        REQUIRE(guard.result != nullptr);
        REQUIRE(toVector(guard.result) == std::vector<int>{-5, 0, 5});
    }

    SECTION("Disjoint ranges with list1 strictly smaller than list2")
    {
        ListGuard guard;
        ListNode* list1 = guard.makeList({-100, -50});
        ListNode* list2 = guard.makeList({50, 100});

        guard.result = Solution::mergeTwoLists(list1, list2);
        REQUIRE(guard.result != nullptr);
        REQUIRE(toVector(guard.result) == std::vector<int>{-100, -50, 50, 100});
    }

    SECTION("Disjoint ranges with list2 strictly smaller than list1")
    {
        ListGuard guard;
        ListNode* list1 = guard.makeList({10, 20, 30});
        ListNode* list2 = guard.makeList({-10, -5});

        guard.result = Solution::mergeTwoLists(list1, list2);
        REQUIRE(guard.result != nullptr);
        REQUIRE(toVector(guard.result) == std::vector<int>{-10, -5, 10, 20, 30});
    }

    SECTION("Duplicate and boundary values: [-100, 100]")
    {
        ListGuard guard;
        ListNode* list1 = guard.makeList({-100, -100, 0, 100});
        ListNode* list2 = guard.makeList({-100, 0, 0, 100});

        guard.result = Solution::mergeTwoLists(list1, list2);
        REQUIRE(guard.result != nullptr);
        REQUIRE(toVector(guard.result) == std::vector<int>{-100, -100, -100, 0, 0, 0, 100, 100});
    }

    SECTION("Uneven lengths: single node merged into longer list")
    {
        ListGuard guard;
        ListNode* list1 = guard.makeList({2});
        ListNode* list2 = guard.makeList({1, 3, 4, 5, 6});

        guard.result = Solution::mergeTwoLists(list1, list2);
        REQUIRE(guard.result != nullptr);
        REQUIRE(toVector(guard.result) == std::vector<int>{1, 2, 3, 4, 5, 6});
    }
}
