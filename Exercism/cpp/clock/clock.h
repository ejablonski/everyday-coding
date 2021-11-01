#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace date_independent
{
	class clock
	{
	public:
		static string at(int _h, int _m)
		{
			int h = 0;
			int m = _m + _h * 60;

			if(m < 0)
			{
				h = 24;

				while(m < 0)
				{
					h--;
					m += 60;

					if(h == 0)
						h = 24;
				}
			}
			else
			{
				while(m >= 60)
				{
					h++;
					m -= 60;

					if(h == 24)
						h = 0;
				}
			}

			string hours = to_string(h);
			string minutes = to_string(m);

			if(h < 10)
				hours.insert(hours.begin(), '0');

			if(m < 10)
				minutes.insert(minutes.begin(), '0');

			return hours + ":" + minutes;
		}
	};
}  // namespace date_independent

#endif // CLOCK_H
