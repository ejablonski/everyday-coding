#include <string>

struct Solution
{
    static int minInsertions(std::string _s)
    {
        int open_bracket = 0;
        int insertions = 0;

        for (int i = 0; i < _s.size(); i++) {
            if (_s[i] == '(') {
                open_bracket++;
            }

            if (_s[i] == ')') {
                /**
                 * C++ strings ends with a null character (\0) so we can check for that to simplify
                 * if statement
                 */
                if (_s[i + 1] == '\0') {
                    insertions++;
                }

                if (_s[i + 1] == ')') {
                    i++;
                }

                if (open_bracket == 0) {
                    insertions++;
                } else {
                    open_bracket--;
                }
            }
        }

        return insertions + (open_bracket * 2);
    }
};
