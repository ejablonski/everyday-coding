#if !defined(SERIES_H)
#define SERIES_H

#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

namespace series {
	vector<int> digits(string);
	vector<vector<int>> slice(string, int);
}  // namespace series

#endif // SERIES_H
