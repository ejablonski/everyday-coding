#if !defined(BINARY_H)
#define BINARY_H

#include <string>
#include <cmath>
using namespace std;

namespace binary
{
	int convert(string _s)
	{
		for(auto c : _s)
		{
			if(!isdigit(c))
			{
				return 0;
			}
		}

		int bin = 0;

		for(unsigned int i = 0; i < _s.length(); i++)
		{
			int n = (stoi(to_string(_s[_s.length() - i - 1])) - 48) * pow(2, i);

			bin += n;
		}

		return bin;
	}
}  // namespace binary

#endif // BINARY_H
