#pragma once

namespace MapParser {

	struct MapID;
	struct MapSize;
	struct MapField;
	struct MapObject;
	class MapData;
	class RegexToken;

	struct Parser{
		static MapID parseMapID(RegexToken& _rt);
		static MapSize parseMapSize(RegexToken& _rt);
		static MapField parseMapField(RegexToken& _rt);
		static MapObject parseMapObject(RegexToken& _rt);
		static MapData parseMapData(RegexToken& _rt);
	};
}