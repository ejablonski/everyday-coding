#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        scores.push_back(tmp);
    }

    int high = scores.front();
    int low = scores.front();
    int h_count = 0;
    int l_count = 0;

    for(int i = 0; i < scores.size(); ++i) {
        if(scores.at(i) > high) {
            high = scores.at(i);
            h_count++;
        }

        if(scores.at(i) < low) {
            low = scores.at(i);
            l_count++;
        }
    }

    cout << h_count << " " << l_count;
    return 0;
}