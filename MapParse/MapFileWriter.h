#pragma once

#include <vector>
#include <string>


namespace MapParser {
	class MapData;
}

namespace MapFileWriter {
	using MapList = std::vector<MapParser::MapData>;

	void saveMapFile(const std::string& _filePath, MapList& _mapList);
}