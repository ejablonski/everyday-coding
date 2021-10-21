#if !defined(PASCALS_TRIANGLE_H)
#define PASCALS_TRIANGLE_H

#include <vector>
using namespace std;

namespace pascals_triangle
{
	int factorial(int n)
	{
		if (n == 0)
			return 1;

		return n * factorial(n - 1);
	}

	vector<vector<int>> generate_rows(int _r)
	{
		vector<vector<int>> ret;

		for(int i = 0; i < _r; ++i)
		{
			vector<int> row;

			for(int j = 0; j < i + 1; j++)
			{
				if(i == 0 || j == 0 || j == i)
				{
					row.push_back(1);
				}
				else
				{
					// pascals formula - https://mathworld.wolfram.com/PascalsFormula.html
					row.push_back(factorial(i) / (factorial(j) * factorial(i - j)));
				}
			}

			ret.push_back(row);
		}

		return ret;
	}
}  // namespace pascals_triangle

#endif // PASCALS_TRIANGLE_H
