#pragma once

#include <string>
#include <vector>
#include "MapData.h"

namespace MapFileReader {

	/// <summary>
	/// �}�b�v�f�[�^��ǂݎ��
	/// </summary>
	/// <param name="_filePath"> �}�b�v�f�[�^�̃t�@�C���p�X </param>
	/// <returns></returns>
	std::vector<MapParser::MapData> readMapFile(const std::string& _filePath);

};