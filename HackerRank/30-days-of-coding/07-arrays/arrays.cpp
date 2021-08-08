// https://www.hackerrank.com/challenges/30-arrays
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = arr.size() - 1; i >= 0; i--) {
       cin >> arr[i];
    }

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
