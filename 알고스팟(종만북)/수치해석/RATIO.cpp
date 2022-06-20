/*
	RATIO
	게임 횟수 g, 승리 횟수 w, 승률 r이 주어졌을 때, 승률을 r+1로 올리기 위해 필요한 게임 횟수?
	(단, 2*10^9 회 이상 해야할 경우 포기함.)
	입력: 테스트 케이스 수 c (100 이하) / 현재까지 한 게임 횟수 n (10^9 이하), 승리 횟수 m (n 이하)
*/

#include <iostream>
#include <iomanip>

#define RANGE_MAX 2000000000LL

using namespace std;

long long getAns(long long tot, long long w) {
	long long ratio = w * 100LL / tot;
	if (ratio == (w + RANGE_MAX) * 100LL / (tot + RANGE_MAX)) return -1;
	
	long long lo = 0LL, hi = RANGE_MAX;
	long long mid, t_ratio;
	
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		t_ratio = (w + mid) * 100LL / (tot + mid);
		if (ratio == t_ratio) lo = mid;
		else hi = mid;
	}
	return hi;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long c, n, m;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		cout << (getAns(n, m)) << '\n';
	}
	
	return 0;
} 
