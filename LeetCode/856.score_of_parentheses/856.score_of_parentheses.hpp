#include <string>

/**
 * Solution: Found a hint about this solution on one of the comments of this problem on LeetCode.
 * It's about tracking depth of the parentheses and based on that calculate the score. To determine
 * the depth one needs to check for brackets (where ( increases the depth and ) decreases). Finding
 * the core (the deepest bracket) triggers scoring where one can use bitwise operator to add the
 * score (by adding 2^depth).
 */
struct Solution
{
    static int scoreOfParentheses(std::string& _s)
    {
        int depth = 0;
        int score = 0;

        for (int i = 0; i < _s.size(); i++) {
            if (_s[i] == '(') {
                depth++;
            }

            if (_s[i] == ')') {
                depth--;

                if (i > 0 && _s[i - 1] == '(') {
                    score += 1 << depth;
                }
            }
        }

        return score;
    }
};
