#include <vector>

struct Solution
{
    [[nodiscard]]
    static int minOperations(std::vector<int>& _nums)
    {
        int n = _nums.size();

        if (n <= 1) {
            return 0;
        }

        int drops = 0;
        int rises = 0;
        int idx0 = -1;

        // Count structural breaks to identify the type of rotated array
        for (int i = 0; i < n; ++i) {
            if (_nums[i] == 0) {
                idx0 = i;
            }
            if (_nums[i] > _nums[(i + 1) % n]) {
                drops++;
            }
            if (_nums[i] < _nums[(i + 1) % n]) {
                rises++;
            }
        }

        if (drops == 1) {
            return std::min(idx0, n - idx0 + 2);
        }

        if (rises == 1) {
            return std::min(n - idx0, idx0 + 2);
        }

        return -1;
    }
};
