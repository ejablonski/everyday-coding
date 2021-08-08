#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    set<int> s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int querie, tmp;
        cin >> querie >> tmp;
        switch(querie) {
            case(1): {
                s.insert(tmp);
                break;
            }
            case(2): {
                auto itr = s.find(tmp);
                if(itr != s.end()) {
                    s.erase(tmp);
                }
                break;
            }
            case(3): {
                auto itr = s.find(tmp);
                if(itr != s.end()) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
                break;
            }
        }
    }
    return 0;
}