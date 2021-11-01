#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H

#include <utility>
#include <string>

namespace robot_simulator {
	enum Bearing
	{
		NORTH = 0,
		EAST,
		SOUTH,
		WEST
	};

	class Robot
	{
	public:
		Robot(std::pair<int, int> _c = {0, 0}, Bearing _b = Bearing::NORTH)
		{
			coords = _c;
			bearing = _b;
		};

		std::pair<int, int> get_position() const
		{
			return coords;
		};

		Bearing get_bearing() const
		{
			return bearing;
		};

		void turn_right()
		{
			switch(bearing)
			{
			case Bearing::NORTH:
				bearing = Bearing::EAST;
				break;
			case Bearing::EAST:
				bearing = Bearing::SOUTH;
				break;
			case Bearing::SOUTH:
				bearing = Bearing::WEST;
				break;
			case Bearing::WEST:
				bearing = Bearing::NORTH;
				break;
			default:
				break;
			}
		};

		void turn_left()
		{
			switch(bearing)
			{
			case Bearing::NORTH:
				bearing = Bearing::WEST;
				break;
			case Bearing::EAST:
				bearing = Bearing::NORTH;
				break;
			case Bearing::SOUTH:
				bearing = Bearing::EAST;
				break;
			case Bearing::WEST:
				bearing = Bearing::SOUTH;
				break;
			default:
				break;
			}
		};

		void advance()
		{
			switch(bearing)
			{
			case Bearing::NORTH:
				coords.second++;
				break;
			case Bearing::EAST:
				coords.first++;
				break;
			case Bearing::SOUTH:
				coords.second--;
				break;
			case Bearing::WEST:
				coords.first--;
				break;
			default:
				break;
			}
		};

		void execute_sequence(std::string _s)
		{
			for(auto &it: _s)
			{
				switch(it)
				{
				case 'L':
					turn_left();
					break;
				case 'R':
					turn_right();
					break;
				case 'A':
					advance();
					break;
				default:
					break;
				}
			}
		};

	private:
		std::pair<int, int> coords;
		Bearing bearing;
	};
}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H
