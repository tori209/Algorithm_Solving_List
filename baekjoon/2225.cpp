/*
	2225��
	����: �պ���
	�Է�: �� �ڿ��� N(1�̻� 200����), K(1�̻� 200����)
	���: 0~N�� ���� K���� ���� N�� �Ǵ� ����� �� % 1,000,000,000
	���Ѱ��� ���� ������ ��� ���� / ���� ������ �ٲ�� �ٸ� ���.
*/

#include <iostream>

using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned int n, k;
	unsigned long long cnt[201][201] = {{0,},}; // ī��Ʈ * �� 
	
	cin >> n >> k;
	fill_n(cnt[0], 201, 0);
	fill_n(cnt[1], 201, 1);
	for (int count = 2; count <= k; count++) {
		cnt[count][0] = 1;
		for (int sum = 1; sum <= n; sum++) {
			cnt[count][sum] = cnt[count-1][sum] + cnt[count][sum-1];
			// cnt[count][sum]�� cnt[count-1]���� idx = 0 to sum �� ��� ��ģ ���̴�.
			// cnt[count-1] �� ���� ���� 0, 1, ..., sum�� �ڿ� ������ ���̱� ����. 
		}
	}

 	cout << cnt[k][n] << '\n';
	return 0;
} 
