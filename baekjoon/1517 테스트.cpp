#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream ofs ("test.txt", ofstream::out);
	
	ofs << 500000;
	for (int i = 500000; i > 0; i--) ofs << i << '\n';
	
	return 0;
}
