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
	struct MapData {
		std::vector<int> data;
	};

	/// <summary>
	/// �}�b�v�ɔz�u����I�u�W�F�N�g
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