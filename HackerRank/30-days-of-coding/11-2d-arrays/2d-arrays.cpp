// https://www.hackerrank.com/challenges/30-2d-arrays
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector< vector<signed int> > arr(6, vector<signed int>(6));
    vector<signed int> sum;
    signed int max;

    for(int arr_i = 0; arr_i < 6; arr_i++) {
       for(int arr_j = 0; arr_j < 6; arr_j++) {
          cin >> arr[arr_i][arr_j];
       }
    }

    for(int i = 0; i < 4; i++) {
       for(int j = 0; j < 4; j++) {
          int hourglass =   arr[i][j] + arr[i][j  + 1] + arr[i][j + 2] +
                            arr[i + 1][j + 1] + 
                            arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
          sum.push_back(hourglass);
       }
    }

    max = sum[0];
    for(int i = 0; i < sum.size(); i++) {
        if(sum[i] > max) {
            max = sum[i];
        }
    }
    cout << max;
    return 0;
}
