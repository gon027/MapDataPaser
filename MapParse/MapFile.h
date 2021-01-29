#pragma once
#include <string>
#include <fstream>

namespace MapParser {

	inline std::string readMapFile() {
		std::fstream file("test_matdata.txt");
		if (!file) {
			//std::cout << "Read Error" << std::endl;
		}

		std::string str;
		std::string line;
		while (std::getline(file, line)) {
			str += line;
		}

		return str;
	}

}