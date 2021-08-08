#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> socks;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        auto search = socks.find(tmp);
        if(search == socks.end()) {
            socks.insert(make_pair(tmp, 1));
        } else {
            search->second += 1;
        }
    }

    int pairs = 0;
    for(auto const &value : socks) {
        if(get<1>(value) > 1)
            pairs += (get<1>(value) - (get<1>(value) % 2)) / 2;
    }

    cout << pairs;
    return 0;
}