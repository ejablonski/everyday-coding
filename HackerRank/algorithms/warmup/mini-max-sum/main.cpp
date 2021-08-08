#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<long long> nums;

    for(int i = 0; i < 5; i++) {
        long long tmp;
        cin >> tmp;
        nums.insert(tmp);
    }

    long long sum_min = 0;
    for(int i = 0; i < 4; i++) {
        sum_min += *next(nums.begin(), i);
    }

    long long sum_max = 0;
    for(int i = 1; i < 5; i++) {
        sum_max += *next(nums.begin(), i);
    }

    cout << sum_min << " " << sum_max;
    return 0;
}