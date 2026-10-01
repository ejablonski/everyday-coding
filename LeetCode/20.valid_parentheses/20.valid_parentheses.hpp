#include <stack>
#include <utility>
#include <vector>

struct Solution
{
    static bool isValid(std::string& _s)
    {
        if (_s.size() % 2 != 0) {
            return false;
        }

        std::vector<std::pair<char, char>> pars{{'(', ')'}, {'{', '}'}, {'[', ']'}};
        std::stack<char> stack;

        for (auto const c : _s) {
            for (auto const p : pars) {
                if (c == p.first) {
                    stack.push(c);
                }

                if (c == p.second) {
                    if (stack.empty()) {
                        return false;
                    }
                    if (stack.top() == p.first) {
                        stack.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return stack.empty();
    };
};
