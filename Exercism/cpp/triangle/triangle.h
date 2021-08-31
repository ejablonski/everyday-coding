#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <algorithm>
#include <array>
#include <stdexcept>

namespace triangle
{
	enum flavor
	{
		equilateral = 0,
		isosceles   = 1,
		scalene     = 2
	};

	int kind(const double& x, const double& y, const double& z)
	{
		// Sort side lengths for easier comparing of sides
		std::array<double, 3> t = {x, y, z};
		std::sort(t.begin(), t.end());

		// Error handling
		// Throw exception if triangle can't be build with passed variables
		if(t[0] <= 0 || t[1] <= 0 || t[2] <= 0)
		{
			throw std::domain_error("Triangle sides can't be smaller then 0.");
		}

		if(t[0] + t[1] < t[2])
		{
			throw std::domain_error("Violating triangle inequality.");
		}

		// If every side is equal return equilateral
		if(t[0] == t[1] && t[1] == t[2])
		{
			return equilateral;
		}

		// If two biggest sides are equal return isosceles
		if(t[1] == t[2])
		{
			return isosceles;
		}

		// If non of sides is equal to another then return scalene
		if(t[0] != t[1] && t[1] != t[2] && t[2] != t[0])
		{
			return scalene;
		}

		return -1;
	}
}

#endif
