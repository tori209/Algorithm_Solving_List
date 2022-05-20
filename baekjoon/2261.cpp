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
	int n, x, y;
	int min_dist = INT_MAX;
	int begin_pos, end_pos;
	bool found;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pos.push_back(make_pair(x, y));
		
	}
	sort(pos.begin(), pos.end());
	
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> cand;
		for (int j = i + 1; j < n; j++) {
			x = pos[i].first - pos[j].first;
			y = pos[i].second - pos[j].second;
			
			if (x*x > min_dist) break;
			else cand.push_back(make_pair(y*y, x*x));
		}
		sort(cand.begin(), cand.end());
		for (pair<int, int> p : cand) {
			if (p.first >= min_dist) break;
			if (p.first + p.second < min_dist) min_dist = p.first + p.second;
		}
	}
	
	cout << min_dist << '\n';
	
	return 0;
}
