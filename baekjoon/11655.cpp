/*
	11655��
	����: ROT13
	�Է�: ���ڿ� S
	���: ī�̻縣 ��ȣ, 13�� Ű������ S�� ��ȣȭ�� ���ڿ�. (���� �ҹ���, �빮�ڸ�.) 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string s;
	getline(cin, s);
	
	for (char c : s) {
		if (c >= 'a' && c <= 'z') cout << (char)('a' + (c - 'a' + 13) % 26);
		else if (c >= 'A' && c <= 'Z') cout << (char)((c - 'A' + 13) % 26 + 'A');
		else cout << c;
	}
	cout << '\n';
	
	return 0;
} 
