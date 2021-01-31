#include <iostream>
#include <string>
#include <vector>
#include "../Token.h"
#include "../RegexToken.h"
#include "../MapData.h"
#include "../MapFile.h"
#include "../MapParser.h"
using namespace std;

/*int main() {
	auto str = MapParser::readMapFile("sample/Test5.txt");
	cout << str << endl;
	MapParser::RegexToken rt(str);
	auto res = MapParser::createMapData(rt);
	for (auto& r : res) {
		r.debug();
	}

	/*
	MapParser::RegexToken test1("123");
	MapParser::RegexToken test2("123.0");
	MapParser::RegexToken test3("1.023440");
	MapParser::RegexToken test4("100000000.023440");

	cout << test1.getToken().data << endl;
	cout << test2.getToken().data << endl;
	cout << test3.getToken().data << endl;
	cout << test4.getToken().data << endl;
	
}
*/