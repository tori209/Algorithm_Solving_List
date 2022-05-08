#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string v1, v2;
	cin >> v1 >> v2;
	
	for (int i = 2; i > -1; i--) {
		if (v1[i] < v2[i]) {
			cout << v2[2] << v2[1] << v2[0] << '\n';
			break;
		} else if (v1[i] > v2[i]) {
			cout << v1[2] << v1[1] << v1[0] << '\n';
			break;
		} else continue;
	}
	return 0;
}
