#include "2073.time_needed_to_buy_tickets.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 2073 - Time Needed to Buy Tickets",
          "[LeetCode][2073][array][queue][simulation]")
{
    Solution solution;

    // --- Official Markdown Examples ---
    SECTION("Example 1: tickets = [2, 3, 2], k = 2")
    {
        std::vector<int> tickets = {2, 3, 2};
        REQUIRE(solution.timeRequiredToBuy(tickets, 2) == 6);
    }

    SECTION("Example 2: tickets = [5, 1, 1, 1], k = 0")
    {
        std::vector<int> tickets = {5, 1, 1, 1};
        REQUIRE(solution.timeRequiredToBuy(tickets, 0) == 8);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single person (minimum constraint n = 1, tickets = 1): tickets = [1], k = 0")
    {
        std::vector<int> tickets = {1};
        REQUIRE(solution.timeRequiredToBuy(tickets, 0) == 1);
    }

    SECTION("Single person with upper boundary tickets: tickets = [100], k = 0")
    {
        std::vector<int> tickets = {100};
        REQUIRE(solution.timeRequiredToBuy(tickets, 0) == 100);
    }

    SECTION("Target person at the front needs only 1 ticket: tickets = [1, 5, 5], k = 0")
    {
        std::vector<int> tickets = {1, 5, 5};
        REQUIRE(solution.timeRequiredToBuy(tickets, 0) == 1);
    }

    SECTION("Target person in the middle needs only 1 ticket: tickets = [5, 1, 5], k = 1")
    {
        std::vector<int> tickets = {5, 1, 5};
        REQUIRE(solution.timeRequiredToBuy(tickets, 1) == 2);
    }

    SECTION("Target person at the end needs only 1 ticket: tickets = [5, 5, 1], k = 2")
    {
        std::vector<int> tickets = {5, 5, 1};
        REQUIRE(solution.timeRequiredToBuy(tickets, 2) == 3);
    }

    SECTION("All people want identical ticket amounts: tickets = [3, 3, 3], k = 1")
    {
        std::vector<int> tickets = {3, 3, 3};
        REQUIRE(solution.timeRequiredToBuy(tickets, 1) == 8);
    }

    SECTION("Mixed ticket requirements with people behind finishing earlier: tickets = [4, 5, 2, 1], k = 1")
    {
        std::vector<int> tickets = {4, 5, 2, 1};
        REQUIRE(solution.timeRequiredToBuy(tickets, 1) == 12);
    }

    SECTION("Maximum boundary values: tickets = [100, 100, 100], k = 2")
    {
        std::vector<int> tickets = {100, 100, 100};
        REQUIRE(solution.timeRequiredToBuy(tickets, 2) == 300);
    }
}
