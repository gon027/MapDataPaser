#pragma once

#include <string>

namespace MapPaser {

	/// <summary>
	/// トークンのタイプ
	/// </summary>
	enum class TokenType : unsigned int {
		None,
		Space,
		LeftHookBrack,   // 左鉤括弧
		RightHookBrack,  // 右鉤括弧
		LeftBrackets,    // 左括弧
		RightBrackets,   // 右括弧
		MapID,           // マップID
		MapWide,         // マップの広さ
		MapData,         // マップデータ
		MapObject,       // マップのオブジェクト
		Comma,           // カンマ
		Equal,           // イコール 
		Width,
		Height,
		Id,
		Object,
		Name,
		X,
		Y
	};

	/// <summary>
	/// トークンの構造体
	/// </summary>
	struct Token {
		TokenType tokenType;
		std::string data;
	};
}