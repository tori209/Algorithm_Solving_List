/*
	2745��
	����: ���� ��ȯ
	�Է�: b���� �� n�� �ڿ��� b
	���: n�� 10�������� ��ȯ�� ��
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	stack<char> s;
	char c;
	int b;
	long long sum = 0LL;
	long long digit = 1;
	
	while (cin.get(c) && c != '\n' && c != ' ') {
		s.push(c);
	}
	cin >> b;
	while (!s.empty()) {
		c = s.top();
		if (c >= '0' && c <= '9') sum += digit * (long long)(c - '0');
		else sum += digit * (long long)(c - 'A' + 10);
		digit *= (long long)b;
		s.pop();
	}
	
	cout << sum << '\n';
	
	
	return 0;
} 
