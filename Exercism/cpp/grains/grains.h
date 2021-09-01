#if !defined GRAINS_H
#define GRAINS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

namespace grains
{
    unsigned long long int square(const int& n) {
        unsigned long long int current_square = 1;

        for(int i = 1; i < n; ++i) {
            unsigned long long int prev_square = current_square;
            current_square = prev_square * 2;
        }

        return current_square;
    }

    unsigned long long total() {
        unsigned long long int result = 0;

        for(int i = 1; i <= 64; ++i) {
            unsigned long long int tmp_a = result;
            unsigned long long int tmp_b = square(i);
            result = tmp_a + tmp_b;
        }

        return result;
    }
}

#endif
