#include "anagram.h"

namespace anagram
{
	anagram::anagram(std::string _s)
	{
		base = _s;
	}

	std::vector<std::string> anagram::matches(std::vector<std::string> _c)
	{
		std::vector<std::string> solution;

		std::transform(base.begin(), base.end(), base.begin(), ::tolower);
		std::string tmp_base = base; // needed to check if passed candidates are not equal to base
		std::sort(base.begin(), base.end());

		for(unsigned int i = 0; i < _c.size(); i++) {
			std::string tmp_cand;
			tmp_cand.clear();
			tmp_cand = _c[i];
			std::transform(_c[i].begin(), _c[i].end(), _c[i].begin(), ::tolower);

			if(tmp_base != _c[i]) { // to satisfy 'does_not_detect_a_word_as_its_own_anagram' test case
				std::sort(_c[i].begin(), _c[i].end());

				if(base == _c[i]) {
					solution.push_back(tmp_cand);
				}
			}
		}

		return solution;
	}
}