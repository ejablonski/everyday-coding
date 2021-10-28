#if !defined(MATCHING_BRACKETS_H)
#define MATCHING_BRACKETS_H

#include <bits/stdc++.h>
#include <string>
using namespace std;

namespace matching_brackets
{
	bool check(string _s)
	{
		stack<char> s;
		char x;

		for(unsigned int i = 0; i < _s.length(); i++)
		{
			if(_s[i] == '(' || _s[i] == '[' || _s[i] == '{')
			{
				s.push(_s[i]);
				continue;
			}

			if(_s[i] == '(' || _s[i] == '[' || _s[i] == '{' || _s[i] == ')' || _s[i] == ']' || _s[i] == '}')
			{
				if(s.empty())
				{
					return false;
				}

				switch(_s[i])
				{
				case ')':
					x = s.top();
					s.pop();

					if (x == '{' || x == '[')
					{
						return false;
					}

					break;
				case '}':
					x = s.top();
					s.pop();

					if (x == '(' || x == '[')
					{
						return false;
					}

					break;
				case ']':
					x = s.top();
					s.pop();

					if (x == '(' || x == '{')
					{
						return false;
					}

					break;
				}
			}
		}

		return (s.empty());
	}
}  // namespace matching_brackets

#endif // MATCHING_BRACKETS_H
