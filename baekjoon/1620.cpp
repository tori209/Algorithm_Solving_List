#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m;
	string str;
	
	map<string, int> s2idx;
	vector<string> dict(100000, "");
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		dict[i] = str;
		s2idx[str] = i;
	}
	
	while (m-- > 0) {
		cin >> str;
		bool isNum = true;
		for (char c : str) if (!isdigit(c)) isNum = false;
		if (isNum) {
			cout << dict[stoi(str) - 1] << '\n';
		} else {
			cout << s2idx[str] + 1 << '\n';
		}
	}
	
	return 0;
}
