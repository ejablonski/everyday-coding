#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int a) {
    int reverse = 0;
    while(a != 0) {
        reverse = reverse * 10;
        reverse = reverse + a % 10;
        a = a / 10;
    }
    return reverse;
}

int main() {
    int i, j, k;
    cin >> i >> j >> k;
    int count = 0;
    for(int n = i; n <= j; n++) {
        if(abs(n - reverse(n)) % k == 0) {
            count++;
        }
    }
    cout << count;
    return 0;
}
