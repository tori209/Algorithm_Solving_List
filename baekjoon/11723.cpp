/*
	11723��
	����: ����
	�Է�: ���տ� ���� ���� ���� m(1 �̻� 3,000,000 ����)
	���: check ������ �Էµ� ������ ��� ���
	
	������ ����
	add x: ���� s�� x�� �߰���. ���� ��� ����
	remove x: ���� s���� x�� ������. ������ ����.
	check x: ���� s�� x�� ������ 1, ������ 0�� ���
	toggle x: ���� s�� x�� ������ ����, ������ �߰�
	all: S�� 1~20���� ä���.
	empty: s�� ����.
	(x�� 1 �̻� 20 ���� �ڿ���)
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
