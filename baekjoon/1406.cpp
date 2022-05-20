/*
	1406��
	����: ������
	�Է�: �����⿡ �ԷµǾ��ִ�, ���� �ҹ��ڷ� ������, 100,000�� ���� ���ڿ� s / �Է��� ������ ��� �� m / ��� m��
	���: ��� ó�� ���
	
	�� ������ ��� ���۷���
	L: Ŀ�� ���� �� ĭ �̵�. (�� ���� ��� ����)
	D: Ŀ�� ������ �� ĭ �̵�. (�� ���� ��� ����)
	B: Ŀ�� ������ ���� ���� (�� ���� ��� ����)
	P $: ���� $�� Ŀ�� ���ʿ� �߰� 
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
