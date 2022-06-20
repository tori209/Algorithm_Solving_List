/*
	RATIO
	���� Ƚ�� g, �¸� Ƚ�� w, �·� r�� �־����� ��, �·��� r+1�� �ø��� ���� �ʿ��� ���� Ƚ��?
	(��, 2*10^9 ȸ �̻� �ؾ��� ��� ������.)
	�Է�: �׽�Ʈ ���̽� �� c (100 ����) / ������� �� ���� Ƚ�� n (10^9 ����), �¸� Ƚ�� m (n ����)
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
