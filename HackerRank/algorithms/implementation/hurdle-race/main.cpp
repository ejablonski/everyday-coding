#include <iostream>
using namespace std;

int main() {
    int n, k, max = 0, tmp;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp > max) {
            max = tmp;
        }
    }

    if(max <= k) {
        cout << 0;
    } else {
        cout << max - k;  
    }

    return 0;
}
