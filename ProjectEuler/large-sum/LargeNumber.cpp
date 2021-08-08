#include "LargeNumber.h"

namespace ln
{
    LargeNumber::LargeNumber(std::string _s) : s(_s) {};

    std::string LargeNumber::number() const
    {
        return s;
    }

    std::string LargeNumber::add(LargeNumber& _ln, LargeNumber& _rn)
    {
        std::string sl = _ln.number();
        std::string sr = _rn.number();

        std::vector<int> vl;
        std::vector<int> vr;
        std::vector<int> vsum;

        vl.resize(sr.length() >= sl.length() ? sr.length() : sl.length());
        vr.resize(sr.length() >= sl.length() ? sr.length() : sl.length());

        if(sr.length() > sl.length())
        {
            sl.insert(0, sr.length() - sl.length(), '0');
        }

        if (sl.length() > sr.length())
        {
            sr.insert(0, sl.length() - sr.length(), '0');
        }

        for(unsigned int i = 0; i < sr.length(); i++)
        {
            vl[i] = (std::stoi(std::to_string(sl[i])) - 48);
            vr[i] = (std::stoi(std::to_string(sr[i])) - 48);
        }

        std::reverse(vl.begin(), vl.end());
        std::reverse(vr.begin(), vr.end());

        bool reminder = false;

        for(unsigned int i = 0; i < vl.size(); i++)
        {
            if(reminder)
            {
                vl[i]++;
            }

            if(vl[i] + vr[i] > 9)
            {
                vsum.push_back((vl[i] + vr[i]) - 10);
                reminder = true;
            }
            else
            {
                vsum.push_back(vl[i] + vr[i]);
                reminder = false;
            }
        }

        if(reminder)
        {
            vsum.push_back(1);
        }

        std::reverse(vsum.begin(), vsum.end());
        std::string ret;

        for(unsigned int i = 0; i < vsum.size(); i++)
        {
            char c = vsum[i] + 48;
            ret.push_back(c);
        }

        return ret;
    };

    void LargeNumber::operator=(std::string& _s)
    {
        s = _s;
    }
}
