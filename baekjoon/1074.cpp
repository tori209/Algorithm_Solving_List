/*
	1074��
	����: Z
	�Է�: ���� n (1 �̻� 15 ����), r, c (���� 0 �̻� 2^n �̸�)
	���: r�� c���� �� ��°�� �湮�ߴ°�?
	�� �湮 ���: 2^n * 2^n �迭�� z�ڷ� �湮�ϰ�, n > 1�̸� 2^n-1 * 2^n-1 4���� �����Ͽ� �»�, ���, ����, ���� ������ �湮�Ѵ�.
		�̵��� �׻� z�ڷ� �Ѵ�. 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	
	int n, r, c;
	int cnt;
	long long ret = 0LL, base;
	
	cin >> n >> r >> c;
	base = (1LL << (n - 1));
	
	while (base != 0) {
		cnt = 0;
		if (r >= base) {
			cnt += 2;
			r -= base;
		}
		if (c >= base) {
			cnt += 1;
			c -= base;
		}
		ret += base * base * cnt;
		base /= 2;
	}
	
	cout << ret << '\n';
	
	return 0;
}
