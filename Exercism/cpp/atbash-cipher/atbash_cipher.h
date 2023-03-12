#pragma once

#include <string>
#include <algorithm>
#include <regex>

namespace atbash_cipher {
    using namespace std;

    string encode(string);
    string decode(string);
    string replace(string, string, string, bool);
}  // namespace atbash_cipher
