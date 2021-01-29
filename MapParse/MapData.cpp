#include "MapData.h"
#include <iostream>

namespace MapPaser {

	MapData::MapData(MapID _mapId, MapSize _mapSize, MapField _mapField, MapObject _mapObject)
		: mapID(_mapId)
		, mapSize(_mapSize)
		, mapField(_mapField)
		, mapObject(_mapObject)
	{
	}

	void MapData::debug()
	{
		using namespace std;
		
		cout << endl;

		cout << "--- Debug ---" << endl;

		cout << "ID = " << mapID.id << endl;
		cout << "Size = " << mapSize.width << " : " << mapSize.height << endl;
		cout << "--- Field ---" << endl;
		for (auto& e : mapField.data) {
			cout << e << ", ";
		}
		cout << endl;

		cout << "--- Objects ---" << endl;
		for (auto& e : mapObject.objects) {
			cout << "Name = "   << e.name << endl;
			cout << "X = "      << e.x << endl;
			cout << "Y = "      << e.y << endl;
			cout << "Width = "  << e.width << endl;
			cout << "Height = " << e.height << endl;
			cout << "----------" << endl;
		}
		cout << endl;
	}
}
