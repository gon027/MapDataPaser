#pragma once

#include <string>

namespace MapParser {

	struct Token;

	class RegexToken {
	public:
		RegexToken(const std::string& _str);
		~RegexToken() = default;

		Token getToken();

		bool isEof();

	private:
		std::string str;
		int strSize;
		int position;
	};
}