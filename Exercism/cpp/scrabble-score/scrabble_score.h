#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <locale>

namespace scrabble_score
{
	static const std::map<char, int> table{{{'A', 1}, {'B', 3}, {'C', 3}, {'D', 2},
											{'E', 1}, {'F', 4}, {'G', 2}, {'H', 4},
											{'I', 1}, {'J', 8}, {'K', 5}, {'L', 1},
											{'M', 3}, {'N', 1}, {'O', 1}, {'P', 3},
											{'R', 1}, {'Q', 10}, {'S', 1}, {'T', 1},
											{'U', 1}, {'W', 4}, {'V', 4}, {'X', 8},
											{'Y', 4}, {'Z', 10}}};

	int score(const std::string& in_string)
	{
		int points = 0;

		for(const char& c : in_string)
		{
			// Ensure that char is uppercase to be able to compare with score table
			char upper_c = std::toupper(c);
			// Find char in score table and add score
			auto search = table.find(upper_c);
			if(search != table.end())
			{
				points += search->second;
			}
		}

		return points;
	}
}

#endif
