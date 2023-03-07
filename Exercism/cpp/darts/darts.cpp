#include "darts.h"

namespace darts {
  /**
   * @brief Calculates diameter of a circle.
   * 
   * @param _x X coord
   * @param _y Y coord
   * @return constexpr float Diameter of a circle
   */
  constexpr float diameter(float _x, float _y) {
    return sqrt(pow(_x - 0, 2) + pow(_y - 0, 2));
  }

  /**
   * @brief Map of points to radi of the circles.
   * First value is a radius, second is a amount of points.
   */
  const std::vector<std::pair<float, int>> MAP{{1, 10}, {5, 5}, {10, 1}};

  /**
   * @brief Dart is inside one of the circles if its diameter is lower
   * than radius of the cirlce.
   * 
   * @param _x X coord
   * @param _y Y coord
   * @return int Amount of points
   */
  int score(float _x, float _y) {
    const float D_HIT = diameter(_x, _y);

    for(auto &p: MAP) {
      if(D_HIT <= p.first) { return p.second; };
    }

    return 0;
  }
} // namespace darts
