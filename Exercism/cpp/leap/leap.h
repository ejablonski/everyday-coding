#include <iostream>
using namespace std;

namespace leap
{
	bool is_leap_year(int i)
	{
		if(i % 4 == 0 && i % 100 != 0)
			return true;
		else
			if(i % 400 == 0)
				return true;
			else
				return false;
	}
}
