#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <vector>
#include <utility>
#include <iostream>
using namespace std;

namespace protein_translation
{
	vector<string> proteins(string _s)
	{
		vector<pair<string, vector<string>>> dict = {
			{"Methionine", {"AUG"}},
			{"Phenylalanine", {"UUU", "UUC"}},
			{"Leucine", {"UUA", "UUG"}},
			{"Serine", {"UCU", "UCC", "UCA", "UCG"}},
			{"Tyrosine", {"UAU", "UAC"}},
			{"Cysteine", {"UGU", "UGC"}},
			{"Tryptophan", {"UGG"}},
			{"", {"UAA", "UAG", "UGA"}}}; // STOP

		vector<string> trans = {};
		vector<string> seq = {};

		for(unsigned int i = 0; i < _s.length() - 2; i += 3)
		{
			seq.push_back(_s.substr(i, 3));
		}

		for(unsigned int i = 0; i < seq.size(); i++)
		{
			for(unsigned int j = 0; j < dict.size(); j++)
			{
				for(unsigned int k = 0; k < dict[j].second.size(); k++)
				{
					if(seq[i] == dict[j].second[k] && dict[j].first.empty())
					{
						i = seq.size();
						j = dict.size();
						break;
					}

					if(seq[i] == dict[j].second[k] && !dict[j].first.empty())
					{
						trans.push_back(dict[j].first);
					}
				}
			}
		}

		return trans;
	}
}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
