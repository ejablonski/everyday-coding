#include <iostream>
using namespace std;

namespace space_age
{
	// Year in a seconds for every planet
	struct in_seconds
	{
		static const unsigned int   EARTH       = 31557600;
		static const unsigned int   MERCURY     = 7600544;
		static const unsigned int   VENUS       = 19414149;
		static const unsigned int   MARS        = 59354033;
		static const unsigned int   JUPITER     = 374355659;
		static const unsigned int   SATURN      = 929292363;
		static const unsigned int   URANUS      = 2651370019;
		static const unsigned long  NEPTUNE     = 5200418560;
	};

	class space_age
	{
	private:
		double d_seconds;

	public:
		space_age(const double& d)
		{
			d_seconds = d;
		}

		// Return back seconds variable
		double seconds() const
		{
			return d_seconds;
		}

		float on_earth() const
		{
			return d_seconds / in_seconds::EARTH;
		}

		float on_mercury() const
		{
			return d_seconds / in_seconds::MERCURY;
		}

		float on_venus() const
		{
			return d_seconds / in_seconds::VENUS;
		}

		float on_mars() const
		{
			return d_seconds / in_seconds::MARS;
		}

		float on_jupiter() const
		{
			return d_seconds / in_seconds::JUPITER;
		}

		float on_saturn() const
		{
			return d_seconds / in_seconds::SATURN;
		}

		float on_uranus() const
		{
			return d_seconds / in_seconds::URANUS;
		}

		float on_neptune() const
		{
			return d_seconds / in_seconds::NEPTUNE;
		}
	};
}