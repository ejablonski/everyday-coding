#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H

#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

namespace secret_handshake
{
	vector<string> commands(int _n)
	{
		if(_n == 0)
		{
			return vector<string> {};
		}

		vector<int> bin;
		vector<string> ret;
		bool rev = false;

		while(_n > 0) {
			bin.push_back(_n % 2);
			_n = _n / 2;
		}

		string s;
		ostringstream convert;
		for(unsigned int i = 0; i < bin.size(); i++)
		{
			convert << bin[bin.size() - i -1];
		}
		s = convert.str();

		int n = stoi(s);

		while(n >= 1)
		{
			if(n - 10000 >= 0)
			{
				rev = true;
				n -= 10000;
			}
			else if(n - 1000 >= 0)
			{
				ret.push_back("jump");
				n -= 1000;
			}
			else if(n - 100 >= 0)
			{
				ret.push_back("close your eyes");
				n -= 100;
			}
			else if(n - 10 >= 0)
			{
				ret.push_back("double blink");
				n -= 10;
			}
			else if(n - 1 >= 0)
			{
				ret.push_back("wink");
				n -= 1;
			}
		}

		if(!rev)
			reverse(ret.begin(), ret.end());

		return ret;
	}
}  // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
