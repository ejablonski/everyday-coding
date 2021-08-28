#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace sum_of_multiples
{
	int to(vector<int> multiples, int n)
	{
		vector<int> to_sum;
		// Go through all numbers from 1 to n
		// and modulo it by every element from
		// multiples vector.
		for(int i = 1; i < n; i++)
		{
			for(unsigned int j = 0; j < multiples.size(); j++)
			{
				if(i % multiples[j] == 0) {
					// Check if that number is already found
					// Don't add duplicates
					auto result = find(to_sum.begin(), to_sum.end(), i);
					if(result == to_sum.end())
					{
						to_sum.push_back(i);
					}
				}
			}
		}

		int sum = 0;
		// Add all found integers
		for(unsigned int i = 0; i < to_sum.size(); i++)
		{
			sum += to_sum[i];
		}

		return sum;
	}
}