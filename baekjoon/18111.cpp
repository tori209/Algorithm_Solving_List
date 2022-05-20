#include <iostream>
#include <climits>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned long long block[500][500];
	unsigned long long m, n, b, h;
	unsigned long long tot, dig, fill;
	unsigned long long min = LLONG_MAX, cur = 0;
	
	cin >> m >> n >> b;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> block[i][j];
		}
	}
	
	//cout << "|Height\t|Dig\t|Fill\t|Time\t|\n";
	for (int height = 0; height <= 256; height++) {
		tot = 0;
		dig = 0;
		fill = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (height > block[i][j]) fill += (height - block[i][j]);
				else dig += (block[i][j] - height);
			}
		}
		
		if (b + dig < fill) break;
		
		cur = fill + dig*2;
		if (min >= cur) {
			min = cur;
			h = height;
		}
		
		//cout << '|' << height << "\t|" << dig << "\t|" << fill << "\t|" << cur << "\t|\n";
	}
	
	cout << min << ' ' << h << '\n';
	
	return 0;
}
