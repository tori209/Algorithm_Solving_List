/********************
	11055��
	����: ���� ū �����ϴ� �κ� ����
	�Է�: ���� A�� ũ�� N�� A�� item��
	���: ���� ū �����ϴ� �κ� ������ �� 
********************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, out, max;
	int a[1000];
	int sum[1000] = {0,};
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	out = a[0];
	sum[0] = a[0];
	for (int i = 1; i < n; i++) {
		max = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && sum[j] + a[i] > max) max = sum[j] + a[i]; 
		}
		sum[i] = max;
		if (out < max) out = max;
	}
	cout << out << '\n';
	return 0;	
}
