#include <vector>

struct Solution
{
    static int findMaxConsecutiveOnes(std::vector<int>& _nums)
    {
        int ans = 0;
        int curr_run = 0;

        for (auto n : _nums) {
            if (n == 1) {
                curr_run++;
            } else {
                curr_run = 0;
            }
            ans = std::max(ans, curr_run);
        }

        return ans;
    }
};
