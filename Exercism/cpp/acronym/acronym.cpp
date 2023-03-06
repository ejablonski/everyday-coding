#include "acronym.h"

namespace acronym {
  string acronym(string _s) {
    string ret = "";

    _s = regex_replace(_s, regex(R"([-| - | _|_ ])"), " ");

    stringstream ss(_s);
    string word = "";

    while(ss >> word) {
      ret += ::toupper(word[0]);
    }

    return ret;
  }
}  // namespace acronym
