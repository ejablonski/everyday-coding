#if !defined(COLLATZ_CONJECTURE_H)
#define COLLATZ_CONJECTURE_H

#include <stdexcept>

namespace collatz_conjecture
{
	int steps(int _n)
	{
		if(_n <= 0)
		{
			throw std::domain_error("Invalid arguments.");
		}

		int step = 0;

		while(_n != 1)
		{
			if(_n % 2 == 0)
			{
				_n /= 2;
				step++;
			}
			else
			{
				_n = _n * 3 + 1;
				step++;
			}
		}

		return step;
	}
}  // namespace collatz_conjecture

#endif // COLLATZ_CONJECTURE_H
