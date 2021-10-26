#if !defined(HEXADECIMAL_H)
#define HEXADECIMAL_H

#include <string>
#include <vector>
#include <cmath>
using namespace std;

namespace hexadecimal
{
	int convert(string _s)
	{
		vector<char> hex = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

		int num = 0;
		bool fValidHexVal = false;

		for(unsigned int i = 0; i < _s.length(); i++)
		{
			fValidHexVal = !fValidHexVal;

			for(unsigned int j = 0; j < hex.size(); j++)
			{
				if(_s[_s.length() - i - 1] == hex.at(j))
				{
					num += j * pow(16, i);
					fValidHexVal = true;
					break;
				}
			}

			if(!fValidHexVal)
				break;
		}

		return fValidHexVal ? num : 0;
	}
}  // namespace hexadecimal

#endif // HEXADECIMAL_H