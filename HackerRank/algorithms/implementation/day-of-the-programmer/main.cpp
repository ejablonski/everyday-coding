#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

bool isLeapGreg(int year) {
    if(year % 4 == 0 && year % 100 != 0)
        return true;
    else
        if(year % 400 == 0)
            return true;
        else
            return false;
}

bool isLeapJul(int year) {
    if(year % 4 == 0)
        return true;
    else
        return false;
}

tuple<int, int> getDayOfTheProgrammer(vector<int> v) {
    int d = 0, m = 0, n = 0;
    for(int i = 0; i < 12; i++) {
        if(n + v.at(i) < 256) {
            n += v.at(i);
        } else {
            m = i + 1;
            d = 256 - n;
            break;
        }
    }
    return make_tuple(d, m);
}

int main() {
    int y;
    cin >> y;

    vector<int> cal = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> cal_leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> cal_1918 = {31, 15, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    tuple<int, int> dm;
    if(y >= 1700 && y <= 1917) {
        if(isLeapJul(y)) {
            dm = getDayOfTheProgrammer(cal_leap);
        } else {
            dm = getDayOfTheProgrammer(cal);
        }
    } else if(y == 1918) {
        dm = getDayOfTheProgrammer(cal_1918);
    } else if(y >= 1919 && y <= 2700) {
        if(isLeapGreg(y)) {
            dm = getDayOfTheProgrammer(cal_leap);
        } else {
            dm = getDayOfTheProgrammer(cal);
        }
    }

    string ds = to_string(get<0>(dm));
    string ms = to_string(get<1>(dm));
    if(ds.size() == 1)
        ds.insert(0, "0");
    if(ms.size() == 1)
        ms.insert(0, "0");


    cout << ds << "." << ms << "." << y;
    return 0;
}