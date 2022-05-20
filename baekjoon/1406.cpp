/*
	1406번
	문제: 에디터
	입력: 편집기에 입력되어있는, 영어 소문자로 구성된, 100,000자 이하 문자열 s / 입력할 에디터 명령 수 m / 명령 m개
	출력: 명령 처리 결과
	
	※ 에디터 명령 레퍼런스
	L: 커서 왼쪽 한 칸 이동. (맨 앞일 경우 무시)
	D: 커서 오른쪽 한 칸 이동. (맨 뒤일 경우 무시)
	B: 커서 왼쪽의 문자 삭제 (맨 앞일 경우 무시)
	P $: 문자 $를 커서 왼쪽에 추가 
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	stack<char> f, e;
	string edit;
	char cmd;

	cin >> edit;
	for (char c : edit) f.push(c);
	edit.clear();
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == 'L') {
			if (f.empty()) continue;
			e.push(f.top());
			f.pop();
		} else if (cmd == 'D') {
			if (e.empty()) continue;
			f.push(e.top());
			e.pop();
		} else if (cmd == 'B') {
			if (f.empty()) continue;
			f.pop();
		} else if (cmd == 'P') {
			cin >> cmd;
			f.push(cmd);
		} else continue;
	}
	while (!f.empty()) {
		e.push(f.top());
		f.pop();
	}
	while (!e.empty()) {
		edit.push_back(e.top());
		e.pop();
	}
	cout << edit << '\n';
	
	return 0;
}
