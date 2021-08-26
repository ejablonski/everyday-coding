#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace grade_school
{
	class school
	{
	private:
		map<int, vector<string>> db;

	public:
		map<int, vector<string>> roster() const
		{
			return db;
		}

		void add(const string &name, const int &grade)
		{
			db[grade].push_back(name);

			for(auto it = db.begin(); it != db.end(); it++)
			{
				sort(it->second.begin(), it->second.end());
			}

			sort(db[grade].begin(), db[grade].end());
		}

		vector<string> grade(const int &grade) const
		{
			if(db.empty())
			{
				return vector<string>();
			}
			else
			{
				return db.at(grade);
			}
		}
	};
}
