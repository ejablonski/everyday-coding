#pragma once

#include <algorithm>
#include <ranges>
#include <vector>

struct Solution
{
    [[nodiscard]]
    static bool canMakeArithmeticProgression(std::vector<int>& _v)
    {
        if (_v.size() <= 2) {
            return true;
        }
        std::ranges::sort(_v);

        int expected_diff = _v[1] - _v[0];

        auto diffs = _v | std::views::adjacent_transform<2>([](int a, int b) { return b - a; });

        return std::ranges::all_of(diffs, [=](int diff) { return diff == expected_diff; });
    }
};
