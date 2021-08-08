// https://www.hackerrank.com/challenges/30-generics
#include <iostream>
#include <vector>
using namespace std;

template<typename T> void printArray(const vector<T>& v) {
    for(auto i : v)
    {
        cout << i << endl;
    }
};

int main() {  
    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};
    
    printArray<int>(vInt);
    printArray<string>(vString);
    
    return 0;
}