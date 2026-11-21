#include "93.restore_ip_addresses.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <vector>

using namespace LC93;

TEST_CASE("LeetCode 93 - Restore IP Addresses", "[LeetCode][93][string][backtracking]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"25525511135\"")
    {
        std::vector<std::string> expected = {"255.255.11.135", "255.255.111.35"};
        REQUIRE_THAT(Solution::restoreIpAddresses("25525511135"),
                     Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Example 2: s = \"0000\"")
    {
        std::vector<std::string> expected = {"0.0.0.0"};
        REQUIRE_THAT(Solution::restoreIpAddresses("0000"),
                     Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Example 3: s = \"101023\"")
    {
        std::vector<std::string> expected = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3",
                                             "101.0.2.3"};
        REQUIRE_THAT(Solution::restoreIpAddresses("101023"),
                     Catch::Matchers::UnorderedEquals(expected));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length too short to form 4 octets: s = \"1\"")
    {
        REQUIRE(Solution::restoreIpAddresses("1").empty());
    }

    SECTION("Maximum length too long to form 4 octets: 20 digits")
    {
        REQUIRE(Solution::restoreIpAddresses("11111111111111111111").empty());
    }

    SECTION("Maximum valid IPv4 boundary: s = \"255255255255\"")
    {
        std::vector<std::string> expected = {"255.255.255.255"};
        REQUIRE_THAT(Solution::restoreIpAddresses("255255255255"),
                     Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Out-of-range octet values exceed 255: s = \"256256256256\"")
    {
        REQUIRE(Solution::restoreIpAddresses("256256256256").empty());
    }

    SECTION("Leading zeros rejected except standalone zero: s = \"010010\"")
    {
        std::vector<std::string> expected = {"0.10.0.10", "0.100.1.0"};
        REQUIRE_THAT(Solution::restoreIpAddresses("010010"),
                     Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Five zeros cannot be partitioned without leading zeros: s = \"00000\"")
    {
        REQUIRE(Solution::restoreIpAddresses("00000").empty());
    }
}
