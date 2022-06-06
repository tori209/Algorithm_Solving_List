/*
	6603��
	����: �ζ�
	�Է�: �� �׽�Ʈ ���̽��� ����,
		���� ũ�� k (6 �ʰ� 13 �̸�), ���տ� ���ԵǴ� �� k�� (�������� ���ĵ�)
		k == 0�̸� ����.
	���: �� �׽�Ʈ ���̽��� ����,
		6���� ���� �� �� ���� �� �ִ� ��� ����� ��.
		�� �׽�Ʈ ���̽� ���̿��� ���� ���� �߰��Ѵ�. 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int k, cnt;
	int set[12];
	int idx[6];
	
	while(1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> set[i];
		for (int i = 0; i < 6; i++) idx[i] = i;
		
		while(1) {
			for (int i = 0; i < 6; i++) cout << set[idx[i]] << ' ';
			cout << '\n';
			
			cnt = 0;
			for (int i = 0; i < 6; i++) {
				if (idx[i] == k - 6 + i) cnt++;
			}
			
			if (cnt == 0) idx[5]++;
			else if (cnt == 6) break;
			else {
				idx[5 - cnt]++;
				for (int i = 6 - cnt; i < 6; i++) idx[i] = idx[i - 1] + 1;
			}
		}
		
		cout << '\n';
	}
	
	return 0; 
}
