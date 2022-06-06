#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long x1, y1, x2, y2;
	long long x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	
	if (x3 == x4) {
		if (x1 == x2) cout << 0 << '\n';
		else {
			if (abs(x2 - x1) > abs(x3 - x1) && (x2 - x1) * (x3 - x1) > 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	} else if (y3 == y4) {
		if (y1 == y2) cout << 0 << '\n';
		else {
			if (abs(y2 - y1) > abs(y3 - y1) && (y2 - y1) * (y3 - y1) > 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	} else {
		long long a1 = (x4 - x3) * (y1 - y3);
		long long a2 = (x4 - x3) * (y2 - y1);
		long long a3 = (y4 - y3) * (x1 - x3);
		long long a4 = (y4 - y3) * (x2 - x1);
		
		if (abs(a1 - a3) < abs(a4 - a2) && (a1 - a3)*(a4 - a2) > 0) cout << 1 <<'\n';
		else cout << 0 << '\n';
	}
	
	return 0;
}
