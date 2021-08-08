#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s, n, m;
    vector<int> vn, vm;

    cin >> s >> n >> m;
    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        vn.push_back(tmp);
    }
    for(int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        vm.push_back(tmp);
    }

    int p = -1;
    for(auto const &i : vn) {
        for(auto const &j : vm) {
            int km = i + j;
            if(km > p && km <= s)
                p = km;
        }
    }

    cout << p;
    return 0;
}