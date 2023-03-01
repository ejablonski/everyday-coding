#include "pangram.h"

namespace pangram {
  using namespace std;

  bool is_pangram(string _s) {
    vector<bool> mark(26, false);

    int index;

    for(unsigned int i = 0; i < _s.length(); i++) {
      if ('A' <= _s[i] && _s[i] <= 'Z')
        index = _s[i] - 'A';
      else if ('a' <= _s[i] && _s[i] <= 'z')
        index = _s[i] - 'a';
      else
        continue;

      mark[index] = true;
    }

    for(int i = 0; i <= 25; i++) {
      if (mark[i] == false)
        return (false);
    }

    return true;
  }
}  // namespace pangram
