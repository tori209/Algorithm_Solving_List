/*
	1764번
	문제: 듣보잡
	입력: 듣도 못한 사람의 수 n, 보도 못한 사람의 수 m
		개행 후 듣도 못한 사람 명단
		개행 후 보도 못한 사람 명단
	출력: 둘 다 포함된 사람 수와 명단 
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m;
	set<string> cmp, ret;
	string name;
	
	cin >> n >> m;
	while (n--) {
		cin >> name;
		cmp.insert(name);
	}
	while (m--) {
		cin >> name;
		if (cmp.find(name) != cmp.cend()) ret.insert(name);
	}
	cout << ret.size() << '\n';
	for (set<string>::iterator it = ret.begin(); it != ret.end(); it++) cout << *it << '\n';
	
	return 0;
} 
