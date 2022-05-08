/************************
	2522¹ø: º°Âï±â - 12 
************************/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	char* str;
	cin >> n;
	str = new char[n + 1];
	memset (str, ' ', n);
	str[n] = '\0';
	for (int i = 0; i < 2*n - 1; i++) {
		if (i < n) str[n - i - 1] = '*';
		else str[i - n] = ' ';
		cout << str << '\n';
	}
	return 0;
}
