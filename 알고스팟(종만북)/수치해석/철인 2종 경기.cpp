/*
	철인 2종 경기
	입력: 경로 길이 t (100 이하), 달리기 경로 r, 참가자 수 n (20 이하) 
	출력: n-1번 선수가 2등과 큰 차이로 우승하기 위한 r의 값.
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
