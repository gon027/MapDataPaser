#pragma once

#include <string>
#include <vector>

namespace MapPaser {

	/// <summary>
	/// �}�b�vID
	/// </summary>
	struct MapID {
		int id;
	};

	/// <summary>
	/// �}�b�v�̑S�̂̑傫��
	/// </summary>
	struct MapSize {
		int width;
		int height;
	};

	/// <summary>
	/// �}�b�v�̃f�[�^�̔z��
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
	/// �}�b�v�ɔz�u����I�u�W�F�N�g
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