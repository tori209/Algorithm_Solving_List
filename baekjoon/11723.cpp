/*
	11723번
	문제: 집합
	입력: 집합에 대한 연산 개수 m(1 이상 3,000,000 이하)
	출력: check 연산이 입력될 때마다 결과 출력
	
	※집합 연산
	add x: 집합 s에 x를 추가함. 없을 경우 무시
	remove x: 집합 s에서 x를 제거함. 없으면 무시.
	check x: 집합 s에 x가 있으면 1, 없으면 0을 출력
	toggle x: 집합 s에 x가 있으면 제거, 없으면 추가
	all: S에 1~20으로 채운다.
	empty: s를 비운다.
	(x는 1 이상 20 이하 자연수)
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	bool items[21] = {false,};
	int m, x;
	string cmd;
	
	cin >> m;
	while (m--) {
		cin >> cmd;
		if (cmd.compare("add") == 0) {
			cin >> x;
			items[x] = true;
		} else if (cmd.compare("remove") == 0) {
			cin >> x;
			items[x] = false;
		} else if (cmd.compare("check") == 0) {
			cin >> x;
			cout << (items[x] ? 1 : 0) << '\n';
		} else if (cmd.compare("toggle") == 0) {
			cin >> x;
			items[x] = !items[x];
		} else if (cmd.compare("all") == 0) {
			fill_n(items, 21, true);
		} else if (cmd.compare("empty") == 0) {
			fill_n(items, 21, false);
		} else cin.clear();
	}
	
	return 0;
} 
