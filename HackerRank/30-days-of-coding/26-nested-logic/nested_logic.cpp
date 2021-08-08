// https://www.hackerrank.com/challenges/30-nested-logic
#include <iostream>
using namespace std;

struct date {
    int d;
    int m;
    int y;
};

int main() {
    date act;
    date exp;

    cin >> act.d >> act.m >> act.y;
    cin.clear();
    cin >> exp.d >> exp.m >> exp.y;

    if(act.d <= exp.d && act.m <= exp.m && act.y <= exp.y) {
        cout << 0;
    } else {
        if(act.d > exp.d && act.m == exp.m && act.y == exp.y) {            
            cout << 15 * (act.d - exp.d);
        } else if(act.m > exp.m && act.y == exp.y) {            
            cout << 500 * (act.m - exp.m);
        } else if( act.y > exp.y ) {
            cout << 10000;
        } else {
            cout << 0;
        }
    }

    return 0;
}