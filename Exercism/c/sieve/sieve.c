#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    bool primes_b[ARRAY_LEN];
    primes_b[0] = false;
    primes_b[1] = false;

    for(unsigned int i = 2; i <= ARRAY_LEN; i++) {
        primes_b[i] = true;
    }

    for(int i = 0; i <= trunc(sqrt(ARRAY_LEN)); i++) {
      if(primes_b[i] == true) {
        bool is_prime = true;

        for(int j = 2; j <= i; j++) {
          if(i % j == 0 && i != j) {
            is_prime = false;
            break;
          }
        }

        if(is_prime) {
          primes_b[i] = true;
          primes_b[i * i] = false;

          for(unsigned int k = 1; (i * i) + (i * k) <= ARRAY_LEN; k++) {
            primes_b[(i * i) + (i * k)] = false;
          }
        } else {
          primes_b[i] = false;
        }
      }
    }

    int j = 0;

    for(unsigned int i = 0; i <= limit; i++) {
      if(primes_b[i] == true) {
        primes[j] = i;
        j++;
      }
    }

    return j > (int)max_primes ? (int)max_primes : j;
}
