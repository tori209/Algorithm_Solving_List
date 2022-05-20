/*
	9613��
	����: GCD ��
	�Է�: �׽�Ʈ ���̽� ���� t (1�̻� 100����), 
			�� �׽�Ʈ�� ����, ���� ���� n(2 �̻� 100 ����)�� n���� ���ڵ� (1,000,000 ����)
	���: �� �׽�Ʈ ���̽����� ���ڸ� 2�� ��Ī���� ��, ���� �� �ִ� ��� �ּҰ�������� �� 
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
	
	int t, n;
	unsigned int num[100];
	unsigned long long sum; 
	
	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0;
		for (int i = 0; i < n; i++) cin >> num[i];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) sum += (long long)(num[i] > num[j] ? gcd(num[i], num[j]) : gcd(num[j], num[i]));
		}
		cout << sum << '\n';
	}
	
	return 0;
}
