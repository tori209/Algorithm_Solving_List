/********************
	11722번
	문제: 가장 긴 감소하는 부분 수열
	입력: 수열 A의 크기 N과 A의 item들
	출력: 가장 긴 감소하는 부분 수열의 길이 
********************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, out, max;
	int a[1000];
	int num[1000] = {0,};
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	out = 1;
	num[0] = 1;
	for (int i = 1; i < n; i++) {
		max = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i] && num[j] + 1 > max) max = num[j] + 1; 
		}
		num[i] = max;
		if (out < max) out = max;
	}
	cout << out << '\n';
	return 0;
}
