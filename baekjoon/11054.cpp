/********************
	11054번
	문제: 가장 긴 바이토닉 부분 수열 
	입력: 수열 A의 크기 N과 A의 item들
	출력: 가장 긴 바이토닉 부분 수열의 길이 
********************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, out, max;
	int a[1000];
	int left[1000] = {0,};
	int right[1000] = {0,};
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	out = 1;
	left[0] = 1;
	right[n-1] = 1;
	for (int i = 1; i < n; i++) {
		max = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && left[j] + 1 > max) max = left[j] + 1; 
		}
		left[i] = max;
	}
	
	for (int i = n-2; i > -1; i--) {
		max = 1;
		for (int j = n-1; j > i; j--) {
			if (a[j] < a[i] && right[j] + 1 > max) max = right[j] + 1; 
		}
		right[i] = max;
	}
	
	for (int i = 0; i < n; i++) if (out < left[i] + right[i] - 1) out = left[i] + right[i] - 1;
	cout << out << '\n';
	
	return 0;	
}
