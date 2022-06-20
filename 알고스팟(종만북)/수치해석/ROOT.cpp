/*
	ROOTS
	문제: 단변수 다항 방정식의 수치적 해법
	실수 근만을 갖는 ax^2 + bx + c = 0 과 같은 형태의 단변수 다항 방정식이 주어질 때, 이들의 근을 계산하는 프로그램을 작성하시오.
	입력: 테스트 케이스 수 c (50 이하), 방정식 차수 n (2 이상 5 이하), 고차항부터 항들의 계수 
	출력: n개의 실수로 오름차순으로 정렬된 방정식의 해. (오차: 10^-8 이하)
	
	※해의 절댓값을 10 이하로 가정한다. 
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define SOL_MIN -10.0
#define SOL_MAX 10.0
#define ERR 0.00000001
#define LOOP_MAX 200

using namespace std;

double getVal(vector<double> coeff, double pos) {
	double ret = 0;
	double temp = 1;
	for (double e : coeff) {
		ret += temp * e;
		temp *= pos;
	}
	return ret;
}

// f(left) >= 0 / f(right) < 0 인 경우 
double bi_searchBS(double left, double right, vector<double> coeff) {
	double t_left = left, t_right = right;
	double mid;
	
	for (int i = 0; i < LOOP_MAX; i++) {
		mid = (t_left + t_right) / 2;
		if (abs(t_right - t_left) / 2 <= ERR) break;
		
		if (getVal(coeff, mid) >= 0) t_left = mid;
		else t_right = mid;
	}
	
	return mid;
}

// f(left) <= 0 / f(right) > 0 인 경우 
double bi_searchSB(double left, double right, vector<double> coeff) {
	double t_left = left, t_right = right;
	double mid;
	for (int i = 0; i < LOOP_MAX; i++) {
		mid = (t_left + t_right) / 2;
		if (abs(t_right - t_left) / 2 <= ERR) break;
		
		if (getVal(coeff, mid) <= 0) t_left = mid;
		else t_right = mid;
	}
	return mid;
}

// 해를 retrun 해주면 됨. 없으면 공백. 
vector<double> find_answer(vector<double> coeff) {
	vector<double> ret; 
	if (coeff.size() == 1) {
		return ret;
	} else {
		for (int i = 0; i < coeff.size() - 1; i++) 
			ret.push_back(coeff[i + 1] * (i + 1));
		ret = find_answer(ret);
	}
	
	vector<double> lookAt (ret);
	lookAt.push_back(SOL_MAX);
	ret.clear();
	
	double left = SOL_MIN, right;
	for (double d : lookAt) {
		right = d;
		if (getVal(coeff, left) * getVal(coeff, right) <= 0) {
			if (getVal(coeff, right) < 0) ret.push_back(bi_searchBS(left, right, coeff));
			else ret.push_back(bi_searchSB(left, right, coeff)); 
		} 
		left = right;
	}
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n;
	cin >> c;
	while(c--) {
		cin >> n;
		vector<double> coeff(n + 1, 0), ans;
		
		for (int i = n; i >= 0; i--) cin >> coeff[i];
		ans = find_answer(coeff);
		sort(ans.begin(), ans.end());
		
		for (double d : ans) cout << setprecision(12) << d << ' ';
		cout << '\n';
	}
	
	return 0;
} 
