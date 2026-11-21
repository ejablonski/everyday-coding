#include "138.copy_list_with_random_pointer.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace LC138;

namespace {
struct NodeSpec
{
    int val;
    int randomIndex; // -1 represents nullptr
};

struct CopyCheckResult
{
    bool isNull = false;
    bool hasCycle = false;
    bool lengthMatches = false;
    bool allNodesDistinctFromOriginal = false;
    bool valuesMatch = false;
    bool randomPointersMatch = false;
    bool originalListIntact = false;
};

Node* buildRandomList(const std::vector<NodeSpec>& specs, std::vector<Node*>& origNodes)
{
    origNodes.clear();
    origNodes.reserve(specs.size());

    for (const NodeSpec& spec : specs) {
        origNodes.push_back(new Node(spec.val));
    }
    for (std::size_t i = 0; i < specs.size(); ++i) {
        if (i + 1 < specs.size()) {
            origNodes[i]->next = origNodes[i + 1];
        }
        if (specs[i].randomIndex >= 0) {
            origNodes[i]->random = origNodes[static_cast<std::size_t>(specs[i].randomIndex)];
        }
    }
    return origNodes.empty() ? nullptr : origNodes.front();
}

CopyCheckResult inspectAndFree(const std::vector<NodeSpec>& specs,
                               const std::vector<Node*>& origNodes,
                               Node* copiedHead)
{
    CopyCheckResult check{};
    check.isNull = (copiedHead == nullptr);

    std::unordered_set<Node*> origSet(origNodes.begin(), origNodes.end());
    std::vector<Node*> copiedNodes;
    std::unordered_map<Node*, std::size_t> copiedIndex;

    Node* curr = copiedHead;
    while (curr != nullptr) {
        if (copiedIndex.contains(curr)) {
            check.hasCycle = true;
            break;
        }
        copiedIndex.emplace(curr, copiedNodes.size());
        copiedNodes.push_back(curr);
        curr = curr->next;
    }

    check.lengthMatches = (!check.hasCycle && copiedNodes.size() == specs.size());

    check.allNodesDistinctFromOriginal = true;
    for (Node* node : copiedNodes) {
        if (origSet.contains(node)) {
            check.allNodesDistinctFromOriginal = false;
            break;
        }
    }

    if (check.lengthMatches) {
        check.valuesMatch = true;
        check.randomPointersMatch = true;
        for (std::size_t i = 0; i < specs.size(); ++i) {
            if (copiedNodes[i]->val != specs[i].val) {
                check.valuesMatch = false;
            }
            if (specs[i].randomIndex < 0) {
                if (copiedNodes[i]->random != nullptr) {
                    check.randomPointersMatch = false;
                }
            } else {
                auto targetIdx = static_cast<std::size_t>(specs[i].randomIndex);
                if (copiedNodes[i]->random != copiedNodes[targetIdx]) {
                    check.randomPointersMatch = false;
                }
            }
        }
    }

    check.originalListIntact = true;
    for (std::size_t i = 0; i < specs.size(); ++i) {
        Node* expectedNext = (i + 1 < specs.size()) ? origNodes[i + 1] : nullptr;
        Node* expectedRandom = (specs[i].randomIndex >= 0)
                                   ? origNodes[static_cast<std::size_t>(specs[i].randomIndex)]
                                   : nullptr;
        if (origNodes[i]->val != specs[i].val || origNodes[i]->next != expectedNext ||
            origNodes[i]->random != expectedRandom) {
            check.originalListIntact = false;
            break;
        }
    }

    std::unordered_set<Node*> toDelete(origNodes.begin(), origNodes.end());
    toDelete.insert(copiedNodes.begin(), copiedNodes.end());
    for (Node* node : toDelete) {
        delete node;
    }

    return check;
}

void verifyDeepCopy(const std::vector<NodeSpec>& specs)
{
    std::vector<Node*> origNodes;
    Node* head = buildRandomList(specs, origNodes);
    Node* copied = Solution::copyRandomList(head);
    CopyCheckResult check = inspectAndFree(specs, origNodes, copied);

    REQUIRE_FALSE(check.isNull);
    REQUIRE_FALSE(check.hasCycle);
    REQUIRE(check.lengthMatches);
    REQUIRE(check.allNodesDistinctFromOriginal);
    REQUIRE(check.valuesMatch);
    REQUIRE(check.randomPointersMatch);
    REQUIRE(check.originalListIntact);
}
} // namespace

TEST_CASE("LeetCode 138 - Copy List with Random Pointer", "[LeetCode][138][hash-table][linked-list]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]")
    {
        verifyDeepCopy({{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}});
    }

    SECTION("Example 2: head = [[1,1],[2,1]]")
    {
        verifyDeepCopy({{1, 1}, {2, 1}});
    }

    SECTION("Example 3: head = [[3,null],[3,0],[3,null]]")
    {
        verifyDeepCopy({{3, -1}, {3, 0}, {3, -1}});
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Empty list: head = []")
    {
        Node* copied = Solution::copyRandomList(nullptr);
        CopyCheckResult check = inspectAndFree({}, {}, copied);

        REQUIRE(check.isNull);
    }

    SECTION("Single node with null random pointer: [[42,null]]")
    {
        verifyDeepCopy({{42, -1}});
    }

    SECTION("Single node with self-referencing random pointer and min value: [[-10000,0]]")
    {
        verifyDeepCopy({{-10000, 0}});
    }

    SECTION("All random pointers null with max value: [[-5,null],[0,null],[10000,null]]")
    {
        verifyDeepCopy({{-5, -1}, {0, -1}, {10000, -1}});
    }

    SECTION("Cyclic random pointers across duplicate values: [[7,1],[7,2],[7,0]]")
    {
        verifyDeepCopy({{7, 1}, {7, 2}, {7, 0}});
    }
}
