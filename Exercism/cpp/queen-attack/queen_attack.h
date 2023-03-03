#pragma once

#include <stdexcept>
#include <string>
#include <utility>

namespace queen_attack {
  class chess_board {
  public:
    chess_board();
    chess_board(std::pair<int, int>, std::pair<int, int>);

    std::pair<int, int> white() const;
    std::pair<int, int> black() const;
    bool can_attack() const;

    operator std::string() const;

  private:
    std::pair<int, int> whiteQ;
    std::pair<int, int> blackQ;
  };
}  // namespace queen_attack
