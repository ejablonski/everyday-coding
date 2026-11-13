#include "232.implement_queue_using_stacks.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("LeetCode 232 - Implement Queue using Stacks", "[LeetCode][232][stack][design][queue]")
{
    MyQueue queue;

    // --- Official Markdown Examples ---
    SECTION("Example 1: push(1), push(2), peek() -> 1, pop() -> 1, empty() -> false")
    {
        queue.push(1);
        queue.push(2);
        REQUIRE(queue.peek() == 1);
        REQUIRE(queue.pop() == 1);
        REQUIRE_FALSE(queue.empty());
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Newly constructed queue is empty") { REQUIRE(queue.empty()); }

    SECTION("Single element boundary values (1 <= x <= 9) and queue reuse")
    {
        queue.push(1);
        REQUIRE_FALSE(queue.empty());
        REQUIRE(queue.peek() == 1);
        REQUIRE(queue.pop() == 1);
        REQUIRE(queue.empty());

        queue.push(9);
        REQUIRE_FALSE(queue.empty());
        REQUIRE(queue.peek() == 9);
        REQUIRE(queue.pop() == 9);
        REQUIRE(queue.empty());
    }

    SECTION("Repeated peek does not remove the front element")
    {
        queue.push(3);
        queue.push(5);
        REQUIRE(queue.peek() == 3);
        REQUIRE(queue.peek() == 3);
        REQUIRE(queue.pop() == 3);
        REQUIRE(queue.peek() == 5);
        REQUIRE(queue.pop() == 5);
        REQUIRE(queue.empty());
    }

    SECTION("Interleaved push, peek, and pop operations preserve FIFO order")
    {
        queue.push(1);
        queue.push(2);
        queue.push(3);
        REQUIRE(queue.pop() == 1);

        // Push new elements while earlier elements are still in the queue
        queue.push(4);
        queue.push(5);
        REQUIRE(queue.peek() == 2);
        REQUIRE(queue.pop() == 2);
        REQUIRE(queue.pop() == 3);

        // Now elements pushed later must become the front
        REQUIRE(queue.peek() == 4);
        REQUIRE(queue.pop() == 4);
        REQUIRE(queue.pop() == 5);
        REQUIRE(queue.empty());
    }

    SECTION("Duplicate values preserve insertion order")
    {
        queue.push(7);
        queue.push(7);
        queue.push(2);
        queue.push(7);

        REQUIRE(queue.pop() == 7);
        REQUIRE(queue.pop() == 7);
        REQUIRE(queue.pop() == 2);
        REQUIRE(queue.pop() == 7);
        REQUIRE(queue.empty());
    }

    SECTION("Multi-cycle transfer within 100-call constraint")
    {
        for (int i = 1; i <= 9; ++i) {
            queue.push(i);
        }
        for (int i = 1; i <= 5; ++i) {
            REQUIRE(queue.pop() == i);
        }
        for (int i = 1; i <= 9; ++i) {
            queue.push(i);
        }
        for (int i = 6; i <= 9; ++i) {
            REQUIRE(queue.pop() == i);
        }
        for (int i = 1; i <= 9; ++i) {
            REQUIRE(queue.pop() == i);
        }
        REQUIRE(queue.empty());
    }
}
