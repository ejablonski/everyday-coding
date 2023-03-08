#pragma once

#include <string>
#include <regex>

namespace isbn_verifier {
  using std::string, std::regex;

  bool is_valid(string);
} // namespace isbn_verifier
