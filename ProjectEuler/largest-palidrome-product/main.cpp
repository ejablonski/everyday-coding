#include <vector>
#include <iostream>
#include "largest_palidrome_product.h"
using namespace std;

int main() {
    int n;
    std::vector<int> tests;

    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        tests.push_back(tmp);
    }

    for(int i = 0; i < n; i++) {
        std::cout << palidrome::largestPalidromeProduct(tests[i]) << std::endl;
    }

    return 0;
}