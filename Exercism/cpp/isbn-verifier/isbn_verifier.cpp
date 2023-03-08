#include "isbn_verifier.h"

namespace isbn_verifier {
  bool is_valid(string _s) {
    _s = regex_replace(_s, regex(R"([-])"), "");
  
    if(_s.length() != 10) { return false; }

    int sum = 0;
    int mod = 10;

    for(unsigned int i = 0; i < _s.length(); i++) {
      int n;

      if(i == 9 && _s[i] == 'X') {
        n = 10;
      } else {
        n = _s[i] - '0';
      }

      if(n < 0 || (n > 10 && i != 10)) { return false; }

      sum += n * mod;
      mod--;
    }

    return (sum % 11 == 0);
  }
}  // namespace isbn_verifier
