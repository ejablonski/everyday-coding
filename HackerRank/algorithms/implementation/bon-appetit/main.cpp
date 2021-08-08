#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int b;
    cin >> b;

    int shared_bill = 0;
    for(int i = 0; i < v.size(); i++) {
        if(i != k)
            shared_bill += v.at(i);
    }

    if((shared_bill / 2) == b) {
        cout << "Bon Appetit";
    } else {
        cout << b - (shared_bill / 2);
    }
    return 0;
}