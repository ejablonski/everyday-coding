#include "even_fibonacci_numbers.h"

namespace fib
{
    unsigned long long int sum_up_even(unsigned long long int n) {
        unsigned long long int term_1 = 1;
        unsigned long long int term_2 = 1;
        unsigned long long int next_term = 0;
        unsigned long long int result = 0;
        
        while(next_term <= n) {
            if((next_term % 2) == 0)
                result += next_term;
        
            next_term = term_1 + term_2;
            term_2 = term_1;
            term_1 = next_term;
        }

        return result;
    }
}
