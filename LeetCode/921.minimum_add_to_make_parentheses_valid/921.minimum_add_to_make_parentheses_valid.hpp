#include <string>

struct Solution
{
    [[nodiscard]]
    static int minAddToMakeValid(const std::string& s)
    {
        int open_waiting = 0;
        int insertions_needed = 0;

        for (char c : s) {
            if (c == '(') {
                ++open_waiting;
            } else {
                if (open_waiting > 0) {
                    --open_waiting;
                } else {
                    ++insertions_needed;
                }
            }
        }

        return insertions_needed + open_waiting;
    }
};
