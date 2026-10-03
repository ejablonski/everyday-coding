#include <string>
#include <vector>

struct Solution
{
    static void explore(std::string& _buffer, int _open, int _closed, int _size,
                        std::vector<std::string>& _ans)
    {
        if (_buffer.size() == 2 * _size) {
            _ans.push_back(_buffer);
            return;
        }

        if (_open < _size) {
            _buffer.push_back('(');
            explore(_buffer, _open + 1, _closed, _size, _ans);
            _buffer.pop_back();
        }

        if (_closed < _open) {
            _buffer.push_back(')');
            explore(_buffer, _open, _closed + 1, _size, _ans);
            _buffer.pop_back();
        }
    }
    static std::vector<std::string> generateParenthesis(int _n)
    {
        std::vector<std::string> ans;
        std::string buffer;

        explore(buffer, 0, 0, _n, ans);

        return ans;
    }
};
