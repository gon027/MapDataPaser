#pragma once

#include <string>
#include <vector>

namespace MapParser {

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

	/// <summary>
	/// �I�u�W�F�N�g�̃f�[�^���
	/// </summary>
	struct MapInfo {
		std::string name;
		float x;
		float y;
		float width;
		float height;
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