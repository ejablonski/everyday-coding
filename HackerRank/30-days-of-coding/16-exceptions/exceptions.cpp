// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer
#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;

    try{
        cout << stoi(S);
    } catch (...) {
        cout << "Bad String";
    }

    return 0;
}