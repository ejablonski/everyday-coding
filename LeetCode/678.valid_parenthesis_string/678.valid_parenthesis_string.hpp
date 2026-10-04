#include <string>
#include <vector>

struct Solution
{
    [[nodiscard]]
    static bool checkValidString(std::string& _s)
    {
        /**
         * Need to track three states:
         *  - unvisited branch (-1)
         *  - visited and invalid (0)
         *  - visited and valid (1)
         */
        std::vector<std::vector<int>> memo(_s.size() + 1, std::vector<int>(_s.size() + 1, -1));
        return solve(_s, 0, 0, memo);
    }

    [[nodiscard]]
    static bool checkValidStringGreedy(std::string& _s)
    {
        int min_open = 0;
        int max_open = 0;

        for (auto const c : _s) {
            if (c == '(') {
                min_open++;
                max_open++;
            }

            if (c == ')') {
                min_open--;
                max_open--;
            }

            if (c == '*') {
                min_open--;
                max_open++;
            }

            if (max_open < 0) {
                return false;
            }

            min_open = std::max(min_open, 0);
        }
        return min_open == 0;
    }

  private:
    [[nodiscard]]
    static bool solve(std::string& _s, int _idx, int _open_count,
                      std::vector<std::vector<int>>& _memo)
    {
        if (_open_count < 0) {
            return false;
        }

        if (_memo[_idx][_open_count] != -1) {
            return _memo[_idx][_open_count];
        }

        if (_idx == _s.size() && _open_count == 0) {
            return true;
        }

        if (_s[_idx] == '(') {
            return _memo[_idx][_open_count] = solve(_s, _idx + 1, _open_count + 1, _memo);
        }

        if (_s[_idx] == ')') {
            return _memo[_idx][_open_count] = solve(_s, _idx + 1, _open_count - 1, _memo);
        }

        if (_s[_idx] == '*') {
            return _memo[_idx][_open_count] = solve(_s, _idx + 1, _open_count + 1, _memo) ||
                                              solve(_s, _idx + 1, _open_count - 1, _memo) ||
                                              solve(_s, _idx + 1, _open_count, _memo);
        }

        return false;
    }
};
