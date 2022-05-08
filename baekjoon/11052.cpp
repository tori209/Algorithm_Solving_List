/*
	11052��
	����: ī�� �����ϱ� 
	�Է�: �����Ϸ��� �ϴ� ī�� ���� N / ī���� P1, P2, ... PN�� ���� 
	���: N���� ī�带 �����ϱ� ���� �����ؾ��ϴ� �ݾ��� �ִ�.
		�� ��, N���� �ʰ��Ͽ� ������ �� ������ �������� �Ұ��ϴ�.
		�� Pi �� i���� ī�尡 ����ִ� ī������ �ǹ��Ѵ�. 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	int price[1001] = {0,};
	int sum[1001] = {0,};
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> price[i];
	sum[1] = price[1];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (sum[i] < sum[i - j] + price[j]) sum[i] = sum[i - j] + price[j];
		}
	}
	
	cout << sum[n] << '\n';
	return 0;
} 
