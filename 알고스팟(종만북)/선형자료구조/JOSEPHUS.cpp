#include <iostream>
#include <list>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n, k, tar;
	int s;
	list<int> num;
	list<int>::iterator it;
	
	cin >> c;
	while(c--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) 
			num.push_back(i);
		s = n;
		tar = k;
		it = num.begin();
		while (s != 2) {
			if (tar == k) {
				it = num.erase(it);
				s--;
				tar = 1;
			} else {
				it = next(it);
				tar++;
			}
			if (it == num.end()) it = num.begin();
		}
		
		it = num.begin();
		cout << *it << ' ' << *next(it) << '\n';
		
		num.clear();
	}
	
	return 0;
}
