// https://www.hackerrank.com/challenges/30-dictionaries-and-maps
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int queries;
    vector<string> search;
    map<string, string> phone_book;

    cin >> queries;

    for(int i = 0; i < queries; i++) {
        string key;
        string value;
        cin >> key >> value;
        phone_book.insert(pair<string, string>(key, value));
    }

    string key;
    while(cin >> key) {
        auto result = phone_book.find(key);
        if(result != phone_book.end()) {
            cout << result->first << "=" << result->second << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    return 0;
}