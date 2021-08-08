// https://www.hackerrank.com/challenges/30-review-loop
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int cases;
    vector<string> strings;

    cin >> cases;

    for(int i = 0; i <= cases; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
    }

    for(int i = 0; i < strings.size(); i++) {
        string even;
        even.clear();
        string odd;
        odd.clear();

        for(int j = 0; j < strings[i].length(); j ++) {
            string tmp = strings[i];

            if(j == 0 || j % 2 == 0) {
                even.push_back(tmp[j]);
            } else {
                odd.push_back(tmp[j]);
            }
        }
        cout << even << " " << odd << endl;
    }
    return 0;
}
