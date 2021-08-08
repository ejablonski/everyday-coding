#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        int max = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if ((i & j) > max && (i & j) < k){
                    max = (i & j);
                }
            }
        }

        cout << max << endl;
    }

    return 0;
}