/*
	1107��
	����: ������
	�Է�: �̵��Ϸ��� ä�� ��ȣ n(0 �̻� 500,000 ����)
		���� �� ���峭 ��ư�� ���� m (0 �̻� 10 ����)\
		���� �� ���峭 ��ư ��� 
	���: ä�� 100������ n������ �Ѿ�� ���� ������ ��ư�� �ּ� Ƚ��
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long n, m;
	long long cnt, num, min;
	bool numBroken [10] = {false,};
	bool numpadBroken = false;
	bool found;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char t;
		cin >> t;
		numBroken[t - '0'] = true;
	}
	
	if (n == 100) {
		cout << 0 << '\n';
		return 0;
	} else min = abs(n - 100);
	
	for (num = n; num <= n+min; num++) {
		long long temp = num;
		found = true;
		do {
			if (numBroken[temp % 10LL]) {
				found = false;
				break;
			}
			temp /= 10;
		} while (temp != 0);
		if (found) break;
	}
	
	if (found) {
		cnt = (num-n);
		do {
			cnt++;
			num /= 10LL;
		} while (num != 0LL);
		if (cnt < min) min = cnt;
	}
	
	for (num = n; num >= 0LL; num--) {
		long long temp = num;
		found = true;
		do {
			if (numBroken[temp % 10LL]) {
				found = false;
				break;
			}
			temp /= 10LL;
		} while (temp != 0);
		if (found) break;
	}
	
	if (found) {
		cnt = (n - num);
		do {
			cnt++;
			num /= 10LL;
		} while (num != 0LL);
		if (cnt < min) min = cnt;
	}	
	
	cout << min << '\n';
	
	return 0;
} 
