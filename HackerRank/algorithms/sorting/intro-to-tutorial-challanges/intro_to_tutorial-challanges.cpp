#include <iostream>
using namespace std;

int main() {
    int n, v, tmp;
    cin >> v >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp == v) {
            cout << i;
        }
    }
    return 0;
}
