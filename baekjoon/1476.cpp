#include<iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int e, s, m, ret;
	cin >> e >> s >> m;
	
	for (ret = 1; ; ret++) {
		if ((ret - 1)%15 + 1 == e && (ret - 1)%28 + 1 == s && (ret - 1)%19 + 1 == m) break;
	}
	cout << ret << '\n';
	
	return 0;
}
