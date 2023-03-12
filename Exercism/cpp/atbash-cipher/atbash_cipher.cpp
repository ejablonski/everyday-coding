#include "atbash_cipher.h"

namespace atbash_cipher {
  const string ALPHABET = "abcdefghijklmnopqrstuvwxyz0123456789";
  const string CIPHER = "zyxwvutsrqponmlkjihgfedcba0123456789";

  string encode(string _s) {
    return replace(_s, CIPHER, ALPHABET, true);
  }

  string decode(string _s) {
    return replace(_s, ALPHABET, CIPHER, false);
  }

  string replace(string _what, string _from, string _to, bool _seperate) {
    transform(_what.begin(), _what.end(), _what.begin(), ::tolower);
    _what = regex_replace(_what, regex(R"([,|.| ])"), "");

    string ret;

    for(unsigned int i = 0; i < _what.length(); i++) {
      if(_seperate && i != 0 && i % 5 == 0) {
        ret += " ";
      }

      ret += _to[_from.find(_what[i])];
    }

    return ret;
  }
}  // namespace atbash_cipher
