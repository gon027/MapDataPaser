# MapDataPaser
独自マップファイルのパーサを作りたい。

## サンプル

#### ※ クラス定義などは後程きれいにします。

- マップデータを読み込むサンプル
``` c++
#include "MapFile.h"
#include "Token.h"
#include "RegexToken.h"
#include "MapData.h"
#include "MapParser.h"

int main(){
  // マップファイルを読み込む
  std::string code = MapParser::readMapFile{ "FilePath" };

  // 正規表現のクラス
  MapParser::RegexToken rt{ code };

  // 解析する
  auto resltl = MapParser::createMapData(rt);
}
```

- マップデータを書き出すサンプル
``` c++
#include "MapFile.h"
#include "Token.h"
#include "RegexToken.h"
#include "MapData.h"
#include "MapParser.h"
#include "MapFileWriter.h"

int main(){
  // マップリストを作成する
  MapParser::MapList mapList{ ... };

  // MapFileWriteクラスを作成
  MapParser::MapFileWriter mapFileWriter{"FilePath"};

  // マップデータを保存する
  mapFileWriter.saveMap(mapList);
}
```