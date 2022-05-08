/****************************
	10992번
	문제: 별 찍기 - 17
****************************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, i, j;
	cin >> n;
	
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) cout << ' ';
		if (i != 0) cout << '*';
		for (j = 0; j < 2 * i - 1; j++) cout << ' ';
		cout << '*' << '\n';
	}
	for (i = 0; i < 2*n - 1; i++) cout << '*';
	cout << '\n';
	
	return 0;
}
