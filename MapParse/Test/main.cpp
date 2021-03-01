#include <iostream>
#include <string>
#include <vector>
#include "../MapParser/Token.h"
#include "../MapParser/MapFile.h"
#include "../MapParser/MapData.h"
#include "../MapFileReader.h"
#include "../MapFileWriter.h"

// マップを読み込む用のデバッグ関数
void test_readMap() {
	// マップファイルを読み込む
	auto mapList = MapFileReader::readMapFile("data/input.txt");

	// デバッグ用
	for (auto& map : mapList) {
		map.debug();
	}
}

// マップに書き込む用のデバッグ関数
void test_writeMap() {
	// マップIDの作成
	MapParser::MapID mapID{ 1 };

	// マップサイズの作成
	MapParser::MapSize mapSize{ 5, 5 };

	// マップのフィールドの作成
	// 注意 : マップのフィールドは、mapSizeの大きさでなければならない
	MapParser::MapField mapField{
		{ 
			"1", "2", "3", "4", "5",
			"6", "7", "8", "9", "10",
			"11", "12", "13", "14", "15",
			"16", "17", "18", "19", "20",
			"21", "22", "23", "24", "25"
		}
	};

	// マップに配置するオブジェクトを作成
	MapParser::MapObject mapObject{
		{
			{ "object1", 100.0, 100.0, 50.0, 50.0 },
			{ "object2", 200.0, 200.0, 50.0, 50.0 },
			{ "object3", 300.0, 300.0, 50.0, 50.0 },
			{ "object4", 400.0, 400.0, 50.0, 50.0 },
		}
	};

	// MapDataの作成
	MapParser::MapData map{
		mapID, mapSize, mapField, mapObject
	};

	// マップID(2つめを作成)
	MapParser::MapID mapID1{ 2 };

	// MapDataの作成
	MapParser::MapData map1{
		mapID1, mapSize, mapField, mapObject
	};

	// 作成したMapDataをMapListに登録
	MapFileWriter::MapList mapList{
		map, map1
	};

	// マップを書き出す
	MapFileWriter::saveMapFile("data/output.txt", mapList);
}

int main()
{
	test_readMap();

	//test_writeMap();

	return 0;
}