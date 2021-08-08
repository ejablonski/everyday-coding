#include <iostream>
#include <vector>

#include "compare_the_triplets.h"

int main() {
    std::vector<int> alice;
    std::vector<int> bob;

    for(int i = 0; i < 3; i++) {
        int tmp;
        std::cin >> tmp;
        alice.push_back(tmp);
    }

    std::cin.clear();

    for(int i = 0; i < 3; i++) {
        int tmp;
        std::cin >> tmp;
        bob.push_back(tmp);
    }

    std::vector<int> result = triplets::compute(alice, bob);

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}