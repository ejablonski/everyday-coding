#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    map<string, int> students;
    cin >> n;
    string name;
    for(int i = 0; i < n; i++) {
        int q, note;        
        cin >> q >> name;
        if(q == 1) {
            cin >> note;
            students[name] += note;
        }
        if(q == 2) {
            students[name] = 0;
        }
        if(q == 3) {
            cout << students[name] << endl;
        }
    }
    return 0;
}