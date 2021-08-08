// https://www.hackerrank.com/challenges/c-tutorial-strings
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    string b;

    cin >> a;
    cin >> b;

    int as = a.size();
    int bs = b.size();

    cout << as << " " << bs << endl;
    cout << a + b << endl;

    for(int i = 0; i < as; i++) {
        if( i == 0 ) {
            cout << b[i];
        } else {
            cout << a[i];
        }
    }
    
    cout << " ";
    
    for(int i = 0; i < bs; i++) {
        if(i == 0) {
            cout << a[i];
        } else {
           cout << b[i];
        }
    }
    return 0;
}
