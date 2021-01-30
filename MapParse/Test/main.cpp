#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <chrono>
#include "../Token.h"
#include "../RegexToken.h"
#include "../MapData.h"
#include "../MapFile.h"
#include "../MapParser.h"
using namespace std;
using namespace chrono;

/**
int main()
{
	/*
	MapPaser::RegexToken rt{ "{mapWide=[width=10,height=11]}" };
	MapPaser::RegexToken rt{ "{mapWide={0, 2, 10, 100, 1000, 99}}" };
	MapPaser::RegexToken rt{ "{mapObject={[name=10,x=120,y=130,width=300,height=499],[name=20,x=120,y=130,width=300,height=499],[name=20,x=12220,y=13220,width=32200,height=49229]}}" };
	MapParser::RegexToken rt{
		"{[mapID=1,mapWide={[width=100,height=100]},mapData={560,2,10,100,1000,99,0,0,0,9},mapObject={[name=123,x=12,y=123,width=90,height=948],[name=123,x=12,y=123,width=90,height=948]}]}"
	};

	system_clock::time_point start, end;
	start = system_clock::now();

	auto createMapData = MapParser::readMapFile("sample/Test4.txt");
	cout << createMapData << endl;

	MapParser::RegexToken rt{ createMapData };
	auto aa = MapParser::createMapData(rt);

	end = system_clock::now();
	auto elapsed = duration_cast<milliseconds>(end - start).count();

	cout << (elapsed / 1000.0) << endl;

	for (auto& r : aa) {
		r.debug();
	}

	return 0;
}
*/