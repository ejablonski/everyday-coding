#include <string>
#include <iostream>
#include "largest_palidrome_product.h"

namespace palidrome
{
    bool isPalidrome(int n) {
        std::string pali = std::to_string(n);
        for(int i = 0; i < pali.size() / 2; ++i) {
            if(pali[i] != pali[pali.size()-1-i])
                return false;
        }
        return true;
    }

    int largestPalidromeProduct(int n) {
        int num = 0;

        for(int i = 100; i < 1000; ++i) {
            for(int j = 100; j < 1000; ++j) {
                int tmp = i*j;
                if(isPalidrome(tmp)) {
                    if(tmp > num && tmp <= n)
                        num = tmp;
                }
            }
        }

        return num;
    }
}