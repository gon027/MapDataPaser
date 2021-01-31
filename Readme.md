# MapParser
マップファイルを自作して読み込むパーサー  

## サンプル
``` c++
#include ""

// マップファイルを読み込む
std::string code = MapParser::readMapFile("filePath");

// 正規表現のクラス
MapParser::RegexToken rt{ code };

// 解析する
auto resltl = MapParser::createMapData(rt);

```
