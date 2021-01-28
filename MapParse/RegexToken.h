#pragma once

#include <string>

namespace MapPaser {

	struct Token;

	class RegexToken {
	public:
		RegexToken(const std::string& _str);
		~RegexToken() = default;

		Token getToken();

	private:
		std::string str;
	};
}