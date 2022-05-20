/*
	1934번
	문제: 최소공배수
	입력: 테스트 케이스 개수 T와 쌍 a, b T개
	출력: 각 쌍의 최소공약수
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
	
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a * b / (a > b ? gcd(a, b) : gcd(b, a)) << '\n';
	}
	return 0;
}
