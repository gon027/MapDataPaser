#pragma once

#include <string>
#include <vector>

namespace MapParser {

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

	/// <summary>
	/// オブジェクトのデータ情報
	/// </summary>
	struct MapInfo {
		std::string name;
		float x;
		float y;
		float width;
		float height;
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

		MapID& getMapID();
		MapSize& getMapSize();
		MapField& getMapField();
		MapObject& getMapObject();

	private:
		MapID mapID;
		MapSize mapSize;
		MapField mapField;
		MapObject mapObject;
	};
}