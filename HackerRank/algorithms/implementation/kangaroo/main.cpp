#include <iostream>
using namespace std;

int main() {
    int x1, x2, v1, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    if((x1 < x2 && v1 < v2) || (x1 != x2 && v1 == v2)) {
        cout << "NO";
        return 0;
    }

    (x1 - x2) % (v2 - v1) == 0 ? cout << "YES" : cout << "NO";

    return 0;
}
