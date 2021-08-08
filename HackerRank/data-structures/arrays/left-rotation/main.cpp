#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, d;
    vector<int> v;
    cin >> n >> d;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i = 0; i < d; i++) {
        int tmp = v[0];
        v.erase(v.begin());
        v.push_back(tmp);
    }
    
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
