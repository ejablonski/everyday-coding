// https://www.hackerrank.com/challenges/30-data-types
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    
    int ii;
    double dd;
    string str;

    cin >> ii;
    cin >> dd;
    cin.ignore();
    getline(cin, str);

    cout << i + ii << endl;
    printf("%.1f\n", d + dd);
    cout << s;
    cout << str << endl;
    
    return 0;
}
