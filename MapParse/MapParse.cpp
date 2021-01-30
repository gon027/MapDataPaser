#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "Token.h"
#include "RegexToken.h"
#include "MapData.h"
#include "MapFile.h"
using namespace std;

MapParser::MapID getMapID(MapParser::RegexToken& _rt) {
	auto t = _rt.getToken();

	if (t.tokenType != MapParser::TokenType::MapID) {
		return { -1 };
	}

	_rt.getToken();
	auto val = _rt.getToken();

	return { std::stoi( val.data ) };
}

MapParser::MapSize getMapSize(MapParser::RegexToken& _rt) {
	auto t = _rt.getToken();

	if (t.tokenType != MapParser::TokenType::MapWide) {
		return { 0, 0 };
	}

	int width = 0;
	int height = 0;

	_rt.getToken();
	auto token = _rt.getToken();
	if (token.tokenType == MapParser::TokenType::LeftHookBrack) {
		token = _rt.getToken();

		if (token.tokenType == MapParser::TokenType::LeftBrackets) {
			token = _rt.getToken();

			if (token.tokenType == MapParser::TokenType::Width) {
				_rt.getToken();
				auto widthToken = _rt.getToken();

				width = std::stoi(widthToken.data);
			}

			_rt.getToken();
			token = _rt.getToken();
			if (token.tokenType == MapParser::TokenType::Height) {
				_rt.getToken();
				auto heightToken = _rt.getToken();

				height = std::stoi(heightToken.data);
			}
		}
		_rt.getToken();
	}
	_rt.getToken();
	
	return { width, height };
}

MapParser::MapField getMapData(MapParser::RegexToken& _rt) {
	auto token = _rt.getToken();
	//cout << token.data << endl;
	
	std::cout << (int)token.tokenType << " : " << token.data << std::endl;
	if (token.tokenType != MapParser::TokenType::MapData) {
		return {};
	}

	token = _rt.getToken();
	//std::cout << (int)token.tokenType << " : " << token.data << std::endl;

	std::vector<std::string> result;

	token = _rt.getToken();
	//std::cout << (int)token.tokenType << " : " << token.data << std::endl;

	while (token.tokenType != MapParser::TokenType::RightHookBrack)
	{
		auto num = _rt.getToken();
		//std::cout << (int)num.tokenType << " : " << num.data << std::endl;
		result.emplace_back(num.data);

		token = _rt.getToken();
	}

	return { result };
}

MapParser::MapObject getMapObject(MapParser::RegexToken& _rt) {
	auto token = _rt.getToken();  // TokenTypeがMapObjectか見る
	//std::cout << "MapObject = " << token.data << std::endl;

	if (token.tokenType != MapParser::TokenType::MapObject) {
		return {};
	}

	_rt.getToken();  // イコールを外す

	token = _rt.getToken();
	//std::cout << "トークン1 = " << (int)token.tokenType << " : " << token.data << std::endl;


	MapParser::MapObject result;
	while (token.tokenType != MapParser::TokenType::RightHookBrack) {
		token = _rt.getToken();
		//std::cout << "トークン2 = " << (int)token.tokenType << " : " << token.data << std::endl;

		// ここで鉤括弧が閉まっていた場合
		if (token.tokenType == MapParser::TokenType::RightHookBrack) {
			return {};
		}


		MapParser::MapInfo md{};
		while (token.tokenType != MapParser::TokenType::RightBrackets) {
			token = _rt.getToken();

			if (token.tokenType == MapParser::TokenType::Name) {
				_rt.getToken();
				token = _rt.getToken();
				md.name = token.data;
			}
			else if (token.tokenType == MapParser::TokenType::X){
				_rt.getToken();
				token = _rt.getToken();
				md.x = std::stoi(token.data);
			}
			else if (token.tokenType == MapParser::TokenType::Y) {
				_rt.getToken();
				token = _rt.getToken();
				md.y= std::stoi(token.data);
			}
			else if (token.tokenType == MapParser::TokenType::Width) {
				_rt.getToken();
				token = _rt.getToken();
				md.width = std::stoi(token.data);
			}
			else if (token.tokenType == MapParser::TokenType::Height) {
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

MapParser::MapData parseMapData(MapParser::RegexToken& _rt) {

	auto token = _rt.getToken();

	MapParser::MapID mapId{};
	MapParser::MapSize mapSize{};
	MapParser::MapField mapField{};
	MapParser::MapObject mapObject{};
	if (token.tokenType == MapParser::TokenType::LeftBrackets) {
		while (token.tokenType != MapParser::TokenType::RightBrackets) {

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
	/*MapParser::RegexToken rt{
		"{[mapID=1,mapWide={[width=100,height=100]},mapData={560,2,10,100,1000,99,0,0,0,9},mapObject={[name=123,x=12,y=123,width=90,height=948],[name=123,x=12,y=123,width=90,height=948]}]}"
	};
	*/

	auto a = MapParser::readMapFile("Test.txt");
	cout << a << endl;

	MapParser::RegexToken rt{ a };

	while (rt.isEof()) {
		auto t = rt.getToken();

		if (t.tokenType == MapParser::TokenType::LeftHookBrack) {
			auto aa = parseMapData(rt);
			aa.debug();
		}
	}

	return 0;
}
