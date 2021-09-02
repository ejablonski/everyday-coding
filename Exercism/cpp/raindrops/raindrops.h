#include <iostream>
#include <string>

namespace raindrops
{
	std::string convert(int n)
	{
		std::string rain = "";

		if(n % 3 == 0)
		{
			rain += "Pling";
		}
		if(n % 5 == 0)
		{
			rain += "Plang";
		}
		if(n % 7 == 0)
		{
			rain += "Plong";
		}
		if(n % 3 != 0 && n % 5 != 0 && n % 7 != 0)
		{
			rain += std::to_string(n);
		}

		return rain;
	}
}
