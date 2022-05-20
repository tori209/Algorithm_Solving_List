#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, n;
	int x1, y1, x2, y2;
	int x, y, r, dist1, dist2;
	int cnt;
	
	
	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		cnt = 0;
		while (n--) {
			cin >> x >> y >> r;
			r = r * r;
			dist1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
			dist2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
			cnt += (dist1 < r && dist2 > r || dist1 > r && dist2 < r ? 1 : 0);
		}
		cout << cnt << '\n';
	}
	
	return 0;
}
