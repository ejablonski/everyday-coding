#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> flock = {0, 0, 0, 0, 0};
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        flock.at(tmp - 1) += 1;
    }

    int bt = flock.at(0);
    int idx = 1;
    for(int i = 1; i < flock.size(); i++) {
        if(bt < flock.at(i) && bt != flock.at(i)) {
            bt = flock.at(i);
            idx = i;
        }
    }

    cout << (idx + 1);
    return 0;
}