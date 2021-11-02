#include "series.h"

namespace series {
	vector<int> digits(string _s)
	{
		vector<int> v;

		for(auto& c: _s)
		{
			v.push_back(stoi(to_string(c)) - 48);
		}

		return v;
	}

	vector<vector<int>> slice(string _s, int _n)
	{
		if((int)_s.length() < _n)
		{
			throw domain_error("you deserve whatever you get");
		}

		vector<vector<int>> r;
		vector<int> v = series::digits(_s);

		for(unsigned int i = 0; i <= v.size() - _n; i++)
		{
			vector<int> temp;

			for(int j = 0; j < _n; j++)
			{
				temp.push_back(v[i + j]);
			}

			r.push_back(temp);
		}

		return r;
	}
}  // namespace series
