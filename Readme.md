# MapDataPaser
�Ǝ��}�b�v�t�@�C���̃p�[�T����肽���B

## �T���v��

#### �� �N���X��`�Ȃǂ͌�����ꂢ�ɂ��܂��B

- �}�b�v�f�[�^��ǂݍ��ރT���v��
``` c++
#include "../MapFileReader.h"

int main(){
  // �}�b�v�t�@�C����ǂݍ���
  auto mapList = MapFileReader::readMapFile("sample/Test.txt");
}
```

- �}�b�v�f�[�^�������o���T���v��
``` c++
#include "../MapFileWriter.h"

int main(){
  // �}�b�v���X�g���쐬����
  MapParser::MapList mapList{ ... };

  // �}�b�v�f�[�^��ۑ�����
  MapFileWriter::saveMapFile("sample/output.txt", m);
}
```