#if !defined(TWO_FER_H)
#define TWO_FER_H

#include <string>
using namespace std;

namespace two_fer
{
	string two_fer(string _s = "")
	{
		return _s.empty() ? "One for you, one for me." : "One for " + _s + ", one for me.";
	}
} // namespace two_fer

#endif //TWO_FER_H
