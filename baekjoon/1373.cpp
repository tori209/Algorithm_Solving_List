/*
	1373��
	����: 2���� 8����
	�Է�: 2���� n (len(n) <= 1,000,000)
	���: n�� 8������ ��ȯ�� ��
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string str;
	string oct = "";
	char t;
	int sum = 0;
	
	cin >> str;
	str.insert(str.begin(), (3 - str.size() % 3) % 3, '0');
	for (int i = 0; i < str.size(); i += 3) {
		t = '0' + (str[i] == '1') * 4 + (str[i+1] == '1') * 2 + (str[i+2] == '1');
		oct.push_back(t);
	}
	cout << oct << '\n';
	
	return 0;
} 
