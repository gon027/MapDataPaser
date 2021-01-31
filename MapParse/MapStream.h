#pragma once

#include <vector>
#include "MapData.h"

namespace MapPasrer {

	using MapDataList = std::vector<int>;

	class MapFileWriter {
	public:
		MapFileWriter(MapDataList& _mapDataList);
		~MapFileWriter() = default;;

		void saveMapFile();

	private:
		MapDataList mapDataList;
	};
}