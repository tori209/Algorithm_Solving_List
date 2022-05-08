#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, n;
	string str;
	
	cin >> t;
	while (t-- > 0) {
		cin >> n >> str;		
		for (char c : str) {
			for(int i = 0; i < n; i++) cout << c;
		}
		cout << '\n';		
	}
	return 0;
}
