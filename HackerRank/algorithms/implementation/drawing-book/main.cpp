#include <iostream>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    if(((n / 2) - (p / 2)) > (p / 2))
        cout << p / 2;
    else
        cout << ((n / 2) - (p / 2));

    return 0;
}