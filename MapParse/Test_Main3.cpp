#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Token.h"
#include "RegexToken.h"
#include "MapData.h"
#include "MapFile.h"
#include "MapParser.h"
using namespace std;

char newl = '\n';

struct Data {
	string name;
	float x;
	float y;
	float width;
	float height;
};

ofstream out{ "outTest.txt" };

template<class T>
string& operator<<(string& _str, T _type) {
	_str += to_string(_type);
	return _str;
}

template<>
string& operator<<(string& _str, const char _c) {
	_str += _c;
	return _str;
}

template<>
string& operator<<(string& _str, const char* _rstr) {
	_str += _rstr;
	return _str;
}

template<>
string& operator<<(string& _str, string _rstr) {
	_str += _rstr;
	return _str;
}


void writeMapID(MapParser::MapID& _mapID, string& _str) {
	_str << "		" << "mapID = " << _mapID.id << "," << newl;
}

void writeMapSize(MapParser::MapSize& _mapSize, string& _str) {
	_str << "		"     << "mapSize = " << newl;
	_str << "		"     << "[" << newl;
	_str << "			" << "width = " << _mapSize.width << "," << newl;
	_str << "			" << "height = " << _mapSize.height << newl;
	_str << "		"     << "]" << "," << newl;
}

void writeMapField(MapParser::MapField& _mapField, size_t width, size_t height, string& _str) {
	_str << "		" << "mapField = " << newl;
	_str << "		" << "{" << newl;

	for (size_t y = 0; y < height; ++y) {
		_str << "			";
		for (size_t x = 0; x < width; ++x) {
			size_t index = x + width * y;
			_str << _mapField.data[index];

			if (index < (width * height - 1)) {
				_str << ", ";
			}
		}

		if (y != (5 - 1)) {
			_str << newl;
		}
	}

	_str << newl << "		" << "}" << "," << newl;
}

void writeMapObject(MapParser::MapObject& _mapObject, string& _str) {
	_str << "		" << "mapObject = " << newl
	     << "		" << "{" << newl;

	for (size_t i{ 0 }; i < _mapObject.objects.size(); ++i) {
		_str << "			" << "[";
		_str << " name = "    << _mapObject.objects[i].name   << ", "
				<< "x = "        << _mapObject.objects[i].x      << ", "
				<< "y = "        << _mapObject.objects[i].y      << ", "
				<< "width = "    << _mapObject.objects[i].width  << ", "
				<< "height = "   << _mapObject.objects[i].height << " ";
		_str << "]";

		if (i != (_mapObject.objects.size() - 1)) {
			_str << "," << newl;
		}
	}

	_str << newl << "		" << "}" << newl;
}

void writeMap(MapParser::MapData _mapData) {
	string line;

	line << "{" << newl;

	// ‚±‚±‚©‚ç‘‚«o‚·
	line << "	" << "[" << newl;

	/*
	{
		line << "		" << "mapID = " << 1 << "," << newl;
	}
	*/

	MapParser::MapID md{ 1 };
	writeMapID(md, line);

	/*
	{
		line << "		" << "mapSize = " << newl;

		{
			line << "		" << "[" << newl;
			{
				line << "			" << "width = " << 100 << "," << newl;
				line << "			" << "height = " << 100 << newl;
			}
			line << "		" << "]" << "," << newl;
		}
	}
	*/

	MapParser::MapSize ms{ 5, 5 };
	writeMapSize(ms, line);


	/*
	{
		line << "		" << "mapField = " << newl;

		line << "		" << "{" << newl;

		{

			vector<int> vec{
				1, 2, 3, 4, 5,
				6, 7, 8, 9, 10,
				11, 12, 13, 14, 15,
				16, 17, 18, 19, 20,
				21, 22, 23, 24, 25
			};

			for (size_t y = 0; y < 5; ++y) {
				line << "			";
				for (size_t x = 0; x < 5; ++x) {
					size_t index = x + 5 * y;
					line << vec[index];

					if (index < (5 * 5 - 1)) {
						line << ", ";
					}
				}

				if (y != (5 - 1)) {
					line << newl;
				}
			}
		}

		line << newl;
		line << "		" << "}" << "," << newl;
	}
	*/

	MapParser::MapField mf{ 
		{
			"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			"1", "2", "3", "4", "5"
		}
	};
	writeMapField(mf, ms.width, ms.height, line);

	/*
	{
		line << "		" << "mapObject = " << newl;
		line << "		" << "{" << newl;

		{
			vector<Data> vec{
				{"test1", 0, 0, 0, 0},
				{"test2", 1, 1, 1, 1},
				{"test3", 2, 2, 2, 2},
				{"test4", 3, 3, 3, 3},
				{"test5", 4, 4, 4, 4},
			};

			for (size_t i{ 0 }; i < 5; ++i) {
				line << "			" << "[";

				line << " name = " << vec[i].name << ", "
					<< "x = " << vec[i].x << ", "
					<< "y = " << vec[i].y << ", "
					<< "width = " << vec[i].width << ", "
					<< "height = " << vec[i].height << " ";


				line << "]";

				if (i != (5 - 1)) {
					line << "," << newl;
				}
			}

			line << newl;
		}

		line << "		" << "}" << newl;
	}
		
	*/

	MapParser::MapObject mo{};
	mo.objects.emplace_back(MapParser::MapInfo{ "111", 1, 2, 3, 4 });
	mo.objects.emplace_back(MapParser::MapInfo{ "111", 1, 2, 3, 4 });
	mo.objects.emplace_back(MapParser::MapInfo{ "111", 1, 2, 3, 4 });
	mo.objects.emplace_back(MapParser::MapInfo{ "111", 1, 2, 3, 4 });
	mo.objects.emplace_back(MapParser::MapInfo{ "111", 1, 2, 3, 4 });
	writeMapObject(mo, line);

	line << "	" << "]";

	/*
	if (d != (2 - 1)) {
		line << "," << newl;
	}*/


	line << newl << "}" << newl;

	std::cout << line << std::endl;
}

int main() {
	MapParser::MapData a{ {},{},{},{} };
	writeMap(a);
}