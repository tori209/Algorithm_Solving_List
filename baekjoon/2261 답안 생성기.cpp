#include <iostream>
#include <random>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(-10000, 10000);
	
	ofstream ofs("test.txt", ofstream::out);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		// ofs << dis(gen) << ' ' << dis(gen) << '\n';
		ofs << i - 10000 << ' ' << j - 10000 << '\n';
		cout << "Progress: " << i * n + j + 1 << " / " << n*n<< '\n';
	}
	cout << "Finished\n";
	ofs.flush();
	ofs.close();
	return 0;
}
