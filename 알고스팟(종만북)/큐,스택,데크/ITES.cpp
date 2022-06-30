/*
*/

#include <iostream>
#include <queue>

using namespace std;

long long getNext(long long val) {
	return (val * 214013LL + 2531011LL) % (1LL << 32);
}

int convert(long long val) {
	return val % 10000 + 1;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, k, n;
	
	cin >> c;
	while (c--) {
		cin >> k >> n;
		
		int ret = 0;
		int sum = 1984LL;
		long long left, right;
		left = right = 1983LL;
		
		for (int i = 0; i < n;) {
			if (sum <= k) {
				if (sum == k)
					ret++;
				
				if (i < n - 1) {
					right = getNext(right);
					sum += convert(right);
					i++;
				} else break;
			}
			if (sum > k) {
				sum -= convert(left);
				left = getNext(left);
			}
		}
		
		cout << ret << '\n';
	}
	
	return 0;
}
