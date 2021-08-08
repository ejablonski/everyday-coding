#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int size;
    vector<int> v;

    cin >> size;

    for(int i = 0; i < size; i++) {
        int number;
        cin >> number;
        v.push_back(number);
    }
    
    sort(v.begin(), v.end());

    for(int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
