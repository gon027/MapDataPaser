#include <iostream>
#include <string>
#include <vector>
#include "../RegexToken.h"
#include "../MapData.h"
#include "../MapFile.h"
#include "../MapParser.h"
using namespace std;

int main() {
	auto str = MapParser::readMapFile("sample/Test4.txt");
	MapParser::RegexToken rt(str);
	auto res = MapParser::createMapData(rt);
	for (auto& r : res) {
		r.debug();
	}
}