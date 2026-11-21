#include "141.linked_list_cycle.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <memory>
#include <vector>

using namespace LC141;

namespace {

struct LinkedList
{
    std::vector<std::unique_ptr<ListNode>> nodes;

    [[nodiscard]] ListNode* head() const noexcept
    {
        return nodes.empty() ? nullptr : nodes.front().get();
    }
};

LinkedList buildList(const std::vector<int>& _values, int _pos)
{
    LinkedList list;
    list.nodes.reserve(_values.size());
    for (int v : _values) {
        list.nodes.push_back(std::make_unique<ListNode>(v));
    }
    for (std::size_t i = 0; i + 1 < list.nodes.size(); ++i) {
        list.nodes[i]->next = list.nodes[i + 1].get();
    }
    if (_pos >= 0 && static_cast<std::size_t>(_pos) < list.nodes.size()) {
        list.nodes.back()->next = list.nodes[static_cast<std::size_t>(_pos)].get();
    }
    return list;
}

} // namespace

TEST_CASE("LeetCode 141 - Linked List Cycle",
          "[LeetCode][141][hash-table][linked-list][two-pointers][floyds-cycle-finding-algorithm]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: head = [3,2,0,-4], pos = 1")
    {
        LinkedList list = buildList({3, 2, 0, -4}, 1);
        REQUIRE(Solution::hasCycle(list.head()) == true);
    }

    SECTION("Example 2: head = [1,2], pos = 0")
    {
        LinkedList list = buildList({1, 2}, 0);
        REQUIRE(Solution::hasCycle(list.head()) == true);
    }

    SECTION("Example 3: head = [1], pos = -1")
    {
        LinkedList list = buildList({1}, -1);
        REQUIRE(Solution::hasCycle(list.head()) == false);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Empty list (minimum constraint n = 0)")
    {
        REQUIRE(Solution::hasCycle(nullptr) == false);
    }

    SECTION("Single node self-cycle (pos = 0)")
    {
        LinkedList list = buildList({42}, 0);
        REQUIRE(Solution::hasCycle(list.head()) == true);
    }

    SECTION("Acyclic list with all duplicate node values")
    {
        LinkedList list = buildList({5, 5, 5, 5, 5}, -1);
        REQUIRE(Solution::hasCycle(list.head()) == false);
    }

    SECTION("Tail loops directly back to itself in multi-node list")
    {
        LinkedList list = buildList({1, 2, 3, 4, 5}, 4);
        REQUIRE(Solution::hasCycle(list.head()) == true);
    }

    SECTION("Boundary node values (-10^5 to 10^5) with cycle to head")
    {
        LinkedList list = buildList({-100000, 0, 100000}, 0);
        REQUIRE(Solution::hasCycle(list.head()) == true);
    }
}
