#include <iostream>
using namespace std;

int main() {
    int n_of_tests;
    cin >> n_of_tests;

    double minus = 0;
    double plus = 0;
    double zero = 0;
    for(int i = 0; i < n_of_tests; i++) {
        double tmp;
        cin >> tmp;
        if(tmp < 0)
            minus++;
        if(tmp > 0)
            plus++;
        if(tmp == 0)
            zero++;
    }

    cout << plus / n_of_tests << endl;
    cout << minus / n_of_tests << endl;
    cout << zero / n_of_tests << endl;
    return 0;
}