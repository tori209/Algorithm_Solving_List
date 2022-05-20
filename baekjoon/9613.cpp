/*
	9613번
	문제: GCD 합
	입력: 테스트 케이스 개수 t (1이상 100이하), 
			각 테스트에 대해, 숫자 개수 n(2 이상 100 이하)과 n개의 숫자들 (1,000,000 이하)
	출력: 각 테스트 케이스들의 숫자를 2개 매칭했을 때, 나올 수 있는 모든 최소공배수들의 합 
*/

#include <iostream>

using namespace std;

int gcd(int val1, int val2) {
	return (val2 ? gcd(val2, val1 % val2) : val1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, n;
	unsigned int num[100];
	unsigned long long sum; 
	
	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0;
		for (int i = 0; i < n; i++) cin >> num[i];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) sum += (long long)(num[i] > num[j] ? gcd(num[i], num[j]) : gcd(num[j], num[i]));
		}
		cout << sum << '\n';
	}
	
	return 0;
}
