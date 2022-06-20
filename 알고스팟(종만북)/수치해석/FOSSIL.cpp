/*
	FOSSIL
	����: �ɰ��� ȭ��
	�Է�: �׽�Ʈ ���̽� �� c (50 ����)
		���� ������ ���Ե� ���� �� n, m (1 �̻� 100����) 
		�� ���� ������ ���Ե� ���� ��ǥ (x, y)�� �ð� �ݴ� ���� ������� ���õ�. (x,y�� 0 �̻� 100 ����, �Ҽ��� 2�ڸ����� ǥ��� �Ǽ�)
		�� �� �� �̻��� ������ �� ���̴� ���� ����.
	���: �� ���� ������ ��ġ�� �κ��� ���� �ִ� ��. (���� ���� 10^-7) 
		��ġ�� ���� ��� 0 ���. 
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

struct point {
	double x, y;
};

vector<pair<point, point>> upper, lower;

void decompose(vector<point> & hull) {
	int n = hull.size();
	for (int i = 0; i < n; i++) {
		if (hull[i].x > hull[(i + 1) % n].x) upper.push_back({hull[i], hull[(i + 1) % n]});
		else if (hull[i].x < hull[(i + 1) % n].x) lower.push_back({hull[i], hull[(i + 1) % n]});
	}
}

double findMinX(const vector<point>& vec) {
	double x = 101.0;
	for (int i = 0; i < vec.size(); i++)
		if (x > vec[i].x) x = vec[i].x;
	return x;
}

double findMaxX(const vector<point>& vec) {
	double x = -1.0;
	for (int i = 0; i < vec.size(); i++)
		if (x < vec[i].x) x = vec[i].x;
	return x;
}

bool between(const point& a, const point& b, double x) {
	return (a.x <= x && x <= b.x || b.x <= x && x <= a.x);
}

double getY(const point& a, const point& b, double x) {
	return a.y + (b.y - a.y) * (x - a.x) / (b.x - a.x);
}

double getDist(double x) {
	double minUp, maxLo;
	minUp = 2000.0;
	maxLo = -2000.0;
	
	for (int i = 0; i < upper.size(); i++) {
		if (between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, getY(upper[i].first, upper[i].second, x));
	}
	
	for (int i = 0; i < lower.size(); i++) {
		if (between(lower[i].first, lower[i].second, x))
			maxLo = max(maxLo, getY(lower[i].first, lower[i].second, x));
	}
	
	//cout << "X Value: " << x << "\t minUp: " << minUp << "\t maxLo: " << maxLo << '\n';
	
	return minUp - maxLo;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n, m;
	
	cin >> c;
	
	cout << fixed;
	cout << setprecision(10);
	while (c--) {
		cin >> n >> m;
		
		vector<point> hull1, hull2;
		hull1.resize(n); hull2.resize(m);
		upper.clear(); lower.clear();
		
		for (int i = 0; i < n; i++) cin >> hull1[i].x >> hull1[i].y;
		for (int i = 0; i < m; i++) cin >> hull2[i].x >> hull2[i].y;
		
		decompose(hull1);
		decompose(hull2);
		
		double lo, hi, left, right;
		lo = max (findMinX(hull1), findMinX(hull2));
		hi = min (findMaxX(hull1), findMaxX(hull2));
		
		if (lo > hi) {
			cout << 0.0 << '\n';
			continue;
		}
		
		for (int i = 0; i < 200; i++) {
			left = (2*lo + hi) / 3;
			right = (lo + 2*hi) / 3;
			
			if (getDist(left) < getDist(right)) lo = left;
			else hi = right;
		}
		cout << max(getDist(hi), 0.0) << '\n';
	}
	
	return 0;
} 
