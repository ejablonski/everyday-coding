#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp < 38) {
            v.push_back(tmp);
        } else if(5 - (tmp % 5) < 3) {
            v.push_back((tmp - (tmp % 5)) + 5);
        } else {
            v.push_back(tmp);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << v.at(i) << endl;
    }

    return 0;
}