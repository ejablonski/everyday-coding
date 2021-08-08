#include <vector>
#include <cmath>
using namespace std;

long sum_of_primes(int _n)
{
    // 0 and 1 are not primes so 'false' them right away
    std::vector<bool> primes_b{false, false};

    for(unsigned long long i = 2; i <= _n; i++)
    {
        primes_b.push_back(true);
    }

    // Eratosthenes sieve
    for(unsigned long long i = 0; i <= std::trunc(std::sqrt(_n)); i++)
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

                for(unsigned long long k = 1; (i * i) + (i * k) <= _n; k++)
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

    long ret = 0;

    for(unsigned long long i = 0; i < primes_b.size(); i++)
    {
        if(primes_b[i] == true)
            ret += i;
    }

    return ret;
}
