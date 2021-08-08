#include <vector>
#include <iostream>

int main() {
    int n;
    std::vector<long> tests;

    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        tests.push_back( tmp );
    }

    for(int i = 0; i < n; i++) {
        std::cout << task::sum_multiples(tests[i]) << std::endl;
    }

    return 0;
}