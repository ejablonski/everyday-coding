#if !defined(ARMSTRONG_NUMBERS_H)
#define ARMSTRONG_NUMBERS_H

#include <string>
#include <sstream>
using namespace std;

namespace armstrong_numbers
{
	bool is_armstrong_number(long _n)
	{
		string s;
		ostringstream convert;
		convert << _n;
		s = convert.str();

		long ret = 0;

		for(unsigned int i = 0; i < s.length(); i++)
		{
			ret += pow((stoi(to_string(s[s.length() - i - 1])) - 48), s.length());
		}

		return _n == ret;
	}
}  // namespace armstrong_numbers

#endif // ARMSTRONG_NUMBERS_H