#pragma once

#include <string>
#include <vector>
#include "MapData.h"

namespace MapFileReader {

	/// <summary>
	/// マップデータを読み取る
	/// </summary>
	/// <param name="_filePath"> マップデータのファイルパス </param>
	/// <returns></returns>
	std::vector<MapParser::MapData> readMapFile(const std::string& _filePath);

};