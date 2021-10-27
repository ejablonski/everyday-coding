#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

namespace allergies
{
	class allergy_test
	{
	public:
		allergy_test(int);
		bool is_allergic_to(string);
		unordered_set<string> get_allergies();

	private:
		int score;
		vector<pair<int, string>> allergies = {{1, "eggs"}, {2, "peanuts"}, {4, "shellfish"}, {8, "strawberries"}, {16, "tomatoes"}, {32, "chocolate"}, {64, "pollen"}, {128, "cats"}};
		vector<pair<int, string>> reversed_allergies = {{128, "cats"}, {64, "pollen"}, {32, "chocolate"}, {16, "tomatoes"}, {8, "strawberries"}, {4, "shellfish"}, {2, "peanuts"}, {1, "eggs"}, };
	};
}  // namespace allergies

#endif // ALLERGIES_H
