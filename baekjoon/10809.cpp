#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	unsigned int idx[26];
	fill_n(idx, 26, -1);
	
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (idx[str[i] - 'a'] == -1) idx[str[i] - 'a'] = i; 
	}
	
	for (int i : idx) {
		cout << i << ' ';
	}
	cout << '\n';
	
	return 0;
}
