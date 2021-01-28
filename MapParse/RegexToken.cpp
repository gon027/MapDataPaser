#include "RegexToken.h"
#include "Token.h"
#include <iostream>
#include <vector>
#include <regex>
#include <unordered_map>

namespace MapPaser {

	namespace {
		/// <summary>
		/// ���K�\���̃��X�g
		/// </summary>
		static std::vector<std::regex> regexs
		{
			std::regex("^(\\s|\\t)"),  // �󔒂��^�u
			std::regex("^\\d+"),       // ����
			std::regex("^\\{"),
			std::regex("^\\}"),
			std::regex("^\\["),
			std::regex("^\\]"),
			std::regex("^mapId"),
			std::regex("^mapWide"),
			std::regex("^mapData"),
			std::regex("^mapObject"),
			std::regex("^,"),
			std::regex("^="),
			std::regex("^Width"),
			std::regex("^Height"),
			std::regex("^Id"),
			std::regex("^Object"),
			std::regex("^Name"),
			std::regex("^X"),
			std::regex("^Y"),
		};

		/// <summary>
		/// �g�[�N���̕����񂩂�TokenType�ɕϊ�
		/// </summary>
		/// <param name="_token"> �g�[�N���̕����� </param>
		/// <returns> �ϊ����ꂽTokenType </returns>
		MapPaser::TokenType getTokenType(const std::string& _token) {
			static std::unordered_map<std::string, MapPaser::TokenType> tokenMap{
				{"{",         MapPaser::TokenType::LeftHookBrack},
				{"}",         MapPaser::TokenType::RightHookBrack},
				{"[",         MapPaser::TokenType::LeftBrackets},
				{"]",         MapPaser::TokenType::RightBrackets},
				{"mapID",     MapPaser::TokenType::MapID},
				{"mapWide",   MapPaser::TokenType::MapWide},
				{"mapData",   MapPaser::TokenType::MapData},
				{"mapObject", MapPaser::TokenType::MapObject},
				{",",         MapPaser::TokenType::Comma},
				{"=",         MapPaser::TokenType::Equal},
				{"Width",     MapPaser::TokenType::Width},
				{"Height",    MapPaser::TokenType::Height},
				{"ID",        MapPaser::TokenType::Id},
				{"Object",    MapPaser::TokenType::Object},
				{"Name",      MapPaser::TokenType::Name},
				{"X",         MapPaser::TokenType::X},
				{"Y",         MapPaser::TokenType::Y},
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
			return { MapPaser::TokenType::None, "None" };
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

		return { MapPaser::TokenType::None, "None" };
	}

	bool RegexToken::isEof()
	{
		return position < strSize;
	}
}