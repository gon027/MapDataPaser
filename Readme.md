# MapDataPaser
�Ǝ��}�b�v�t�@�C���̃p�[�T����肽���B

## �T���v��

#### �� �N���X��`�Ȃǂ͌�����ꂢ�ɂ��܂��B

- �}�b�v�f�[�^��ǂݍ��ރT���v��
``` c++
#include "MapFile.h"
#include "Token.h"
#include "RegexToken.h"
#include "MapData.h"
#include "MapParser.h"

int main(){
  // �}�b�v�t�@�C����ǂݍ���
  std::string code = MapParser::readMapFile{ "FilePath" };

  // ���K�\���̃N���X
  MapParser::RegexToken rt{ code };

  // ��͂���
  auto resltl = MapParser::createMapData(rt);
}
```

- �}�b�v�f�[�^�������o���T���v��
``` c++
#include "MapFile.h"
#include "Token.h"
#include "RegexToken.h"
#include "MapData.h"
#include "MapParser.h"
#include "MapFileWriter.h"

int main(){
  // �}�b�v���X�g���쐬����
  MapParser::MapList mapList{ ... };

  // MapFileWrite�N���X���쐬
  MapParser::MapFileWriter mapFileWriter{"FilePath"};

  // �}�b�v�f�[�^��ۑ�����
  mapFileWriter.saveMap(mapList);
}
```