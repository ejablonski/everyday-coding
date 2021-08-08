// https://www.hackerrank.com/challenges/30-binary-numbers
#include <iostream>
using namespace std;

string toBinary(int n) {
    string s;
    while(n != 0) {
        if(n % 2 == 0) {
            s.insert(0, "0");
        } else {
            s.insert(0, "1");
        }
        n /= 2;
    }
    return s;
}

int main() {
    int n;
    int consecutive = 0;
    string bi;

    cin >> n;

    bi = toBinary(n);

    int m = 0;
    for(int i = 0; i < bi.length(); i++) {
        if(bi[i] == '1') {
            ++m;
        } 
        if(bi[i] == '0' || i == bi.length() - 1) {
            if(consecutive < m) {
                consecutive = m;
            }            
            m = 0;
        }
    }

    cout << consecutive;

    return 0;
}
