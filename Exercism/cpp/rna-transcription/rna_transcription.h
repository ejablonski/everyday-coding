#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

#include <vector>
#include <string>
using namespace std;

namespace rna_transcription
{
	char to_rna(char _c)
	{
		switch (_c)
		{
		case 'G':
			return 'C';
			break;
		case 'C':
			return 'G';
			break;
		case 'T':
			return 'A';
			break;
		case 'A':
			return 'U';
			break;
		default:
			break;
		}

		return '0';
	}

	string to_rna(string _s)
	{
		vector<char> dna = {'G', 'C', 'T', 'A'};
		vector<char> rna = {'C', 'G', 'A', 'U'};

		string ret("");

		for(char c : _s)
		{
			ret += to_rna(c);
		}

		return ret;
	}
}  // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H
