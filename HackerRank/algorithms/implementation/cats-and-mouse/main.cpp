#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(abs(c - b) == abs(c - a)) {
            cout << "Mouse C" << endl;
        } else {
            (abs(c - a) < abs(c - b)) ? cout << "Cat A" << endl : cout << "Cat B" << endl;
        }
    }
    return 0;
}