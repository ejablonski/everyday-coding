#include <algorithm>
#include <stack>
#include <string>
#include <vector>

/**
 * Learning Journal:
 * - Pattern: Stack (Last-In, First-Out)
 * - Aha! Moment: Reverse Polish Notation evaluates left-to-right naturally using a stack.
 *   By replacing an if-else string comparison chain with a `switch` statement on a single `char`
 * (`t[0]`), the compiler optimizes the branching (via a jump table), yielding a massive performance
 * boost.
 * - Trap: Order of operands matters immensely for subtraction and division!
 *   The first item popped is the RIGHT operand, the second popped is the LEFT operand (i.e. `b -
 * a`, not `a - b`).
 */

struct Solution
{
    static int evalRPN(std::vector<std::string>& _tokens)
    {
        std::stack<int> s{};
        std::vector<std::string> ops{"+", "-", "*", "/"};

        for (const auto& t : _tokens) {
            // We are assuming that two first tokens will be numbers!
            if (std::ranges::find(ops, t) != ops.end()) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                switch (t[0]) {
                    case '+': {
                        s.push(b + a);
                        break;
                    }
                    case '-': {
                        s.push(b - a);
                        break;
                    }
                    case '*': {
                        s.push(b * a);
                        break;
                    }
                    case '/': {
                        s.push(b / a);
                        break;
                    }
                    default: {
                        break;
                    }
                }

            } else {
                s.push(std::stoi(t));
            }
        }

        return s.top();
    }
};
