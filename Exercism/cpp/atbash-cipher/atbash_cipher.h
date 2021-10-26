#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

namespace atbash_cipher
{
	string encode(string _s)
	{
		string plain = "abcdefghijklmnopqrstuvwxyz";
		string cipher = "zyxwvutsrqponmlkjihgfedcba";
		string encoded = "";

		transform(_s.begin(), _s.end(), _s.begin(), ::tolower);
		_s.erase(remove(_s.begin(), _s.end(), ' '), _s.end()); // fuck
		_s.erase(remove(_s.begin(), _s.end(), ','), _s.end()); // this
		_s.erase(remove(_s.begin(), _s.end(), '.'), _s.end()); // shit

		for(unsigned int i = 0; i < _s.length(); i++)
		{
			for(unsigned int j = 0; j < plain.length(); j++)
			{
				if(::isdigit(_s[i]))
				{
					encoded.push_back(_s[i]);
					break;
				}
				else if(_s[i] == plain[j])
				{
					encoded.push_back(cipher[j]);
					break;
				}
			}

			if((i + 1) % 5 == 0 && i != _s.length() - 1)
			{
				encoded.push_back(' ');
			}
		}

		return encoded;
	}

	string decode(string _s)
	{
		string plain = "abcdefghijklmnopqrstuvwxyz";
		string cipher = "zyxwvutsrqponmlkjihgfedcba";
		string decoded = "";

		transform(_s.begin(), _s.end(), _s.begin(), ::tolower);
		_s.erase(remove(_s.begin(), _s.end(), ' '), _s.end()); // fuck

		for(unsigned int i = 0; i < _s.length(); i++)
		{
			for(unsigned int j = 0; j < cipher.length(); j++)
			{
				if(::isdigit(_s[i]))
				{
					decoded.push_back(_s[i]);
					break;
				}
				else if(_s[i] == cipher[j])
				{
					decoded.push_back(plain[j]);
					break;
				}
			}
		}

		return decoded;
	}
}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H