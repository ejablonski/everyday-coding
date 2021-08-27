#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

namespace robot_name
{
	class robot
	{
	private:
		string s_name;
		vector<string> db;

		void add_to_db(const string s)
		{
			db.push_back( s );
		}

		// check if name already exists in db, if so return false, otherwise true
		bool is_valid(const string s)
		{
			auto result = find(db.begin(), db.end(), s);

			if(result != db.end())
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void create_name()
		{
			// randomize int from a range 1-999 for a number part of a robot name
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> dis_n(0, 999);
			int number = dis_n( gen );

			// int to string converstion
			// if randomized number is lower then 100, insert zeros at the begining
			string s_number;
			if(number < 100)
			{
				s_number = to_string(number);
				while(s_number.length() < 3)
				{
					s_number.insert(0, 1, '0');
				}
			}
			else
			{
				s_number = to_string(number);
			}

			// randomize int for a char part of a robot name
			// ASCII codes for uppercase characters are in range 65-90
			uniform_int_distribution<> dis_c_a(65, 90);
			uniform_int_distribution<> dis_c_b(65, 90);
			char char_a = dis_c_a(gen);
			char char_b = dis_c_b(gen);
			// I found that inserting chars into string is a easiest way
			// also that's the only way that worked
			s_number.insert(s_number.begin(), char_a);
			s_number.insert(s_number.begin(), char_b);
			
			s_name = s_number;
			add_to_db(s_number);
		}

	public:
		robot()
		{
			create_name();
		}

		string name() const
		{
			return s_name;
		}

		void reset()
		{
			// create new name and if it's not valid, create new one till
			// it's valid
			create_name();
			if(is_valid(name())) {
				while(!is_valid(name())) {
					create_name();
				}
			}
		}
	};
}
