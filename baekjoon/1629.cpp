#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long a, b, c;
	long long ret = 1LL;
	cin >> a >> b >> c;
	
	while (b--) ret = ret * a % c;
	cout << ret << '\n';
	
	return 0;
}
