#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    multiset<unsigned long> lst;

    cin >> n;
    for(int i = 0; i < n; i++) {
        unsigned long tmp;
        cin >> tmp;
        lst.insert(tmp);
    }

    // unsigned long it = *next(lst.begin(), lst.size() - 1);
    cout << lst.count(*next(lst.begin(), lst.size() - 1));
    return 0;
}