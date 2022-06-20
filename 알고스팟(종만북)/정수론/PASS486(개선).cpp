/*
	PASS486
	�Է�: �׽�Ʈ ���̽� �� c (50 ����),
		��й�ȣ�� ��� ���� n (400 �̸�), ���� [lo, hi] (1 <= lo <= hi <= 10,000,000) 
	���: [lo, hi] ���� ��� ������ n���� �ڿ������� ����  
*/

#include <iostream>

#define RANGE_MAX 10000000

using namespace std;

int factorMin[10000001];

void initArray() {
	factorMin[0] = factorMin[1] = -1;
	for (int i = 2; i <= RANGE_MAX; i++) factorMin[i] = i;
	
	for (int i = 2; i <= 3164; i++) {
		if (factorMin[i] == i) {
			for (int j = i; i * j <= RANGE_MAX; j++)
				if (factorMin[i * j] > i)
					factorMin[i * j] = i;
		}
	}
	return;
}

int getNum(int n) {
	int ret = 1;
	int cur_prime = factorMin[n];
	int cnt = 1;
	
	while (n != 1) {
		n /= factorMin[n];
		if (cur_prime != factorMin[n]) {
			cur_prime = factorMin[n];
			ret *= (cnt + 1);
			cnt = 1;
		} else cnt++;
	}
	
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n, lo, hi, cnt;
	
	initArray();
	
	cin >> c;
	while (c--) {
		cin >> n >> lo >> hi;
		
		cnt = 0;
		for (int idx = lo; idx <= hi; idx++) {
			if (getNum(idx) == n) cnt++;
		}
		cout << cnt << '\n';
	}
	
	return 0; 
} 
