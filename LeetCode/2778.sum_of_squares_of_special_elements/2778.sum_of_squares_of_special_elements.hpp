#include <vector>
struct Solution
{
    [[nodiscard]]
    static int sumOfSquares(std::vector<int>& _nums)
    {
        int n = _nums.size();
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += _nums[i - 1] * _nums[i - 1];
            }
        }
        return sum;
    }
};
