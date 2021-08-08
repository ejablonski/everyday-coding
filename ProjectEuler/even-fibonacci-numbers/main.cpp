#include <vector>
#include <iostream>

int main() {
    unsigned long long int n;
    std::vector<unsigned long long int> tests;

    std::cin >> n;

    for(unsigned long long int i = 0; i < n; i++) {
        unsigned long long int tmp;
        std::cin >> tmp;
        tests.push_back( tmp );
    }

    for(auto t : tests) {
        std::cout << fib::sum_up_even( t ) << std::endl;
    }

    return 0;
}