# MapParser
�}�b�v�t�@�C�������삵�ēǂݍ��ރp�[�T�[  

## �T���v��
``` c++
#include ""

// �}�b�v�t�@�C����ǂݍ���
std::string code = MapParser::readMapFile("filePath");

// ���K�\���̃N���X
MapParser::RegexToken rt{ code };

// ��͂���
auto resltl = MapParser::createMapData(rt);

```
