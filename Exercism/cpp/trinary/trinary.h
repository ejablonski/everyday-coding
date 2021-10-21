#if !defined(TRINARY_H)
#define TRINARY_H

#include <string>
#include <cmath>
using namespace std;

namespace trinary
{
	int to_decimal(string _s)
	{
		for(auto c : _s)
		{
			if(!isdigit(c))
			{
				return 0;
			}
		}

		int dec = 0;

		for(unsigned int i = 0; i < _s.length(); i++)
		{
			int n = (stoi(to_string(_s[_s.length() - i - 1])) - 48) * pow(3, i);

			dec += n;
		}

		return dec;
	}
}  // namespace trinary

#endif // TRINARY_H
