#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin.clear();
        vector<int> v1, v2;
        int a, b, c, d, p, q;
        cin >> a >> b >> c >> d >> p >> q;
        v1.push_back(a);
        v1.push_back(b);
        v1.push_back(c);
        v1.push_back(d);
        auto itp = find(v1.begin(), v1.end(), p);
        if(itp != v1.end()) {
            v1.erase(itp);
        }
        auto itq = find(v1.begin(), v1.end(), q);
        if(itq != v1.end()) {
            v1.erase(itq);
        }
        cout << v1[0] * v1[1] << endl;
    }
    return 0;
}
