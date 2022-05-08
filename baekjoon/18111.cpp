#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m, b, tot;
	int h1, h2;
	long time1, time2;
	int ** height;
	cin >> n >> m >> b;
	//tot = b;
	height = new int*[n];
	for (int i = 0; i < n; i++) {
		height[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> height[i][j];
			tot += height[i][j];
		}
	}
	h1 = tot / (m*n);
	h2 = (tot + b) / (m*n);
	if (h2 > 256) h2 = 256;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (height[i][j] > h1) time1 = 2 * (height[i][j] - h1);
			else time1 += (h1 - height[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (height[i][j] > h2) time2 = 2 * (height[i][j] - h2);
			else time2 += (h2 - height[i][j]);
		}
	}
	
	if (time1 < time2) {
		cout << time1 << ' ' << h1 << '\n';
	} else if (time1 > time2) {
		cout << time2 << ' ' << h2 << '\n';
	} else if (h1 < h2) {
		cout << time1 << ' ' << h1 << '\n';
	} else {
		cout << time2 << ' ' << h2 << '\n';
	}
	
	return 0;
}
