#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int size;
    int del;
    int start;
    int end;
    vector<int> v;

    cin >> size;

    for(int i = 0; i < size; i++) {
        int number;
        cin >> number;
        v.push_back(number);
    }

    cin >> del;
    cin >> start;
    cin >> end;

    v.erase(v.begin() + --del);
    v.erase(v.begin() + --start, v.begin() + --end);

    cout << v.size() << endl;

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
