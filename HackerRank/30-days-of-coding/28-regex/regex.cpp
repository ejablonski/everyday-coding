#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> list;

    for(int i = 0; i < n; i++) {
        string name;
        string email;
        cin >> name >> email;
        if(email.find("@gmail.com") != string::npos)
        {
            list.push_back(name);
        }
    }

    sort(list.begin(), list.end());

    for(int i = 0; i < list.size(); i++) {
        cout << list[i] << endl;
    }
    return 0;
}