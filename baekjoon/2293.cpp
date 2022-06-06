#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, k;
	unsigned int coin[100];
	unsigned int val[10001];  // 총합 * 쓰인 동전의 최대 밸류 
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		if (coin[i] > k) {
			n--;i--;
		}
	}
	sort(coin, coin + n);
	fill_n(val, 10001, 0);
	val[0] = 1;
	
	for (int idx = 0; idx < n; idx++) {
		for (int sum = 1; sum <= k; sum++) {
			if (sum < coin[idx]) continue;
			val[sum] += val[sum - coin[idx]];
		}
	}
	cout << val[k] << '\n';
	
	return 0;
}
