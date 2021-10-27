#include "allergies.h"

namespace allergies
{
	allergy_test::allergy_test(int _n)
	{
		score = _n;
	}

	bool allergy_test::is_allergic_to(string _s)
	{
		for(auto p : allergies)
		{
			if(p.second == _s && p.first & score)
			{
				return true;
			}
		}

		return false;
	}

	unordered_set<string> allergy_test::get_allergies()
	{
		unordered_set<string> ret;

		if(score == 0)
			return ret;

		for(auto p : reversed_allergies)
		{

			if(score & p.first)
			{
				ret.insert(p.second);
			}
		}

		return ret;
	}
}
