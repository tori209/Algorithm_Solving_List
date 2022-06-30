#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n, begin, match;
	int pi[100001];
	string a;
	
	cin >> c;
	while(c--) {
		cin >> a;
		n = a.size();
		
		begin = 1; match = 0;
		while (begin + match < n) {
			if (a[n - 1 - (begin + match)] == a[n - 1 - match]) {
				match++;
				pi[begin + match - 1] = match;
			}
			else {
				if (match == 0) {
					begin++;
					continue;
				}
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
		
		begin = 0; match = 0;
		while (begin + match < n) {
			if (a[begin + match] == a[(n - 1) - match]) {
				match++;
			}
			else {
				if (match == 0) {
					begin++;
					continue;
				}
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
		cout << 2 * n - match << '\n';
	}
	
	return 0;
}
