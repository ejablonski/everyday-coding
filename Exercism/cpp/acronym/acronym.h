#if !defined(ACRONYM_H)
#define ACRONYM_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace acronym
{
	string acronym(string _s)
	{
		vector<string> words;
		string word;
		string acro;

		replace(_s.begin(), _s.end(), '-', ' ');

		for(auto c : _s)
		{
			if (c == ' ')
			{
				words.push_back(word);
				word = "";
			} 
			else
			{
				word += c;
			}
		}

		words.push_back(word);

		for(auto s : words)
		{
			if(s[s.length() - 1] == ':')
			{
				transform(s.begin(), s.end(), s.begin(), ::toupper);
				s.resize(s.length() - 1);

				return s;
			}
			else
			{
				acro += s[0];
			}
		}

		transform(acro.begin(), acro.end(), acro.begin(), ::toupper);

		return acro;
	}
}  // namespace acronym

#endif // ACRONYM_H