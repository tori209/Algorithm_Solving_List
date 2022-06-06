/*
	1182��
	����: �κм����� �� 
	�Է�: ������ ���� n (1 �̻� 20 ����)�� ���� s (������ 1,000,000 ����)
		���� �� n���� ���� (������ 100,000 ����) 
	���: ���� s�� �Ǵ� �κм����� ���� 
*/

#include <iostream>

using namespace std;

int n, s;
int num[20];

int finder(int idx, int cnt, int cur_sum) {
	if (idx == n) return (cur_sum == s && cnt != 0 ? 1 : 0);
	else return finder(idx + 1, cnt + 1, cur_sum + num[idx]) + finder(idx + 1, cnt, cur_sum);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> num[i];
	
	cout << finder(0, 0, 0) << '\n';
	
	return 0; 
}
