#include "731.my_calendar_ii.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace LC731;

TEST_CASE("LeetCode 731 - My Calendar II",
          "[LeetCode][731][array][binary-search][design][segment-tree][prefix-sum][ordered-set]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: standard booking sequence with double and rejected triple bookings")
    {
        MyCalendarTwo calendar;

        REQUIRE(calendar.book(10, 20) == true);
        REQUIRE(calendar.book(50, 60) == true);
        REQUIRE(calendar.book(10, 40) == true);
        REQUIRE(calendar.book(5, 15) == false);
        REQUIRE(calendar.book(5, 10) == true);
        REQUIRE(calendar.book(25, 55) == true);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Identical intervals allow two bookings and reject the third")
    {
        MyCalendarTwo calendar;

        REQUIRE(calendar.book(10, 20) == true);
        REQUIRE(calendar.book(10, 20) == true);
        REQUIRE(calendar.book(10, 20) == false);
        REQUIRE(calendar.book(15, 16) == false);
        REQUIRE(calendar.book(0, 10) == true);
        REQUIRE(calendar.book(20, 30) == true);
    }

    SECTION("Rejected wide booking does not pollute non-overlapping subranges")
    {
        MyCalendarTwo calendar;

        REQUIRE(calendar.book(10, 20) == true);
        REQUIRE(calendar.book(10, 20) == true);
        REQUIRE(calendar.book(0, 30) == false);

        REQUIRE(calendar.book(0, 10) == true);
        REQUIRE(calendar.book(0, 10) == true);
        REQUIRE(calendar.book(20, 30) == true);
        REQUIRE(calendar.book(20, 30) == true);
    }

    SECTION("Boundary endpoints (0 and 10^9) with unit and full-range intervals")
    {
        constexpr int kMaxTime = 1'000'000'000;
        MyCalendarTwo calendar;

        REQUIRE(calendar.book(0, 1) == true);
        REQUIRE(calendar.book(0, 1) == true);
        REQUIRE(calendar.book(0, 1) == false);
        REQUIRE(calendar.book(1, 2) == true);
        REQUIRE(calendar.book(kMaxTime - 1, kMaxTime) == true);
        REQUIRE(calendar.book(0, kMaxTime) == false);
        REQUIRE(calendar.book(1, kMaxTime) == true);
        REQUIRE(calendar.book(1, 2) == false);
        REQUIRE(calendar.book(2, kMaxTime - 1) == true);
    }

    SECTION("Chained half-open overlapping intervals without triple booking")
    {
        MyCalendarTwo calendar;

        REQUIRE(calendar.book(0, 10) == true);
        REQUIRE(calendar.book(5, 15) == true);
        REQUIRE(calendar.book(10, 20) == true);
        REQUIRE(calendar.book(15, 25) == true);
        REQUIRE(calendar.book(9, 11) == false);
        REQUIRE(calendar.book(0, 5) == true);
        REQUIRE(calendar.book(20, 25) == true);
    }

    SECTION("Spanning interval creating multiple disjoint double-booked segments")
    {
        MyCalendarTwo calendar;

        REQUIRE(calendar.book(10, 20) == true);
        REQUIRE(calendar.book(30, 40) == true);
        REQUIRE(calendar.book(5, 35) == true);
        REQUIRE(calendar.book(20, 30) == true);
        REQUIRE(calendar.book(35, 40) == true);
        REQUIRE(calendar.book(19, 21) == false);
        REQUIRE(calendar.book(0, 5) == true);
    }
}
