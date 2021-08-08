#include <vector>
using namespace std;

int abc_product(int _n)
{
    int a = 0, b = 0, c = 0, ret = 0;
    bool found = false;

    for (a = 1; a < _n / 3; a++) {
        for (b = a; b < _n / 2; b++) {
            c = _n - a - b;

            if (a * a + b * b == c * c) {
                ret = a * b * c;
                found = true;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    return ret;
}
