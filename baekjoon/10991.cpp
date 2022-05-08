/****************************
	10991번
	문제: 별 찍기 - 16
****************************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, i, j;
	cin >> n;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) cout << ' ';
		for (j = 0; j < 2 * i + 1; j++) {
			if (j % 2 == 0) cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
