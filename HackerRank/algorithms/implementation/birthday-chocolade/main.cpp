#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> choco;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        choco.push_back(tmp);
    }

    int d, m;
    cin >> d >> m;

    int counter = 0;
    for(int i = 0; i <= choco.size() - m; i++) {
        int tmp = 0;
        for(int j = i; j < i + m; j++) {
            tmp += choco.at(j);
        }
        if(tmp == d)
            counter++;
    }

    cout << counter;
    return 0;
}