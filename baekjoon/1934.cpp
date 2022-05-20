/*
	1934��
	����: �ּҰ����
	�Է�: �׽�Ʈ ���̽� ���� T�� �� a, b T��
	���: �� ���� �ּҰ����
*/

#include <iostream>

using namespace std;

int gcd(int val1, int val2) {
	return (val2 ? gcd(val2, val1 % val2) : val1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a * b / (a > b ? gcd(a, b) : gcd(b, a)) << '\n';
	}
	return 0;
}
