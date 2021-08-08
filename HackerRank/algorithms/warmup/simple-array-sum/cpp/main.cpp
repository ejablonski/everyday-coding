//https://www.hackerrank.com/challenges/simple-array-sum/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        result += tmp;
    }

    cout << result;
    return 0;
}