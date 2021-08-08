#include <iostream>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> k;
        for(int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if(a <= 0) {
                --k;
            }
        }
        if(k > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
