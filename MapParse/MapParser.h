#pragma once

namespace MapParser {

	struct MapID;
	struct MapSize;
	struct MapField;
	struct MapObject;
	class MapData;
	class RegexToken;

	struct Parser{
		static MapID parseMapID(const RegexToken& _rt);
		static MapSize parseMapSize(const RegexToken& _rt);
		static MapField parseMapField(const RegexToken& _rt);
		static MapObject parseMapObject(const RegexToken& _rt);
		static MapData parseMapData(const RegexToken& _rt);
	};
}