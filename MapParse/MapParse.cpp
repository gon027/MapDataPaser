#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "Token.h"
#include "RegexToken.h"

std::string readMapFile() {
	std::fstream file("test_matdata.txt");
	if (!file) {
		std::cout << "Read Error" << std::endl;
	}

	std::string str;
	std::string line;
	while (std::getline(file, line)) {
		str += line;
	}

	// std::cout << str << std::endl;

	return str;
}


int main()
{	
	MapPaser::RegexToken rt{ "{ Width=100 }" };
	while (rt.isEof()) {
		auto t = rt.getToken();
		std::cout << (int)t.tokenType << " : " << t.data << std::endl;
	}


	return 0;
}
