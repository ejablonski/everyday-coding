#include "1700.number_of_students_unable_to_eat_lunch.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 1700 - Number of Students Unable to Eat Lunch",
          "[LeetCode][1700][array][stack][queue][simulation]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: students = [1, 1, 0, 0], sandwiches = [0, 1, 0, 1]")
    {
        std::vector<int> students = {1, 1, 0, 0};
        std::vector<int> sandwiches = {0, 1, 0, 1};
        REQUIRE(Solution::countStudents(students, sandwiches) == 0);
    }

    SECTION("Example 2: students = [1, 1, 1, 0, 0, 1], sandwiches = [1, 0, 0, 0, 1, 1]")
    {
        std::vector<int> students = {1, 1, 1, 0, 0, 1};
        std::vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
        REQUIRE(Solution::countStudents(students, sandwiches) == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single student able to eat (minimum constraint n = 1): students = [0], sandwiches = [0]")
    {
        std::vector<int> students = {0};
        std::vector<int> sandwiches = {0};
        REQUIRE(Solution::countStudents(students, sandwiches) == 0);
    }

    SECTION("Single student unable to eat (minimum constraint n = 1): students = [0], sandwiches = [1]")
    {
        std::vector<int> students = {0};
        std::vector<int> sandwiches = {1};
        REQUIRE(Solution::countStudents(students, sandwiches) == 1);
    }

    SECTION("Complete mismatch from the start: students = [0, 0, 0], sandwiches = [1, 1, 1]")
    {
        std::vector<int> students = {0, 0, 0};
        std::vector<int> sandwiches = {1, 1, 1};
        REQUIRE(Solution::countStudents(students, sandwiches) == 3);
    }

    SECTION("Blocked immediately by top sandwich: students = [1, 1, 1, 1], sandwiches = [0, 1, 1, 1]")
    {
        std::vector<int> students = {1, 1, 1, 1};
        std::vector<int> sandwiches = {0, 1, 1, 1};
        REQUIRE(Solution::countStudents(students, sandwiches) == 4);
    }

    SECTION("All students share identical preference matching sandwiches: students = [0, 0, 0], sandwiches = [0, 0, 0]")
    {
        std::vector<int> students = {0, 0, 0};
        std::vector<int> sandwiches = {0, 0, 0};
        REQUIRE(Solution::countStudents(students, sandwiches) == 0);
    }

    SECTION("Partial consumption halting on exhausted preference: students = [0, 0, 1, 1, 0], sandwiches = [1, 0, 0, 0, 0]")
    {
        std::vector<int> students = {0, 0, 1, 1, 0};
        std::vector<int> sandwiches = {1, 0, 0, 0, 0};
        REQUIRE(Solution::countStudents(students, sandwiches) == 1);
    }
}
