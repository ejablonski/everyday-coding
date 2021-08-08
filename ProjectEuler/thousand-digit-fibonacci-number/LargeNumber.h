#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace ln
{
    class LargeNumber
    {
    public:
        LargeNumber(std::string);

        static std::string add(LargeNumber&, LargeNumber&);
        std::string number() const;

        void operator=(std::string&);

    private:
        std::string s;
        unsigned int base = 10;
    };
}
