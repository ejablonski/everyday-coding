#include <vector>

struct Solution
{
    /**
     * ALGORITHM EXPLANATION: Stirling Numbers of the 1st Kind
     *
     * dp[n][k] = dp[n - 1][k - 1] + (n - 1) × dp[n - 1][k]
     */
    [[nodiscard]]
    static int rearrangeSticks(int _n, int _k)
    {
        std::vector<std::vector<long long>> dp(_n + 1, std::vector<long long>(_k + 1, 0));

        int MOD = 1e9 + 7;

        dp[1][1] = 1;

        for (int i = 2; i <= _n; ++i) {
            for (int j = 1; j <= _k; ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j]) % MOD;
            }
        }

        return dp[_n][_k];
    }
};
