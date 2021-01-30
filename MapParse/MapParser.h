#pragma once

#include <vector>

namespace MapParser {
	class MapData;
	class RegexToken;

	std::vector<MapData> createMapData(RegexToken& _rt);
}