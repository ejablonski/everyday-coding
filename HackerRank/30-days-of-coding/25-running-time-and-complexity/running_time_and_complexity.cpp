// https://www.hackerrank.com/challenges/30-running-time-and-complexity
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<unsigned long long> v;
    
    for(int i = 0; i < n; i++) {
        unsigned long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    for(auto p : v) {
        bool prime = true;
        
        if(p <= 1) {
            prime = false;
        } else if(p <= 3) {
            prime = true;
        } else if(p % 2 == 0 || p % 3 == 0) {
            prime = false;
        } else {
            unsigned long long i = 5;
            while(i * i <= p) {
                if(p % i == 0 || p % (i + 2) == 0) {
                    prime = false;
                }
                i += 6;
            }
        }

        if(prime) {
            cout << "Prime" << endl;
        } else {
            cout << "Not prime" << endl;
        }
    }
    return 0;
}