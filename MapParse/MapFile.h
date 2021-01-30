#pragma once
#include <string>
#include <fstream>
#include <iostream>

namespace MapParser {

	inline std::string readMapFile(const std::string& _file) {
		std::fstream file(_file);
		if (!file) {
			std::cout << "Read Error" << std::endl;
		}

		std::string str;
		std::string line;
		while (std::getline(file, line)) {
			line.erase(std::remove(line.begin(), line.end(), '	'), line.end());
			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
			str += line;
		}

		return str;
	}

}