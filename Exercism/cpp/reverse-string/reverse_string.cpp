#include "reverse_string.h"

namespace reverse_string {
  string reverse_string(string _s) {
    reverse(_s.begin(), _s.end());
    return _s;
  }
}  // namespace reverse_string
