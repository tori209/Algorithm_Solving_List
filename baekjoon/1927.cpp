#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0); 
	
	priority_queue<int> q;
	int n, i;
	cin >> n;
	while (n-- > 0) {
		cin >> i;
		if (i == 0) {
			if (q.empty()) cout << "0\n";
			else {
				cout << -q.top() << '\n';
				q.pop();
			}
		} else q.push(-i);
	}
	
	return 0;
}
