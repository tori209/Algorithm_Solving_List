/*
	10808��
	����: ���ĺ� ����
	�Է�: a-z�� ������ �ܾ� S
	���: S�� ���Ե� a-z ������ ����
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string s;
	int cnt[26] = {0,};
	cin >> s;
	for(char c : s) cnt[c - 'a']++;
	for (int i : cnt) cout << i << ' ';
	cout << '\n';
	
	return 0;
}
