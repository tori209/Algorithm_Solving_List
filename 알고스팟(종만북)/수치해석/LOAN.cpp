/*
	LOAN
	문제: 전세금 균등 상환
	대출 잔금 n원, 월 이자 p/12 %, 월 상환액 c에 대해, m개월 동안 대출 금액을 모두 상환하기 위해 필요한 c의 최솟값은?
	입력: 테스트 케이스 수 t (50 이하)
		n (1 이상 100,000,000 이하), m (1 이상 120 이하), p (0 초과 50 이하)
	출력: 상환액 c (오차 10^-7) 
	 
*/

#include <iostream>
#include <iomanip>
#include <cmath>

#define ERR 0.0000001
#define LOOP_MAX 100

using namespace std;

double getBalance(double tot, double pay, double ratio, int pow) {
	double remain = tot;
	for (int i = 0; i < pow; i++) {
		remain = remain * (1 + ratio / 1200) - pay;
	}
	return remain;
}

double bSearch(double n, int m, double p) {
	double hi = 0, lo = n * (1 + p / 1200);
	double mid;
	for (int i = 0; i < LOOP_MAX; i++) {
		mid = (hi + lo) / 2;
		//if (abs(hi - lo) / 2 <= ERR) break;
		
		if (getBalance(n, mid, p, m) >= 0) hi = mid;
		else lo = mid;
	}
	return mid;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, m;
	double n, p;
	cin >> t;
	cout << fixed;
	while (t--) {
		cin >> n >> m >> p;
		cout << setprecision(10) << bSearch(n, m, p) << '\n';
	}
	
	return 0;
} 
