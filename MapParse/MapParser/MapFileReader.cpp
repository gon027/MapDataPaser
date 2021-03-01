#include "../MapFileReader.h"
#include "RegexToken.h"
#include "MapData.h"
#include "Token.h"
#include "MapFile.h"
#include <fstream>
#include <iostream>
using namespace std;

namespace MapFileReader {

	namespace {

		// 文字列からMapIDを解析する
		MapParser::MapID parseMapID(MapParser::RegexToken& _rt) {
			auto token = _rt.getToken();

			if (token.tokenType != MapParser::TokenType::MapID) {
				return { -1 };
			}

			_rt.getToken();
			auto val = _rt.getToken();

			return { std::stoi(val.data) };
		}

		// 文字列からMapSizeを解析する
		MapParser::MapSize parseMapSize(MapParser::RegexToken& _rt) {
			auto token = _rt.getToken();

			if (token.tokenType != MapParser::TokenType::MapSize) {
				return { 0, 0 };
			}

			int width = 0;
			int height = 0;

			_rt.getToken();
			token = _rt.getToken();

			if (token.tokenType == MapParser::TokenType::LeftBrackets) {
				token = _rt.getToken();

				if (token.tokenType == MapParser::TokenType::Width) {
					_rt.getToken();
					auto widthToken = _rt.getToken();

					width = std::stoi(widthToken.data);
				}

				_rt.getToken();
				token = _rt.getToken();
				if (token.tokenType == MapParser::TokenType::Height) {
					_rt.getToken();
					auto heightToken = _rt.getToken();

					height = std::stoi(heightToken.data);
				}
			}
			_rt.getToken();

			return { width, height };
		}

		// 文字列からMapFieldを解析する
		MapParser::MapField parseMapField(MapParser::RegexToken& _rt) {

			auto token = _rt.getToken();
			if (token.tokenType != MapParser::TokenType::MapField) {
				return {};
			}

			token = _rt.getToken();

			std::vector<std::string> result;

			token = _rt.getToken();

			while (token.tokenType != MapParser::TokenType::RightHookBrack)
			{
				auto num = _rt.getToken();
				result.emplace_back(num.data);

				token = _rt.getToken();
			}

			return { result };
		}

		// 文字列からMapObjectを解析する
		MapParser::MapObject parseMapObject(MapParser::RegexToken& _rt) {
			auto token = _rt.getToken();  // TokenTypeがMapObjectか見る

			if (token.tokenType != MapParser::TokenType::MapObject) {
				return {};
			}

			_rt.getToken();  // イコールを外す

			token = _rt.getToken();

			MapParser::MapObject result;
			while (token.tokenType != MapParser::TokenType::RightHookBrack) {
				token = _rt.getToken();

				// ここで鉤括弧が閉まっていた場合
				if (token.tokenType == MapParser::TokenType::RightHookBrack) {
					return {};
				}

				MapParser::MapInfo md{};
				while (token.tokenType != MapParser::TokenType::RightBrackets) {
					token = _rt.getToken();

					if (token.tokenType == MapParser::TokenType::Name) {
						_rt.getToken();
						token = _rt.getToken();
						md.name = token.data;
					}
					else if (token.tokenType == MapParser::TokenType::X) {
						_rt.getToken();
						token = _rt.getToken();
						md.x = std::stof(token.data);
					}
					else if (token.tokenType == MapParser::TokenType::Y) {
						_rt.getToken();
						token = _rt.getToken();
						md.y = std::stof(token.data);
					}
					else if (token.tokenType == MapParser::TokenType::Width) {
						_rt.getToken();
						token = _rt.getToken();
						md.width = std::stof(token.data);
					}
					else if (token.tokenType == MapParser::TokenType::Height) {
						_rt.getToken();
						token = _rt.getToken();
						md.height = std::stof(token.data);
					}
					else {
						continue;
					}

					token = _rt.getToken();
				}

				result.objects.emplace_back(md);

				token = _rt.getToken();
			}

			return { result };
		}

		// MapDataを解析する
		MapParser::MapData parseMapData(MapParser::RegexToken& _rt) {
			auto token = _rt.getToken();

			MapParser::MapID mapId{};
			MapParser::MapSize mapSize{};
			MapParser::MapField mapField{};
			MapParser::MapObject mapObject{};
			if (token.tokenType == MapParser::TokenType::LeftBrackets) {
				while (token.tokenType != MapParser::TokenType::RightBrackets) {

					mapId = parseMapID(_rt);
					_rt.getToken();   // カンマを外す

					mapSize = parseMapSize(_rt);
					_rt.getToken();   // カンマを外す

					mapField = parseMapField(_rt);
					_rt.getToken();   // カンマを外す

					mapObject = parseMapObject(_rt);

					token = _rt.getToken();
				}
			}

			return { mapId, mapSize, mapField, mapObject };
		}
	}

    std::vector<MapParser::MapData> readMapFile(const std::string& _filePath)
    {
		auto str = MapParser::readMapFile(_filePath);
		MapParser::RegexToken rt{ str };

		std::vector<MapParser::MapData> result;
		while (rt.isEof()) {
			auto token = rt.getToken();

			if (token.tokenType != MapParser::TokenType::LeftHookBrack) {
				return result;
			}

			while (token.tokenType != MapParser::TokenType::RightHookBrack) {
				auto data = parseMapData(rt);
				result.emplace_back(data);
				token = rt.getToken();
			}
		}

		return result;
    }
}