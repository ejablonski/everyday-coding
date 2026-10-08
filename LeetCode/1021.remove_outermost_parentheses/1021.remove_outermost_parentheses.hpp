#include <string>

struct Solution {
    static std::string removeOuterParentheses(std::string _s) {
      std::string ans = "";
      int counter = 0;

      for (auto const c : _s) {
        if (c == '(') {
          counter++;

          if (counter > 1) {
            ans += c;
          }
        }

        if (c == ')') {
          counter--;

          if (counter > 0) {
            ans += c;
          }
        }
      }

      return ans;
    }
};
