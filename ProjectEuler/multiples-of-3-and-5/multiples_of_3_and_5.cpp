#include "multiples_of_3_and_5.h"

namespace task
{
    long sum(int t, int d) {
        long n = std::floor((t - 1) / d);
        return d * (n * (n + 1)) / 2;
    }

    long sum_multiples(long n) {
        return sum(n, 3) + sum(n, 5) - sum(n, 15);
    }
}
