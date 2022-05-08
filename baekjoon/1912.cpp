/********************
	1912번 
	문제: 연속합 
	입력: 수열 A의 크기 N과 A의 item들
	출력: 수열 내에서 연속된 수의 합 중 최대값 
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
