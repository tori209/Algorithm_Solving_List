/*
	2089��
	����: -2����
	�Է�: 10���� �� N
	���: -2���� ���� ��ȯ�� ��
	
	�� -2����
	-2���� an an-1 an-2 an-3 ... a2 a1 a0�� 10������ ��ȯ�ϸ�
	an*(-2)^n + an-1*(-2)^(n-1) + an-2 * (-2)^(n-2) + ... a2 * (-2)^2 + a1 * (-2)^1 + a0 * (-2)^0 �̴�.
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	stack<bool> s;
	bool b;
	
	cin >> n;
	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}
	
	while (n != 0) {
		b = n % (-2);
		s.push(b);
		n = (n - b) / (-2);
	}
	
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	
	return 0;
} 
