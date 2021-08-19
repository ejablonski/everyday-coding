#include <string>
#include <vector>
#include <algorithm>

namespace anagram
{
class anagram
{
private:
	std::string base;

public:
	anagram(std::string);
	std::vector<std::string> matches(std::vector<std::string>);
};
}
