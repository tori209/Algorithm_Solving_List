/*
	PASS486
	�Է�: �׽�Ʈ ���̽� �� c (50 ����),
		��й�ȣ�� ��� ���� n (400 �̸�), ���� [lo, hi] (1 <= lo <= hi <= 10,000,000) 
	���: [lo, hi] ���� ��� ������ n���� �ڿ������� ����  
*/

#include <iostream>

#define RANGE_MAX 10000000

using namespace std;

int factorNum[10000001];

void initArray() {
	fill_n(factorNum, 10000001, 2);
	factorNum[0] = factorNum[1] = -1;
	
	for (int i = 2; i <= RANGE_MAX; i++) {
		for (int j = 2; i * j < RANGE_MAX; j++)
			factorNum[i*j]++;
	}
	
	return;
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
			//cout << idx << "'s prime factor# : " << factorNum[idx] << '\n';
			if (factorNum[idx] == n) cnt++;
		}
		cout << cnt << '\n';
	}
	
	return 0; 
} 
