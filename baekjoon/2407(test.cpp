#include <iostream>
#include <vector>

typedef unsigned long long ull;

using namespace std;

ull gcd(ull a, ull b) {
	return (b == 0? a : gcd(b, a % b));
}

int main() {
	
	
	vector<int> mul;
	int n, m, div, g;
	ull ret = 1LL;
	ull ret_10 = 0;
	
	cin >> n >> m;
	for (int i = n; i > (n - m > m ? n - m : m); i--)
		mul.push_back(i);
	
	for (int i = 2; i <= (n - m < m ? n - m : m); i++) {
		div = i;
		for (vector<int>::iterator it = mul.begin(); it != mul.end(); it++) {
			if (*it % div == 0) {
				*it /= div;
				div = 1;
				break;
			}
			g = (*it > div ? gcd (*it, div) : gcd(div, *it));
			
			if (g != 1) {
				div /= g;
				*it /= g;
			} else continue;
		}
		if (div != 1) return -1;
	}
	
	for (vector<int>::iterator it = mul.begin(); it != mul.end(); it++) {
		ret *= *it;
		ret_10 *= *it;
		ret_10 += ret / 10000000000000LL;
		ret %= 10000000000000LL;
	}
	
	if (ret_10 == 0) cout << ret << '\n';
	else cout << ret_10 << ret << '\n';
	
	return 0;
}
