#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    cin >> k;
    for(int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        auto lower = lower_bound(v.begin(), v.end(), tmp);
        if(*lower == tmp) {
            cout << "Yes ";
        } else {
            cout << "No ";
        }

        cout << lower - v.begin() + 1 << endl;
    }

    return 0;
}
