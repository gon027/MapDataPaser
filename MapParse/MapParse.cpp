#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "Token.h"
#include "RegexToken.h"
#include "MapData.h"

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

	return str;
}

void parse(MapPaser::RegexToken& _rt) {

}

MapPaser::MapID getMapID(MapPaser::RegexToken& _rt) {
	auto t = _rt.getToken();

	if (t.tokenType == MapPaser::TokenType::MapID) {
		auto e = _rt.getToken();
		auto val = _rt.getToken();

			
		return { std::stoi( val.data ) };
	}

	return { 0 };
}

int main()
{	
	MapPaser::MapID mapId;

	MapPaser::RegexToken rt{ "{mapID=100,mapWide=[width=10,height=11],mapData={0,0,0},mapObject={[],[]}}" };
	while (rt.isEof()) {
		auto t = rt.getToken();

		// 空白を除去
		if (t.tokenType == MapPaser::TokenType::Space) {
			continue;
		}

		/*
		if (t.tokenType == MapPaser::TokenType::LeftHookBrack) {
			mapId = getMapID(rt);
			rt.getToken();
			break;
		}
		*/
		
		std::cout << (int)t.tokenType << " : " << t.data << std::endl;
	}


	//std::cout << mapId.id << std::endl;


	return 0;
}
