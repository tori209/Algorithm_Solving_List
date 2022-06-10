/*
	1074번
	문제: Z
	입력: 정수 n (1 이상 15 이하), r, c (각각 0 이상 2^n 미만)
	출력: r행 c열을 몇 번째로 방문했는가?
	※ 방문 방식: 2^n * 2^n 배열을 z자로 방문하고, n > 1이면 2^n-1 * 2^n-1 4개로 분할하여 좌상, 우상, 좌하, 우하 순으로 방문한다.
		이동은 항상 z자로 한다. 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	
	int n, r, c;
	int cnt;
	long long ret = 0LL, base;
	
	cin >> n >> r >> c;
	base = (1LL << (n - 1));
	
	while (base != 0) {
		cnt = 0;
		if (r >= base) {
			cnt += 2;
			r -= base;
		}
		if (c >= base) {
			cnt += 1;
			c -= base;
		}
		ret += base * base * cnt;
		base /= 2;
	}
	
	cout << ret << '\n';
	
	return 0;
}
