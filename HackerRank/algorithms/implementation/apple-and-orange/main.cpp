// https://www.hackerrank.com/challenges/apple-and-orange
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int s, t, a, b, m, n;
    vector<int> apples, oranges;

    cin >> s >> t;
    cin.clear();
    cin >> a >> b;
    cin.clear();
    cin >> m >> n;

    for(int i = 1; i <= m; i ++) {
        int n;
        cin >> n;
        apples.push_back(n);
    }

    for(int i = 1; i <= n; i++) {
        int n;
        cin >> n;
        oranges.push_back(n);
    }

    int apple = 0;
    int orange = 0;
    for(int i = 0; i < apples.size(); i++) {
        if(a + apples[i] >= s && a + apples[i] <= t) {
            apple++;
        }
    }

    for(int i = 0; i < oranges.size(); i++) {
        if(b + oranges[i] >= s && b + oranges[i] <= t) {
            orange++;
        }
    }

    cout << apple << endl << orange;

    return 0;
}