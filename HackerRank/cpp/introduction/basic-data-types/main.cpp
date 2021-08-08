// https://www.hackerrank.com/challenges/c-tutorial-basic-data-types
#include <cstdio>
using namespace std;

int main() {
    int var_int;
    long var_long;
    long long var_long_long;
    char var_char;
    float var_float;
    double var_double;
        
    scanf("%d %ld %lld %c %f %lf", &var_int, &var_long, &var_long_long, &var_char, &var_float, &var_double);
    printf("%d\n", var_int);
    printf("%ld\n", var_long);
    printf("%lld\n", var_long_long);
    printf("%c\n", var_char);
    printf("%f\n", var_float);
    printf("%lf\n", var_double);
    
    return 0;
}
