#include "crypto_square.h"

namespace crypto_square {
	cipher::cipher(std::string _s)
	{
		plain_text = _s;
	}

	std::string cipher::normalize_plain_text()
	{
		plain_text.erase(
			std::remove_if(
				plain_text.begin(),
				plain_text.end(),
				[](unsigned char c)
				{
					return (std::ispunct(c) || std::isspace(c));
				}
			),
			plain_text.end()
		);

		std::transform(plain_text.begin(), plain_text.end(), plain_text.begin(), ::tolower);

		return plain_text;
	}

	std::vector<std::string> cipher::plain_text_segments()
	{
		if(plain_text.length() == 0)
		{
			return {};
		}

		std::string s = normalize_plain_text();
		std::vector<std::string> v;

		float r = round(sqrt(s.length()));
		float c = round(s.length() / r);

		for(float i = 0; i < r; i++)
		{
			v.push_back(s.substr(i * c, c));
		}

		return v;
	}

	std::string cipher::cipher_text()
	{
		if(plain_text.length() == 0)
		{
			return "";
		}

		std::string s;
		std::vector<std::string> v = plain_text_segments();

		for(long unsigned int i = 0; i < v[0].length(); i++)
		{
			for(long unsigned int j = 0; j < v.size(); j++)
			{
				if(i < v[j].length())
				{
					s += v[j].substr(i, 1);
				}
			}
		}

		return s;
	}

	std::string cipher::normalized_cipher_text()
	{
		if(plain_text.length() == 0)
		{
			return "";
		}

		std::string s;
		std::vector<std::string> v = plain_text_segments();

		for(long unsigned int i = 0; i < v[0].length(); i++)
		{
			for(long unsigned int j = 0; j < v.size(); j++)
			{
				if(i < v[j].length())
				{
					s += v[j].substr(i, 1);
				}
				else
				{
					s += " ";
				}
			}

			if(i < v[0].length() - 1)
			{
				s += " ";
			}
		}

		return s;
	}

}  // namespace crypto_square
