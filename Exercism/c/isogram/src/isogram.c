#include "isogram.h"

bool is_isogram(const char phrase[])
{
	if(phrase == NULL)
	{
		return false;
	}

	bool seen[26] = {0};

	for(; *phrase; ++phrase)
	{
		if(isalpha(*phrase))
		{
			const int n = tolower(*phrase) - 'a';

			if(seen[n])
			{
				return false;
			}

			seen[n] = true;
		}
	}

	return true;
}
