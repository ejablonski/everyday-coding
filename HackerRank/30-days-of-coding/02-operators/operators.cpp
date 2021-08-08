// https://www.hackerrank.com/challenges/30-operators
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double meal;
    int tip;
    int tax;
    
    cin >> meal;
    cin >> tip;
    cin >> tax;
    
    meal = meal + ((meal * tip / 100) + (meal * tax / 100));
    
    printf("%s%.0f%s", "The total meal cost is ", meal, " dollars.");
    return 0;
} 
