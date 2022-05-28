#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	vector<pair<int, int>> pos;
	vector<pair<int, int>> cand;
	int n, x, y;
	int min_dist = INT_MAX;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pos.push_back(make_pair(x, y));
	}
	
	sort(pos.begin(), pos.end());
	for (int i = 1; i < pos.size(); i++) {
		if (pos[i] == pos[i - 1]) {
			cout << 0 << '\n';
			return 0;
		}
	}
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	
	for (pair<int, int> p: pos) {
		for (int i = 0; i < cand.size(); i++) {
			if ((cand[i].first - p.first) * (cand[i].first - p.first) < min_dist) {
				cand.erase(cand.begin(), cand.begin() + i);
				break;
			}
		}
		vector<pair<int, int>> set (cand.begin(), cand.end());
		sort(set.begin(), set.end(), 
			[&p](pair<int, int> a, pair<int, int> b)
			{ return (abs(a.second - p.second) < abs(b.second - p.second) || ((abs(a.second - p.second) == abs(b.second - p.second) && abs(a.first-p.first) <= abs(b.first-p.first)))); }
		);
		for (pair<int, int> s : set) {
			if ((s.second - p.second) * (s.second - p.second) > min_dist) break;
			if ((s.first - p.first) * (s.first - p.first) + (s.second - p.second) * (s.second - p.second) < min_dist) 
				min_dist = (s.first - p.first) * (s.first - p.first) + (s.second - p.second) * (s.second - p.second);
		}
		cand.push_back(p);
	}
	
	cout << min_dist << '\n';
	
	return 0;
}
