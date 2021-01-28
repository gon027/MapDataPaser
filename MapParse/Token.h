#pragma once

#include <string>

namespace MapPaser {

	/// <summary>
	/// �g�[�N���̃^�C�v
	/// </summary>
	enum class TokenType : unsigned int {
		None,
		Space,
		LeftHookBrack,   // ���ꊇ��
		RightHookBrack,  // �E�ꊇ��
		LeftBrackets,    // ������
		RightBrackets,   // �E����
		MapID,           // �}�b�vID
		MapWide,         // �}�b�v�̍L��
		MapData,         // �}�b�v�f�[�^
		MapObject,       // �}�b�v�̃I�u�W�F�N�g
		Comma,           // �J���}
		Equal,           // �C�R�[�� 
		Width,
		Height,
		Id,
		Object,
		Name,
		X,
		Y
	};

	/// <summary>
	/// �g�[�N���̍\����
	/// </summary>
	struct Token {
		TokenType tokenType;
		std::string data;
	};
}