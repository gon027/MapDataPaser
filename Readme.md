# MapDataPaser
独自マップファイルのパーサを作りたい。

## サンプル

#### ※ クラス定義などは後程きれいにします。

- マップデータを読み込むサンプル
``` c++
#include "../MapFileReader.h"

int main(){
  // マップファイルを読み込む
  auto mapList = MapFileReader::readMapFile("sample/Test.txt");
}
```

- マップデータを書き出すサンプル
``` c++
#include "../MapFileWriter.h"

int main(){
  // マップリストを作成する
  MapParser::MapList mapList{ ... };

  // マップデータを保存する
  MapFileWriter::saveMapFile("sample/output.txt", m);
}
```