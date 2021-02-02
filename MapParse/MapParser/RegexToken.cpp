#include "RegexToken.h"
#include "Token.h"
#include <iostream>
#include <vector>
#include <regex>
#include <unordered_map>

namespace MapParser {

	namespace {
		/// <summary>
		/// 正規表現のリスト
		/// </summary>
		static std::vector<std::regex> regexs
		{
			std::regex("^(\\s|\\t)"),       // 空白かタブ
			std::regex("^\\d+(\\.\\d+)?"),  // 整数または小数
			//std::regex("^\\d+"),          // 数字
			std::regex("^\\{"),
			std::regex("^\\}"),
			std::regex("^\\["),
			std::regex("^\\]"),
			std::regex("^mapID"),
			std::regex("^mapSize"),
			std::regex("^mapData"),
			std::regex("^mapObject"),
			std::regex("^,"),
			std::regex("^="),
			std::regex("^width"),
			std::regex("^height"),
			std::regex("^id"),
			std::regex("^object"),
			std::regex("^name"),
			std::regex("^x"),
			std::regex("^y"),
			std::regex("^[a-zA-Z]+"),       // 文字列
		};

		/// <summary>
		/// トークンの文字列からTokenTypeに変換
		/// </summary>
		/// <param name="_token"> トークンの文字列 </param>
		/// <returns> 変換されたTokenType </returns>
		MapParser::TokenType getTokenType(const std::string& _token) {
			static std::unordered_map<std::string, MapParser::TokenType> tokenMap{
				{" ",         MapParser::TokenType::Space},
				{"	",        MapParser::TokenType::Space},
				{"{",         MapParser::TokenType::LeftHookBrack},
				{"}",         MapParser::TokenType::RightHookBrack},
				{"[",         MapParser::TokenType::LeftBrackets},
				{"]",         MapParser::TokenType::RightBrackets},
				{"mapID",     MapParser::TokenType::MapID},
				{"mapWide",   MapParser::TokenType::MapWide},
				{"mapData",   MapParser::TokenType::MapData},
				{"mapObject", MapParser::TokenType::MapObject},
				{",",         MapParser::TokenType::Comma},
				{"=",         MapParser::TokenType::Equal},
				{"width",     MapParser::TokenType::Width},
				{"height",    MapParser::TokenType::Height},
				{"id",        MapParser::TokenType::Id},
				{"object",    MapParser::TokenType::Object},
				{"name",      MapParser::TokenType::Name},
				{"x",         MapParser::TokenType::X},
				{"y",         MapParser::TokenType::Y},
			};

			return tokenMap[_token];
		}
	}

	RegexToken::RegexToken(const std::string& _str)
		: str(_str)
		, strSize(_str.size())
		, position(0)
	{
	}

	Token RegexToken::getToken()
	{
		if (str.size() == 0) {
			return { MapParser::TokenType::None, "None" };
		}

		std::smatch sm;
		for (size_t i{ 0 }; i < regexs.size(); ++i) {
			auto flag = std::regex_search(str, sm, regexs[i]);
			if (flag) {
				auto token = sm.str();
				str = str.substr(sm.length());
				position += sm.length();

				return { getTokenType(token), token };
			}
		}

		return { MapParser::TokenType::None, "None" };
	}

	bool RegexToken::isEof()
	{
		return position < strSize;
	}
}