#pragma once

#include <algorithm>
#include <ranges>
#include <vector>

#if !defined(__cpp_lib_ranges_zip) || __cpp_lib_ranges_zip < 202110L
#include <range/v3/view/drop.hpp>
#include <range/v3/view/zip_with.hpp>
#endif

namespace LC1502 {

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

#if defined(__cpp_lib_ranges_zip) && __cpp_lib_ranges_zip >= 202110L
        auto diffs = _v | std::views::adjacent_transform<2>([](int a, int b) { return b - a; });
#else
        auto diffs = ranges::views::zip_with(
            [](int a, int b) { return b - a; },
            _v,
            _v | ranges::views::drop(1)
        );
#endif

        return std::ranges::all_of(diffs, [=](int diff) { return diff == expected_diff; });
    }
};

} // namespace LC1502
