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
	int cnt[4];
	
	while (getline(cin, s)) {
		fill_n(cnt, 4, 0);
		for (char i = 0; s[i] != '\0'; i++) {
			if (s[i] >= 'a' && s[i] <= 'z') cnt[0]++;
			else if (s[i] >= 'A' && s[i] <= 'Z') cnt[1]++;
			else if (s[i] >= '0' && s[i] <= '9') cnt[2]++;
			else if (s[i] == ' ') cnt[3]++;
			else continue;
		}
		for (int i : cnt) printf("%d ", i);
		printf("\n");
	}
	
	return 0;
}
