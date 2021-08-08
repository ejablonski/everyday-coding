#include <iostream>
using namespace std;

int main() {
    string time;
    cin >> time;

    bool is_am;
    time.substr(time.size() - 2, time.size()) == "AM" ? is_am = true : is_am = false;
    // Remove AM, PM
    time.erase(time.size() - 2, time.size());

    string hour = time.substr(0, 2);
    time.erase(0, 2);

    if(is_am && hour == "12") {
        hour = "00";
    } else if(!is_am && hour != "12") {
        hour = to_string(stoi(hour) + 12);
    }

    time.insert(0, hour);

    cout << time;
    return 0;
}