#include <string>
using namespace std;

long largest_product(string _s, int _n)
{
    long largest = 0;

    for(unsigned int i = 0; i < _s.length() - _n - 1; i++)
    {
        long n = 0;
        string s = _s.substr(i, _n);

        for(unsigned int j = 0; j < _n; j++)
        {
            if(j == 0)
            {
                n = stoi(to_string(s[j])) - 48;
            }
            else
            {
                n *= stoi(to_string(s[j])) - 48;
            }
        }

        if(largest < n)
        {
            largest = n;
        }
    }

    return largest;
}
