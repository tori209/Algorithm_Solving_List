/****************************
	10844��
	����: ���� ��� �� 
	�Է�: 1�̻� 100 ���� �ڿ��� N 
	���: ���̰� N�� ��� ���� ���� % 10^9. (��ܼ�: ������ ��� �ڸ����� ���̰� 1�� ��. 45654 ��.) 
****************************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, sum = 0;
	int num[101][10] = {{0,}, {1,1,1,1,1,1,1,1,1,1},};
	
	cin >> n;
	for (int i = 2; i < n + 1; i++) {
		num[i][0] = num[i-1][1];
		for (int j = 1; j < 9; j++) 
			num[i][j] = (num[i-1][j-1] + num[i-1][j+1]) % 1000000000;
		num[i][9] = num[i-1][8];
	}
	
	for (int i = 1; i < 10; i++) sum = (sum + num[n][i]) % 1000000000;
	
	cout << sum << '\n';
	
	return 0;
}
