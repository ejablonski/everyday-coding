#include "binary_search.h"

namespace binary_search {
  size_t find(vector<int> _v, int _n) {
    auto lower = std::lower_bound(_v.begin(), _v.end(), _n);

    if(lower != _v.end() && !(_n < *lower)) {
      return std::distance(_v.begin(), lower);
    }

    throw std::domain_error("not found");
  }
}  // namespace binary_search
