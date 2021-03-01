#include "../MapFileWriter.h"
#include "MapData.h"
#include <fstream>
#include <iostream>

namespace MapFileWriter {

	namespace {

		const char newl = '\n';

		template<class T>
		std::string& operator<<(std::string& _str, T _type) {
			_str += std::to_string(_type);
			return _str;
		}

		template<>
		std::string& operator<<(std::string& _str, const char _c) {
			_str += _c;
			return _str;
		}

		template<>
		std::string& operator<<(std::string& _str, const char* _rstr) {
			_str += _rstr;
			return _str;
		}

		template<>
		std::string& operator<<(std::string& _str, std::string _rstr) {
			_str += _rstr;
			return _str;
		}

		void writeMapID(MapParser::MapID& _mapID, std::string& _str) {
			_str << "		" << "mapID = " << _mapID.id << "," << newl;
		}

		void writeMapSize(MapParser::MapSize& _mapSize, std::string& _str) {
			_str << "		" << "mapSize = " << newl;
			_str << "		" << "[" << newl;
			_str << "			" << "width = " << _mapSize.width << "," << newl;
			_str << "			" << "height = " << _mapSize.height << newl;
			_str << "		" << "]" << "," << newl;
		}

		void writeMapField(MapParser::MapField& _mapField, MapParser::MapSize _mapSize, std::string& _str) {
			_str << "		" << "mapField = " << newl;
			_str << "		" << "{" << newl;

			const size_t size = _mapSize.height * _mapSize.width;
			const size_t width = _mapSize.width;
			const size_t height = _mapSize.height;

			for (size_t y = 0; y < height; ++y) {
				_str << "			";
				for (size_t x = 0; x < width; ++x) {
					size_t index = x + width * y;
					_str << _mapField.data[index];

					if (index < (width * height - 1)) {
						_str << ", ";
					}
				}

				if (y != (size - 1)) {
					_str << newl;
				}
			}

			_str << newl << "		" << "}" << "," << newl;
		}

		void writeMapObject(MapParser::MapObject& _mapObject, std::string& _str) {
			_str << "		" << "mapObject = " << newl
				<< "		" << "{" << newl;

			for (size_t i{ 0 }; i < _mapObject.objects.size(); ++i) {
				_str << "			" << "[";
				_str << " name = " << _mapObject.objects[i].name << ", "
					<< "x = " << _mapObject.objects[i].x << ", "
					<< "y = " << _mapObject.objects[i].y << ", "
					<< "width = " << _mapObject.objects[i].width << ", "
					<< "height = " << _mapObject.objects[i].height << " ";
				_str << "]";

				if (i != (_mapObject.objects.size() - 1)) {
					_str << "," << newl;
				}
			}

			_str << newl << "		" << "}" << newl;
		}

		void writeMap(MapParser::MapData& _mapData, std::string& _str) {
			_str << "	" << "[" << newl;
			writeMapID(_mapData.getMapID(), _str);
			writeMapSize(_mapData.getMapSize(), _str);
			writeMapField(_mapData.getMapField(), _mapData.getMapSize(), _str);
			writeMapObject(_mapData.getMapObject(), _str);
			_str << "	" << "]";
		}
	}

	void MapFileWriter::saveMapFile(const std::string& _filePath, MapList& _mapList)
	{
		std::ofstream file{ _filePath };
		if (!file) {
			std::cout << "Error" << std::endl;
			return;
		}

		std::string str;
		str << "{" << newl;

		for (size_t i{ 0 }; i < _mapList.size(); ++i) {
			writeMap(_mapList[i], str);
			
			if (i != (_mapList.size() - 1)) {
				str << ',' << newl;
			}
		}		

		str << newl << "}" << newl;

		//std::cout << str << std::endl;

		file << str;
	}
}