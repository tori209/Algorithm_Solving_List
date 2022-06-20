#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct point {
	double x, y;
};

int main() {
	int n;
	vector<point> pos;
	
	cin >> n;
	pos.resize(n);
	for (int i = 0; i < n; i++) cin >> pos[i].x >> pos[i].y;
	sort(pos.begin(), pos.end(), [](point a, point b) { return (a.x < b.x || a.x == b.x && a.y < b.y); });
	
	return 0;
}
