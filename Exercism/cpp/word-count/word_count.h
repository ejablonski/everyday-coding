#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

namespace word_count
{
	map<string, int> words(string text)
	{
		map<string, int> solution;

		// prepare string by getting rid of punctual characters and lowercasing everything
		transform(text.begin(), text.end(), text.begin(), ::tolower);
		for(unsigned int i = 0; i < text.length(); i++)
		{
			// check if punctual char but ignore if it's '\'' and one char behind and after is a letter 
			if(ispunct(text[i]) && !(text[i] == '\'' && isalpha(text[i-1]) && isalpha(text[i+1])))
			{
				// replace with whitespace - will work great with stringstream
				text.replace(text.begin() + i, text.begin() + i + 1, 1, ' ');
			}
		}

		stringstream ss(text);
		string tmp;
		while(ss >> tmp)
		{
			// stream to param tmp and search if it already occured
			auto search = solution.find(tmp);
			if(search != solution.end())
			{
				solution[tmp] += 1;
			}
			else
			{
				solution[tmp] = 1;
			}
		}

		return solution;
	}
}
