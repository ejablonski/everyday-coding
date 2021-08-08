#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
        cin.clear();
    }
    
    int a = 0;
    int b = 0;
    int j = n;
    for(int i = 0; i < n; i++) {
        --j;
        a+=arr[i][i];
        b+=arr[j][i];
    }

    cout << abs(a - b);
    return 0;
}