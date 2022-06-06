/*
	2003번
	문제: 수들의 합2
	입력: n (1 이상 10,000 이하), m (1 이하 300,000,000 이하)
		개행 후 크기 n의 수열의 구성원 (1 이상 30,000 이하) 
	출력: 합이 m이 되는 구간합의 개수. 
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
