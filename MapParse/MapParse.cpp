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

using namespace std;

MapPaser::MapID getMapID(MapPaser::RegexToken& _rt) {
	auto t = _rt.getToken();

	if (t.tokenType == MapPaser::TokenType::MapID) {
		_rt.getToken();
		auto val = _rt.getToken();

		return { std::stoi( val.data ) };
	}

	return { -1 };
}

MapPaser::MapSize getMapSize(MapPaser::RegexToken& _rt) {
	auto t = _rt.getToken();

	int width = 0;
	int height = 0;
	if (t.tokenType == MapPaser::TokenType::MapWide) {
		_rt.getToken();

		auto token = _rt.getToken();

		if (token.tokenType == MapPaser::TokenType::LeftHookBrack) {
			token = _rt.getToken();

			if (token.tokenType == MapPaser::TokenType::LeftBrackets) {
				token = _rt.getToken();

				if (token.tokenType == MapPaser::TokenType::Width) {
					_rt.getToken();
					auto widthToken = _rt.getToken();

					width = std::stoi(widthToken.data);
				}

				_rt.getToken();
				token = _rt.getToken();
				if (token.tokenType == MapPaser::TokenType::Height) {
					_rt.getToken();
					auto heightToken = _rt.getToken();

					height = std::stoi(heightToken.data);
				}
			}
			_rt.getToken();
		}
		_rt.getToken();
	}

	return { width, height };
}

MapPaser::MapField getMapData(MapPaser::RegexToken& _rt) {
	auto token = _rt.getToken();
	//cout << token.data << endl;
	
	//std::cout << (int)token.tokenType << " : " << token.data << std::endl;
	if (token.tokenType == MapPaser::TokenType::MapData) {
		_rt.getToken();
		
		std::vector<std::string> result;

		token = _rt.getToken();
		//std::cout << (int)token.tokenType << " : " << token.data << std::endl;

		while (token.tokenType != MapPaser::TokenType::RightHookBrack)
		{
			auto num = _rt.getToken();
			//std::cout << (int)num.tokenType << " : " << num.data << std::endl;
			result.emplace_back(num.data);

			//_rt.getToken();
			token = _rt.getToken();
		}

		return { result };
	}

	return { };
}

MapPaser::MapObject getMapObject(MapPaser::RegexToken& _rt) {
	auto token = _rt.getToken();  // TokenTypeがMapObjectか見る
	//std::cout << "MapObject = " << token.data << std::endl;

	if (token.tokenType != MapPaser::TokenType::MapObject) {
		return {};
	}

	_rt.getToken();  // イコールを外す

	token = _rt.getToken();
	//std::cout << "トークン1 = " << (int)token.tokenType << " : " << token.data << std::endl;


	MapPaser::MapObject result;
	while (token.tokenType != MapPaser::TokenType::RightHookBrack) {
		token = _rt.getToken();
		//std::cout << "トークン2 = " << (int)token.tokenType << " : " << token.data << std::endl;

		// ここで鉤括弧が閉まっていた場合
		if (token.tokenType == MapPaser::TokenType::RightHookBrack) {
			return {};
		}


		MapPaser::MapInfo md{};
		while (token.tokenType != MapPaser::TokenType::RightBrackets) {
			token = _rt.getToken();

			if (token.tokenType == MapPaser::TokenType::Name) {
				_rt.getToken();
				token = _rt.getToken();
				md.name = token.data;
			}
			else if (token.tokenType == MapPaser::TokenType::X){
				_rt.getToken();
				token = _rt.getToken();
				md.x = std::stoi(token.data);
			}
			else if (token.tokenType == MapPaser::TokenType::Y) {
				_rt.getToken();
				token = _rt.getToken();
				md.y= std::stoi(token.data);
			}
			else if (token.tokenType == MapPaser::TokenType::Width) {
				_rt.getToken();
				token = _rt.getToken();
				md.width = std::stoi(token.data);
			}
			else if (token.tokenType == MapPaser::TokenType::Height) {
				_rt.getToken();
				token = _rt.getToken();
				md.height = std::stoi(token.data);
			}
			else {
				continue;
			}

			token = _rt.getToken();
			//std::cout << (int)token.tokenType << " : " << token.data << std::endl;
		}

		result.objects.emplace_back(md);

		token = _rt.getToken();
	}
	

	return { result };
}

MapPaser::MapData parseMapData(MapPaser::RegexToken& _rt) {

	auto token = _rt.getToken();

	MapPaser::MapID mapId{};
	MapPaser::MapSize mapSize{};
	MapPaser::MapField mapField{};
	MapPaser::MapObject mapObject{};
	if (token.tokenType == MapPaser::TokenType::LeftBrackets) {
		while (token.tokenType != MapPaser::TokenType::RightBrackets) {

			mapId = getMapID(_rt);
			_rt.getToken();

			mapSize = getMapSize(_rt);
			_rt.getToken();

			mapField = getMapData(_rt);
			_rt.getToken();

			mapObject = getMapObject(_rt);

			token = _rt.getToken();
		}
	}

	return { mapId, mapSize, mapField, mapObject };
}

int main()
{	
	//MapPaser::RegexToken rt{ "{mapWide=[width=10,height=11]}" };
	//MapPaser::RegexToken rt{ "{mapWide={0, 2, 10, 100, 1000, 99}}" };
	//MapPaser::RegexToken rt{ "{mapObject={[name=10,x=120,y=130,width=300,height=499],[name=20,x=120,y=130,width=300,height=499],[name=20,x=12220,y=13220,width=32200,height=49229]}}" };
	MapPaser::RegexToken rt{ 
		"{[mapID=1,mapWide={[width=100,height=100]},mapData={0,2,10,100,1000,99},mapObject={[name=123,x=12,y=123,width=90,height=948],[name=123,x=12,y=123,width=90,height=948]}]}"
	};

	while (rt.isEof()) {
		auto t = rt.getToken();

		if (t.tokenType == MapPaser::TokenType::LeftHookBrack) {
			auto aa = parseMapData(rt);
			aa.debug();
		}
	}

	return 0;
}
