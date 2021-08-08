#include <iostream>
#include <vector>
#include "largest_prime_factor.h"

int main() {
    int n;
    std::vector<unsigned long long> tests;

    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        unsigned long long tmp;
        std::cin >> tmp;
        tests.push_back(tmp);
    }
  
    for( int i = 0; i < n; i++ ) {
        std::cout << primes::largest_prime_factor(tests[i]) << std::endl;
    }

    return 0;
}