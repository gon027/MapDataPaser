#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "Token.h"
#include "RegexToken.h"

void Main() {
	std::fstream file("test_matdata.txt");
	if (!file) {
		std::cout << "Read Error" << std::endl;
	}

	std::string str;
	std::string line;
	while (std::getline(file, line)) {
		str += line;
	}

	std::cout << str << std::endl;
}


int main()
{
	//Main();

	//auto t = getToken();
	//std::cout << t.data << std::endl;
	
	MapPaser::RegexToken rt{ "{ aaa }" };
	auto t = rt.getToken();
	std::cout << (int)t.tokenType << " : " << t.data << std::endl;


	return 0;
}
