/*
	1764��
	����: �躸��
	�Է�: �赵 ���� ����� �� n, ���� ���� ����� �� m
		���� �� �赵 ���� ��� ���
		���� �� ���� ���� ��� ���
	���: �� �� ���Ե� ��� ���� ��� 
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
