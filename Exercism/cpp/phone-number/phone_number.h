#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include <stdexcept>

using namespace std;

namespace phone_number
{
    class phone_number
    {
    private:
        string unformatted;
        string formatted;

    public:
        phone_number(string num)
        {
            unformatted = num;

            for(unsigned int i = 0; i < unformatted.length(); i++)
            {
                if(::isalpha(unformatted[i]))
                {
                    throw domain_error("No letters allowed in phone number.");
                }

                unformatted.erase(remove_if(unformatted.begin(), unformatted.end(), ::ispunct), unformatted.end());
                unformatted.erase(remove_if(unformatted.begin(), unformatted.end(), ::isspace), unformatted.end());
                unformatted.shrink_to_fit();
            }

            if(unformatted.size() < 10 || (unformatted.size() > 10 && unformatted[0] != '1') || unformatted.size() > 11)
            {
                throw domain_error("Invalid format.");
            }

            if(unformatted.size() > 10 && unformatted[0] == '1')
            {
                unformatted.erase(0, 1);
            }

            if(unformatted[0] == '1' || unformatted[0] == '0' || unformatted[3] == '0' || unformatted[3] == '1')
            {
                throw domain_error("Invalid format.");
            }

            formatted = "(" + unformatted.substr(0, 3) + ") " + unformatted.substr(3, 3) + "-" + unformatted.substr(6, 4);
        }

        string number() const
        {
            return unformatted;
        }

        string area_code() const
        {
            string code;

            for(int i = 0; i < 3; i++)
            {
                code.push_back(unformatted[i]);
            }

            return code;
        }

        operator std::string() const
        {
            return formatted;
        }
    };
}
