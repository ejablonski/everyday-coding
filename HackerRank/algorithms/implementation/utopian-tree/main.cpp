#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        
        if(n == 0) {
            cout << 1 << endl;
        } else if(n % 2 == 0 && n != 0) {
            int ans = pow(2, ((n / 2) + 1)) - 1;
            cout << ans << endl;
        } else {
            int ans = pow(2,(((n + 1) / 2) + 1)) - 2;
            cout << ans << endl;
        }
    }
    return 0;
}
