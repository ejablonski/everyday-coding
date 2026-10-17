#include <vector>

struct Solution
{
    [[nodiscard]]
    static int timeRequiredToBuy(std::vector<int>& _tickets, int _k)
    {
        int time_passed = 0;
        int idx = 0;
        int max_idx = _tickets.size() - 1;

        while (_tickets[_k] > 0) {
            if (_tickets[idx] != 0) {
                _tickets[idx]--;
                time_passed++;
            }

            if (idx == max_idx) {
                idx = 0;
            } else {
                idx++;
            }
        }

        return time_passed;
    }
};
