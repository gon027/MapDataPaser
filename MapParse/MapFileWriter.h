#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "MapData.h"

namespace MapParser {

	using MapList = std::vector<MapData>;

	class MapFileWriter {
	public:
		MapFileWriter(const std::string& _outputFile);
		~MapFileWriter() = default;;

		void saveMapFile(MapList& _mapList);

	private:
		std::ofstream ofStream;
		MapList mapDataList;
	};
}