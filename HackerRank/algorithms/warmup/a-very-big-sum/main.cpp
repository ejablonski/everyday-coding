#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    unsigned long long result = 0;
    for(int i = 0; i < n; i++) {
        unsigned long long tmp;
        cin >> tmp;
        result += tmp;
    }

    cout << result;

    return 0;
}