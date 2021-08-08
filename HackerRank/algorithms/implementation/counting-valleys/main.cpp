#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    bool f = false; // if in valley
    int c = 0; // counter
    int l = 0; // level
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'U') {
            ++l;
            if(l >= 0 && f) {
                ++c;
                f = false;
            }
        } else {
            --l;
            if(l < 0)
                f = true;
        }
    }

    cout << c;
    return 0;
}