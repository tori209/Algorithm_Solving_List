#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	map<char, int> counter;
	pair<char, int> max;
	string str;
	
	cin >> str;
	
	for (char c : str) {
		if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
		counter[c] += 1;
	}
	
	max = make_pair('\0', -1);
	for (map<char,int>::iterator it = counter.begin(); it != counter.end(); it++) {
		if (max.second < (*it).second) {
			max.first = (*it).first;
			max.second = (*it).second;
		} else if (max.second == (*it).second) {
			max.first = '?';
		} else continue;
	}
	
	cout << max.first << '\n';
	
	return 0;
}
