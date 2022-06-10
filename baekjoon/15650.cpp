/*
	15650��
	����: n�� m 2
	�Է�: n, m (1 �̻� 8 ����, m <= n)
	���: 1~n���� m���� ���� ������ ��� ����� ���� ���������� ��� 
*/

#include <iostream>

using namespace std;

int main () {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m, tar;
	int num[8];
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) num[i] = i + 1;
	
	while (1) {
		for (int i = 0; i < m; i++) cout << num[i] << ' ';
		cout << '\n';
		
		if (num[0] == n - m + 1) break;
		
		num[m - 1]++;
		for (tar = m - 1; tar > 0; tar--) {
			if (num[tar] == (n + tar - m + 2)) num[tar - 1]++;
			else break;
		}
		for (tar = tar + 1; tar < m; tar++) num[tar] = num[tar - 1] + 1;
	}
	
	return 0;
}
