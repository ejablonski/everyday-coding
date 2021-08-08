#include <vector>
#include <cmath>
using namespace std;

int smallest_multiple()
{
    int n = 0;
    bool found = false;

    while(!found)
    {
        found = true;
        n++;

        for(int i = 1; i <= 20; i++)
        {
            if(n % i != 0)
                found = false;
        }
    }

    return n;
}
