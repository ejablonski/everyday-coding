#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i = 0; i < n; i++) {
        cout << v.back() << " ";
        v.pop_back();
    }
    return 0;
}