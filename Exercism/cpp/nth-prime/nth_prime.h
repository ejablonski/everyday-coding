#if !defined(NTH_PRIME_H)
#define NTH_PRIME_H

#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
using namespace std;

namespace nth_prime
{
	std::vector<unsigned long long> sieve(unsigned long long n)
	{
		// 0 and 1 are not primes so 'false' them right away
		std::vector<bool> primes_b{false, false};

		for(unsigned long long i = 2; i <= n; i++)
		{
			primes_b.push_back(true);
		}

		// Eratosthenes sieve
		for(unsigned long long i = 0; i <= std::trunc(std::sqrt(n)); i++)
		{
			if(primes_b[i] == true) // Check only numbers that hasn't been crossed out
			{
				bool is_prime = true; // Check if current i is a prime

				for(unsigned long long j = 2; j <= i; j++)
				{
					if(i % j == 0 && i != j)
					{
						is_prime = false;
						break;
					}
				}

				if(is_prime)
				{
					primes_b[i] = true;
					primes_b[i * i] = false;

					for(unsigned long long k = 1; (i * i) + (i * k) <= n; k++)
					{
						primes_b[(i * i) + (i * k)] = false;
					}
				}
				else
				{
					primes_b[i] = false;
				}
			}
		}

		// Create a vector of prime numbers and return it
		std::vector<unsigned long long> primes_l;

		for(unsigned long long i = 0; i < primes_b.size(); i++)
		{
			if(primes_b[i] == true)
				primes_l.push_back(i);
		}

		return primes_l;
	}

	int nth(int n)
	{
		if(n == 0)
		{
			throw std::domain_error("Zero is invalid argument");
		}

		std::vector<unsigned long long> primes = sieve(500000);

		return primes[n - 1];
	}
}  // namespace nth_prime

#endif // NTH_PRIME_H
