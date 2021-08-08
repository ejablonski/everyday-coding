// https://www.hackerrank.com/challenges/variable-sized-arrays/problem
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> vt;
        for(int j = 0; j < k; j++) {
            int nt;
            cin >> nt;
            vt.push_back(nt);
        }
        v.push_back(vt);
    }

    for(int i = 0; i < q; i++) {
        int q1, q2;
        cin >> q1 >> q2;
        cout << v.at(q1).at(q2) << endl;
    }
    return 0;
}