/*
	1850��
	�Է�: ��� �ڸ��� 1�θ� �̷���� �� �ڿ��� a, b ������ ���� 1�� ����
	���: a, b�� �ִ�����
	--> ���� ������� �׷���, �׳� �Էµ� �� ���� �ִ������� ���ؼ� �׸�ŭ 1�� ����϶�� ����. 
*/

#include <iostream>
#include <string>

using namespace std;

unsigned long long gcd(unsigned long long val1, unsigned long long val2) {
	return (val2 ? gcd(val2, val1 % val2) : val1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned long long a, b;
	cin >> a >> b;
	string ret ((a > b ? gcd(a, b) : gcd(b, a)), '1');
	cout << ret << '\n';
	return 0;
}
