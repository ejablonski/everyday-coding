#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        string tmp;
        cin >> tmp;
        cout << count(v.begin(), v.end(), tmp) << endl;
    }
    return 0;
}
