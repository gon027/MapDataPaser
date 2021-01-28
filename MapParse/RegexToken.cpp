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
			std::regex("^mapID"),
			std::regex("^mapWide"),
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
		};

		/// <summary>
		/// �g�[�N���̕����񂩂�TokenType�ɕϊ�
		/// </summary>
		/// <param name="_token"> �g�[�N���̕����� </param>
		/// <returns> �ϊ����ꂽTokenType </returns>
		MapPaser::TokenType getTokenType(const std::string& _token) {
			static std::unordered_map<std::string, MapPaser::TokenType> tokenMap{
				{" ",         MapPaser::TokenType::Space},
				{"	",        MapPaser::TokenType::Space},
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
				{"width",     MapPaser::TokenType::Width},
				{"height",    MapPaser::TokenType::Height},
				{"id",        MapPaser::TokenType::Id},
				{"object",    MapPaser::TokenType::Object},
				{"name",      MapPaser::TokenType::Name},
				{"x",         MapPaser::TokenType::X},
				{"y",         MapPaser::TokenType::Y},
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