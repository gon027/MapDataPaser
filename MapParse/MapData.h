#pragma once

#include <string>
#include <vector>

namespace MapPaser {

	/// <summary>
	/// マップID
	/// </summary>
	struct MapID {
		int id;
	};

	/// <summary>
	/// マップの全体の大きさ
	/// </summary>
	struct MapSize {
		int width;
		int height;
	};

	/// <summary>
	/// マップのデータの配列
	/// </summary>
	struct MapData {
		std::vector<int> data;
	};

	/// <summary>
	/// マップに配置するオブジェクト
	/// </summary>
	class MapObject {
	private:
		struct MapInfo{
			int id;
			std::string object;
			std::string name;
			int x;
			int y;
			int width;
			int height;
		};

	public:
		std::vector<MapInfo> objects;
	};

	class Map {
	public:


	private:
		MapID mapID;
		MapSize mapSize;
		MapData mapData;
		MapObject mapObject;
	};
}