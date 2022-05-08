/********************
	1912�� 
	����: ������ 
	�Է�: ���� A�� ũ�� N�� A�� item��
	���: ���� ������ ���ӵ� ���� �� �� �ִ밪 
********************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, max;
	int a[100000];
	int sum[100000] = {0,};
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sum[0] = a[0];
	max = a[0];
	for (int i = 1; i < n; i++) {
		sum[i] = ((a[i] > a[i] + sum[i - 1]) ? a[i] : a[i] + sum[i - 1]);
		if (max < sum[i]) max = sum[i];
	}
	
	cout << max << '\n';
	
	return 0;	
}
