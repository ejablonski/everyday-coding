// https://www.hackerrank.com/challenges/arrays-introduction
#include <iostream>
using namespace std;

int main() {
    int input;

    cin >> input;

    int arr[input];
    int arr_reverse[input];

    input--;

    for(int i = 0; i <= input; i++) {
       cin >> arr[i];
    }
    
    for(int i = 0; i <= input; i++) {
        arr_reverse[input - i] = arr[i];
    }
    
    for(int i = 0; i <= input; i++) {
        cout << arr_reverse[i] << " ";
    }

    return 0;
}
