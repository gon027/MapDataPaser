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
	struct MapField {
		std::vector<std::string> data;
	};

	struct MapInfo {
		int id;
		std::string object;
		std::string name;
		int x;
		int y;
		int width;
		int height;
	};

	/// <summary>
	/// マップに配置するオブジェクト
	/// </summary>
	struct MapObject {
		std::vector<MapInfo> objects;
	};

	class MapData {
	public:
		MapData(MapID _mapId, MapSize _mapSize, MapField _mapField, MapObject _mapObject);
		~MapData() = default;

		void debug();

	private:
		MapID mapID;
		MapSize mapSize;
		MapField mapField;
		MapObject mapObject;
	};
}