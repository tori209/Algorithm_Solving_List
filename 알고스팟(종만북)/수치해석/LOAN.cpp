/*
	LOAN
	����: ������ �յ� ��ȯ
	���� �ܱ� n��, �� ���� p/12 %, �� ��ȯ�� c�� ����, m���� ���� ���� �ݾ��� ��� ��ȯ�ϱ� ���� �ʿ��� c�� �ּڰ���?
	�Է�: �׽�Ʈ ���̽� �� t (50 ����)
		n (1 �̻� 100,000,000 ����), m (1 �̻� 120 ����), p (0 �ʰ� 50 ����)
	���: ��ȯ�� c (���� 10^-7) 
	 
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
