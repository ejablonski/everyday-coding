#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int counter = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if((v.at(i) + v.at(j)) % k == 0)
                counter++;
        }
    }

    cout << counter;
    return 0;
}