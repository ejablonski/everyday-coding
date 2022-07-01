#include "roman_numerals.h"

namespace roman_numerals {
	std::string convert(int _n)
	{
		std::map<std::string, int> values{
			{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90},
			{"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
		};

		const std::vector<std::string> orders{
			"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
		};

		std::string roman = "";

		for(const auto& c : orders)
		{
			while(_n >= values[c])
			{
				roman += c;
				_n -= values[c];
			};
		}

		return roman;
	}
}  // namespace roman_numerals
