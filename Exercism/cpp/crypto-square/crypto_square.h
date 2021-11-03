#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>

namespace crypto_square {
	class cipher
	{
	public:
		cipher(std::string);
		std::string normalize_plain_text();
		std::vector<std::string> plain_text_segments();
		std::string cipher_text();
		std::string normalized_cipher_text();

	private:
		std::string plain_text;
	};
}  // namespace crypto_square

#endif // CRYPTO_SQUARE_H
