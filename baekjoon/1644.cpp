/*
	1644��
	����: �Ҽ��� ������ 
	�Է�: �ڿ��� n (4,000,000 ����) 
	���: n�� ���ӵ� �Ҽ��� ������ ���� �� �ִ� ����� �� 
*/

#include <iostream>
#include <vector> 

using namespace std;

bool isPrime[4000001];
vector<int> prime;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned int n;
	unsigned int b_idx = 0, e_idx = 0, sum = 0, cnt = 0;
	
	fill_n(isPrime, 4000001, true);
	isPrime[0] = isPrime[1] = false;
	
	cin >> n;
	for (int i = 0; i <= 2000; i++) {
		if (!isPrime[i]) continue;
		for (int j = 2; j <= 4000000/i; j++) isPrime[i * j] = false;
	}
	
	for (int i = 1; i <= n; i++) if (isPrime[i]) prime.push_back(i);
	
	
	while(b_idx != prime.size()) {
		if (sum < n) {
			if (e_idx == prime.size()) break;
			sum += prime[e_idx++];
		} else {
			if (sum == n) cnt++;
			sum -= prime[b_idx++];
		}
	}
	cout << cnt << '\n';
	
	return 0;
} 
