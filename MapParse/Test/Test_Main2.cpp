/*#include <iostream>
#include <string>
#include <vector>
#include "../MapFileReader.h"
#include "../MapFileWriter.h"
using namespace std;

int main() {
	auto m = MapFileReader::readMapFile("sample/Test.txt");

	for (auto& d_e : m) {
		d_e.debug();
	}

	MapFileWriter::saveMapFile("sample/output.txt", m);
}
*/