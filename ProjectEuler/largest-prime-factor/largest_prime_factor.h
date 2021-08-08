#ifndef LARGEST_PRIME_FACTOR_H
#define LARGEST_PRIME_FACTOR_H

#include <vector>
#include <cmath>

namespace primes
{
    unsigned long long largest_prime(unsigned long long n);
    unsigned long long largest_prime_factor(unsigned long long n);
    std::vector<unsigned long long> eratosthenes_sieve(unsigned long long n);
}

#endif // LARGEST_PRIME_FACTOR_H