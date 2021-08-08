#include <iostream>
#include <set>

using namespace std;

int main() {
    int matrix[6][6];
    set<int> sums;
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            int tmp;
            cin >> tmp;
            matrix[i][j] = tmp;
        }
    }

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            int sum = 0;
            sum += matrix[i][j];
            sum += matrix[i][j + 1];
            sum += matrix[i][j + 2];
            sum += matrix[i + 1][j + 1];
            sum += matrix[i + 2][j];
            sum += matrix[i + 2][j + 1];
            sum += matrix[i + 2][j + 2];
            sums.insert(sum);
        }
    }
    cout << *next(end(sums), -1);
    return 0;
}