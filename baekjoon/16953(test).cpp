#include <iostream>
#include <climits>

using namespace std;

long long count(long long n, long long target) {
	if (n > target) return -1LL;
	if (n == target) return 1LL;
	
	int c1 = count(n * 2, target);
	int c2 = count(n * 10 + 1, target);
	
	if (c1 == -1 || c2 == -1) {
		return (c1 == c2 ? -1 : (c1 == -1 ? c2 + 1: c1 + 1));
	} else return (c1 < c2 ? c1 + 1 : c2 + 1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long a, b;
	cin >> a >> b;
	
	if (a >= b) cout << (a == b ? 1 : -1) << '\n';
	else cout << count(a, b) << '\n';
	
	return 0;
}
