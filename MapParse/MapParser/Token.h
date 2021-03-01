#pragma once

#include <string>

namespace MapParser {

	/// <summary>
	/// トークンのタイプ
	/// </summary>
	enum class TokenType : unsigned int {
		None,
		Space,           // 空白
		Number,          // 数字
		LeftHookBrack,   // 左鉤括弧
		RightHookBrack,  // 右鉤括弧
		LeftBrackets,    // 左括弧
		RightBrackets,   // 右括弧
		MapID,           // マップID
		MapSize,         // マップの広さ
		MapField,         // マップデータ
		MapObject,       // マップのオブジェクト
		Comma,           // カンマ
		Equal,           // イコール 
		Width,           // 幅 
		Height,          // 高さ
		Id,              // id
		Object,          // オブジェクト
		Name,            // オブジェクトの名前
		X,               // x座標 
		Y,                // y座標
	};

	/// <summary>
	/// トークンの構造体
	/// </summary>
	struct Token {
		TokenType tokenType;
		std::string data;
	};
}