#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, k, s;
	int x;
	char cmd;
	
	cin >> t;
	while (t--) {
		priority_queue<int> big;
		priority_queue<int, vector<int>, greater<int>> small; 
		map<int, int> cnt;
		s = 0;
		
		cin >> k;
		while (k--) {
			cin >> cmd >> x;
			
			if (cmd == 'I') {
				big.push(x);
				small.push(x);
				cnt[x]++;
				s++;
			} else if (cmd == 'D') {
				if (s == 0) continue;
				
				if (x == 1) {
					while (cnt[big.top()] == 0) big.pop();
					cnt[big.top()]--;
					big.pop();
					s--;
				} else if (x == -1) {
					while (cnt[small.top()] == 0) small.pop();
					cnt[small.top()]--;
					small.pop();
					s--;
				}
			}
		}
		
		if (s == 0) cout << "EMPTY\n";
		else {
			while (cnt[big.top()] == 0) big.pop();
			while (cnt[small.top()] == 0) small.pop();
			cout << big.top() << ' ' << small.top() << '\n';
		}
	}
}
