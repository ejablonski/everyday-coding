#include "queen_attack.h"

namespace queen_attack {
	chess_board::chess_board()
	{
		whiteQ = {0, 3};
		blackQ = {7, 3};
	}

	chess_board::chess_board(std::pair<int, int> _w = {0, 3}, std::pair<int, int> _b = {7, 3})
	{
		if(_w == _b)
		{
			throw std::domain_error("no");
		}

		whiteQ = _w;
		blackQ = _b;
	}

	std::pair<int, int> chess_board::white() const
	{
		return whiteQ;
	}

	std::pair<int, int> chess_board::black() const
	{
		return blackQ;
	}

	bool chess_board::can_attack() const
	{
		if(whiteQ.first == blackQ.first || whiteQ.second == blackQ.second)
		{
			return true;
		}
		else if(std::abs(whiteQ.first - blackQ.first) == std::abs(whiteQ.second - blackQ.second))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	chess_board::operator std::string() const
	{
		std::string b = "";

		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(whiteQ.first == i && whiteQ.second == j)
				{
					b += "W ";
				}
				else if(blackQ.first == i && blackQ.second == j)
				{
					b += "B ";
				}
				else
				{
					j != 7 ? b += "_ " : b += "_";
				}
			}

			b += "\n";
		}

		return b;
	}
}  // namespace queen_attack
