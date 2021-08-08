// https://www.hackerrank.com/challenges/c-tutorial-stringstream
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    char ch;
    stringstream ss(str);
    vector<int> n;

    do {
        int number;
        ss >> number >> ch;
        n.push_back(number);
    }
    while(!ss.eof());

    return n;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
