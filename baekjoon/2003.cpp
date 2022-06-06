/*
	2003��
	����: ������ ��2
	�Է�: n (1 �̻� 10,000 ����), m (1 ���� 300,000,000 ����)
		���� �� ũ�� n�� ������ ������ (1 �̻� 30,000 ����) 
	���: ���� m�� �Ǵ� �������� ����. 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned int n, m;
	unsigned int sum = 0, cnt = 0;
	unsigned int arr[10000];
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	int b_idx = 0, e_idx = 0;
	while (b_idx != n) {
		if (sum < m) {
			if (e_idx == n) break;
			sum += arr[e_idx++];
		} else {
			if (sum == m) cnt++;
			sum -= arr[b_idx++];
		}
	}
	cout << cnt << '\n';
	
	return 0;
}
