#include <string>
#include <vector>

/**
 * Solution explanation: DP, 1D array solution.
 * Because every valid parentheses must end with ')' all we need is to traverse through whole
 * string, look for closing brackets and see what characters were **before** that. Thanks to 'dp'
 * array that tracks longest valid answer for every 'i' whole solution comes down to two if
 * statements.
 */
struct Solution
{
    [[nodiscard]]
    static int longestValidParentheses(std::string& _s)
    {
        int max_length = 0;
        // Vector initialiased to zeros so there is no need for dp[i] = 0 for some cases.
        std::vector<int> dp(_s.size(), 0);

        for (int i = 0; i < _s.size(); i++) {
            /**
             * If we find closing bracket and previous bracket was bracket opening then it is a
             * valid parentheses.
             */
            if (i > 0 && _s[i] == ')' && _s[i - 1] == '(') {
                dp[i] = 2 + (i > 1 ? dp[i - 2] : 0);
            }
            /**
             * If we find closing bracket and previous bracket was closing as well then we need to
             * check for nested parenthesis.
             */
            if (i > 0 && _s[i] == ')' && _s[i - 1] == ')') {
                int match_idx = i - dp[i - 1] - 1;
                if (match_idx >= 0 && _s[match_idx] == '(') {
                    dp[i] = 2 + dp[i - 1] + (match_idx > 1 ? dp[match_idx - 1] : 0);
                }
            }

            max_length = std::max(max_length, dp[i]);
        }

        return max_length;
    }
};
