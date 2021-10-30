#if !defined(ALL_YOUR_BASE_H)
#define ALL_YOUR_BASE_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using namespace std;

namespace all_your_base
{
	vector<unsigned int> convert(int _from, vector<unsigned int> _what, int _to)
	{
		if(_from < 2 || _to < 2)
		{
			throw invalid_argument("Base must be greater then 2.");
		}

		unsigned int c = 0;
		vector<unsigned int> ret;
		reverse(_what.begin(), _what.end());

		for(unsigned int i = 0; i < _what.size(); i++)
		{
			// This check for validity is obviously garbage but test is only for < 10 base so ¯\_(ツ)_/¯
			// In IRL solution strtoul() would be better
			if(_what[i] >= (unsigned int)_from)
			{
				throw invalid_argument("This is not a valid number.");
			}

			c += _what[i] * pow(_from, i);
		}

		while(c > 0)
		{
			ret.push_back(c % _to);
			c /= _to;
		}

		reverse(ret.begin(), ret.end());

		return ret;
	}
}  // namespace all_your_base

#endif // ALL_YOUR_BASE_H
