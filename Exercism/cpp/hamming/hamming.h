#include <iostream>
#include <string>
using namespace std;

namespace hamming
{
	int compute(string a, string b)
	{
		if(a.length() != b.length())
			throw domain_error("Different string sizes");

		int n = 0;
		for(unsigned int i = 0; i < a.length(); i++)
		{
			if(a[i] != b[i])
				n++;
		}

		return n;
	}
}
