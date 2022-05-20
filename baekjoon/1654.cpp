/*
	1654��
	����: ���� �ڸ���
	�Է�: ���� ���� K(1 �̻� 10,000 ����), �ʿ��� ���� ���� N (1�̻� 1,000,000 ����) (K <= N)
		���� �� K���� ���� ������ ���� 
	���: K���� ������ �����Ͽ� N���� ���� ������ ������ ���鶧, �ִ� ����. 
*/

#include <iostream>
typedef long long ll;
using namespace std;

int k, n;
ll len[10001];

ll binary(ll start, ll end) {
	if (end - start == 1) return start;
	
	ll mid = (start + end) / 2;
	ll cnt = 0;
	
	for (int i = 0; i < k; i++) cnt += (len[i] / mid);
	
	if (cnt < (long long)n) return binary(start, mid);
	else return binary(mid, end);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> len[i];
	
	cout << binary(1LL, 2147483648LL) << '\n';
	
	return 0;
} 
