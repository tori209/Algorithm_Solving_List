/*
	PASS486
	�Է�: �׽�Ʈ ���̽� �� c (50 ����),
		��й�ȣ�� ��� ���� n (400 �̸�), ���� [lo, hi] (1 <= lo <= hi <= 10,000,000) 
	���: [lo, hi] ���� ��� ������ n���� �ڿ������� ����  
*/

#include <iostream>

#define RANGE_MAX 10000000

using namespace std;

int factorMin[RANGE_MAX + 1];
int factorMinPow[RANGE_MAX + 1];
int factorNum[RANGE_MAX + 1]; 

void initArray() {
	// Array �ʱ�ȭ
	factorNum[0] = -1; // ���� 
	factorNum[1] = 1;
	factorMin[0] = factorMin[1] = -1;
	for (int i = 2; i <= RANGE_MAX; i++) factorMin[i] = i;
	
	// factorMin ���� 
	for (int i = 2; i <= 3163; i++) {
		if (factorMin[i] == i) {
			for (int j = i; i * j <= RANGE_MAX; j++)
				if (factorMin[i * j] > i)
					factorMin[i * j] = i;
		}
	}
	
	// factorNum & factorMinPow ����
	for (int i = 2; i <= RANGE_MAX; i++) {
		if (factorMin[i] == i) {
			factorMinPow[i] = 1;
			factorNum[i] = 2;
		}
		else {
			int pre_num = i / factorMin[i];
			// �Ҽ��̹Ƿ� �׻� ����� 2��, pow�� 1. 
			if (factorMin[pre_num] == factorMin[i]) {
				factorMinPow[i] = factorMinPow[pre_num] + 1;
				factorNum[i] = (factorNum[pre_num] / factorMinPow[i]) * (factorMinPow[i] + 1);
			} else {
				factorNum[i] = 2 * factorNum[pre_num];
				factorMinPow[i] = 1;
			}
		}
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
			if (factorNum[idx] == n) cnt++;
		}
		cout << cnt << '\n';
	}
	
	return 0; 
} 
