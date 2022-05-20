/*
	1107번
	문제: 리모컨
	입력: 이동하려는 채널 번호 n(0 이상 500,000 이하)
		개행 후 고장난 버튼의 개수 m (0 이상 10 이하)\
		개행 후 고장난 버튼 목록 
	출력: 채널 100번에서 n번으로 넘어가기 위해 누르는 버튼의 최소 횟수
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long n, m;
	long long cnt, num, min;
	bool numBroken [10] = {false,};
	bool numpadBroken = false;
	bool found;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char t;
		cin >> t;
		numBroken[t - '0'] = true;
	}
	
	if (n == 100) {
		cout << 0 << '\n';
		return 0;
	} else min = abs(n - 100);
	
	for (num = n; num <= n+min; num++) {
		long long temp = num;
		found = true;
		do {
			if (numBroken[temp % 10LL]) {
				found = false;
				break;
			}
			temp /= 10;
		} while (temp != 0);
		if (found) break;
	}
	
	if (found) {
		cnt = (num-n);
		do {
			cnt++;
			num /= 10LL;
		} while (num != 0LL);
		if (cnt < min) min = cnt;
	}
	
	for (num = n; num >= 0LL; num--) {
		long long temp = num;
		found = true;
		do {
			if (numBroken[temp % 10LL]) {
				found = false;
				break;
			}
			temp /= 10LL;
		} while (temp != 0);
		if (found) break;
	}
	
	if (found) {
		cnt = (n - num);
		do {
			cnt++;
			num /= 10LL;
		} while (num != 0LL);
		if (cnt < min) min = cnt;
	}	
	
	cout << min << '\n';
	
	return 0;
} 
