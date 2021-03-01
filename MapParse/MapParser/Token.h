#pragma once

#include <string>

namespace MapParser {

	/// <summary>
	/// �g�[�N���̃^�C�v
	/// </summary>
	enum class TokenType : unsigned int {
		None,
		Space,           // ��
		Number,          // ����
		LeftHookBrack,   // ���ꊇ��
		RightHookBrack,  // �E�ꊇ��
		LeftBrackets,    // ������
		RightBrackets,   // �E����
		MapID,           // �}�b�vID
		MapSize,         // �}�b�v�̍L��
		MapField,         // �}�b�v�f�[�^
		MapObject,       // �}�b�v�̃I�u�W�F�N�g
		Comma,           // �J���}
		Equal,           // �C�R�[�� 
		Width,           // �� 
		Height,          // ����
		Id,              // id
		Object,          // �I�u�W�F�N�g
		Name,            // �I�u�W�F�N�g�̖��O
		X,               // x���W 
		Y,                // y���W
	};

	/// <summary>
	/// �g�[�N���̍\����
	/// </summary>
	struct Token {
		TokenType tokenType;
		std::string data;
	};
}