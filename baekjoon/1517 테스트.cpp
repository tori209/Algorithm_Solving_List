#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream ofs ("test.txt", ofstream::out);
	
	for (int i = 1; i <= 10000; i++) ofs << i << '\n';
	
	return 0;
}
