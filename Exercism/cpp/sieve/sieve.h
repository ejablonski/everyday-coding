#if !defined(SIEVE_H)
#define SIEVE_H

#include <vector>
#include <cmath>

namespace sieve
{
	std::vector<int> primes(int n) {
		// 0 and 1 are not primes so 'false' them right away
		std::vector<bool> primes_b{false, false};

		for(int i = 2; i <= n; i++)
		{
			primes_b.push_back(true);
		}

		// Eratosthenes sieve
		for(int i = 0; i <= std::trunc(std::sqrt(n)); i++)
		{
			if(primes_b[i] == true) // Check only numbers that hasn't been crossed out
			{
				bool is_prime = true; // Check if current i is a prime

				for(int j = 2; j <= i; j++)
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
					primes_b[i*i] = false;

					for(int k = 1; (i*i)+(i*k) <= n; k++)
					{
						primes_b[(i*i)+(i*k)] = false;
					}
				}
				else
				{
					primes_b[i] = false;
				}
			}
		}

		// Create a vector of prime numbers and return it
		std::vector<int> primes_l;

		for(unsigned int i = 0; i < primes_b.size(); i++)
		{
			if(primes_b[i] == true)
				primes_l.push_back(i);
		}

		return primes_l;
	}
}  // namespace sieve

#endif // SIEVE_H
