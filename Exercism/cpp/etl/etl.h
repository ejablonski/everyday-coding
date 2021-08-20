#include <map>
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

namespace etl
{
	map<char, int> transform(map<int, vector<char>> old)
	{
		map<char, int> result;

		for(auto it = old.begin(); it != old.end(); ++it)
		{
			for(unsigned int j = 0; j < it->second.size(); j++)
			{
				result[tolower(it->second.at(j))] = it->first;
			}
		}
		return result;
	}
}
