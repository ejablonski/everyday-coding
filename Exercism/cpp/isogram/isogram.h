#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#include <string>
#include <algorithm>
using namespace std;

namespace isogram
{
    bool is_isogram(string _s)
    {
        transform(_s.begin(), _s.end(), _s.begin(), ::tolower);
        _s.erase(remove(_s.begin(), _s.end(), ' '), _s.end());
        _s.erase(remove(_s.begin(), _s.end(), '-'), _s.end());
        sort(_s.begin(), _s.end());

        auto it = adjacent_find(_s.begin(), _s.end());

        return (it == _s.end());
    }
}  // namespace isogram

#endif // ISOGRAM_H