/*
	ö�� 2�� ���
	�Է�: ��� ���� t (100 ����), �޸��� ��� r, ������ �� n (20 ����) 
	���: n-1�� ������ 2��� ū ���̷� ����ϱ� ���� r�� ��.
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int t, n;
vector<double> running;
vector<double> cycle; 

double otherTime(double r) {
	double ret = r / running[0] + (t - r) / cycle[0];
	for (int i = 1; i < n - 1; i++) {
		if (ret > r / running[i] + (t - r) / cycle[i])
			ret = r / running[i] + (t - r) / cycle[i];
	}
	return ret;
}

double cheatTime(double r) {
	return r / running[n-1] + (t-r) / cycle[n-1];
}

double timeDistance(double r) {
	return otherTime(r) - cheatTime(r);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> t >> n;
	running.resize(n);
	cycle.resize(n);
	for (int i = 0; i < n; i++) 
		cin >> running[i] >> cycle[i];
	
	double lo = 0.0, hi = t;
	double left, right;
	
	cout << fixed;
	cout << setprecision(2);
	for (int i = 0; i < 1000; i++) {
		left = (2*lo + hi) / 3;
		right = (lo + 2*hi) / 3;
		if (timeDistance(left) < timeDistance(right)) lo = left;
		else hi = right;
	}
	if (timeDistance((lo+hi) / 2) < 0) cout << "The cheater cannot win.\n";
	else cout << "The cheater can win by " << cheatTime((lo+hi) / 2) << " seconds with r = " << (lo+hi) / 2 << "km and k = " << t - (lo+hi) / 2 << "km.\n";
} 
