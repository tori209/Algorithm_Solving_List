/*
	1783��
	����: ���� ����Ʈ
	�Է�: ü������ ���� ���� n, ���� ���� m (2,000,000,000 ���� �ڿ���) 
	���: �湮�� �� �ִ� ĭ�� ���� �� �ִ�
	// �̵��� �ִ� ������� �� �� �ִ°��� ������, ��� ĭ�� ����̳� �̵��� �� �ִ����� ���� ���� �ƴϴ�. 
	�� ����Ʈ �̵�
	������ 2ĭ, ��/�Ʒ� 1ĭ
	������ 1ĭ, ��/�Ʒ� 2ĭ
*/

#include <iostream>

typedef unsigned long long ull;
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	ull n, m, cnt = 1;
	cin >> n >> m;
	
	if (n == 1) {
		cout << 1 << '\n';
	} else if (n == 2) {
		cout << (m > 7 ? 4 : (m - 1)/2 + 1) << '\n';
	} else if (m < 7) {
		cout << (m > 4 ? 4 : m) << '\n';
	} else {
		cout << m - 2 << '\n';
	}
	return 0;
} 
