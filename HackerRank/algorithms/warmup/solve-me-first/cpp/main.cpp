#include <iostream>
#include "solve_me_first.h"
using namespace std;

int main() {
    int num1, num2;
    int sum;

    cin >> num1 >> num2;
    sum = solveMeFirst(num1,num2);
    cout << sum;

    return 0;
}