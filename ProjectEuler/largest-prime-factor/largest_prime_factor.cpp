#include "largest_prime_factor.h"

namespace primes
{
    unsigned long long largest_prime(unsigned long long n) {
        std::vector<unsigned long long> primes = eratosthenes_sieve( n ); // vector of a found primes

        for( int i = primes.size() - 1; i >= 0 ; --i ) {
            if( n % primes[i] == 0 )
                return primes[i];
        }
    }

    unsigned long long largest_prime_factor(unsigned long long n) {
        unsigned long long tmp = n;
        unsigned long long current = 2; // prime can't be smaller

        while(tmp > 1) {
            while(tmp % current == 0) {
                tmp /= current;
            }

            current++;

            if(current*current > tmp && tmp > 1) {
                return tmp;
                break;
            }
        }
        
        return --current;
    }

    std::vector<unsigned long long> eratosthenes_sieve(unsigned long long n) {
        // 0 and 1 are not primes so 'false' them right away
        std::vector<bool> primes_b{false, false};
        for(unsigned long long i = 2; i <= n; i++) {
            primes_b.push_back(true);
        }

        // Eratosthenes sieve
        for( unsigned long long i = 0; i <= std::trunc(std::sqrt(n)); i++ ) {
            if(primes_b[i] == true) { // Check only numbers that hasn't been crossed out

                bool is_prime = true; // Check if current i is a prime

                for(unsigned long long j = 2; j <= i; j++) {
                    if(i % j == 0 && i != j) {
                        is_prime = false;
                        break;
                    }
                }

                if(is_prime) {
                    primes_b[i] = true;
                    primes_b[i*i] = false;
                    for(unsigned long long k = 1; (i*i)+(i*k) <= n; k++) {
                        primes_b[(i*i)+(i*k)] = false;
                    }
                } else {
                    primes_b[i] = false;
                }
            }
        }

        // Create a vector of prime numbers and return it
        std::vector<unsigned long long> primes_l;
        for(unsigned long long i = 0; i < primes_b.size(); i++) {
            if(primes_b[i] == true)
                primes_l.push_back(i);
        }

        return primes_l;
    }
} 
