#include "luhn.h"

namespace luhn {
  bool valid(string _s) {
    _s.erase(remove(_s.begin(), _s.end(), ' '), _s.end());
    _s.erase(_s.begin(), find_if(_s.begin(), _s.end(), [](unsigned char ch) {
      return !isspace(ch);
    }));

    for(unsigned int i = 0; i < _s.length(); i++) {
      if(!isdigit(_s[i])) {
        return false;
      }
    }

    if(_s.length() <= 1) {
      return false;
    }

    long sum = 0;

    for(unsigned int i = 1; i < _s.length() + 1; i++) {
      if(i % 2 == 0) {
        int n = (stoi(to_string(_s[_s.length() - i])) - 48) * 2;

        if(n > 9)
            n -= 9;

        sum += n;
      } else {
        sum += (stoi(to_string(_s[_s.length() - i])) - 48);
      }
    }

    if(sum % 10 == 0) {
      return true;
    }

    return false;
  }
}  // namespace luhn
