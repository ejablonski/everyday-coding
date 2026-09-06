#include <vector>

struct Solution
{
    /**
     * ALGORITHM EXPLANATION: Sieve of Eratosthenes
     */
    [[nodiscard]]
    static int countPrimes(int _n)
    {
        if (_n <= 2) {
            return 0;
        }

        // vector of int because changing value of bool takes more cycles then int
        // (it takes more memory tho)
        std::vector<int> is_prime(_n + 1, 1);
        is_prime[1] = is_prime[0] = 0;

        for (int i = 3; i * i <= _n; i += 2) {
            if (is_prime[i] == 1) {
                for (int j = i * i; j <= _n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }

        // Start with 1 because 2 will skipped in the loop below
        int ans = 1;

        // There is no need for checking for even numbers - none of them (except for 2) can't be
        // prime
        for (int i = 3; i < _n; i += 2) {
            if (is_prime[i] == 1) {
                ans++;
            }
        }

        return ans;
    }
};
