/*
	1451번
	문제: 직사각형으로 나누기
	입력: 직사각형의 세로 크기 n, 가로 크기 m, (각각 1 이상 50 이하) 
		개행 후 각 가로줄의 칸에 적힌 수들
	출력: 직사각형을 3개의 작은 직사각형으로 분할하였을 때, 각 직사각형 내 값들의 합을 모두 곱한 값의 최대값. 
	
	※직접 합치면 오류, sum 역할의 함수를 쓰면 AC가 나온다는 사례가 다수 있음.
		sum함수 생성 후 이를 이용해서 해보자. 
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef unsigned long long ull;

ull square[50][50] = {{0,},};

ull range_sum (pair<int, int> begin, pair<int, int> end) {
	int x1 = begin.first;
	int y1 = begin.second;
	int x2 = end.first;
	int y2 = end.second;
	ull ret = 0ULL;
	
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			ret += square[i][j];
		}
	}
	return ret;
} 

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m;
	ull s1, s2, max = 0ULL;
	ull tot = 0ULL;
	char c;
	
	// 입력 받기		
	cin >> n >> m;
	cin.get();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin.get(c);
			square[i][j] = (c - '0');
			tot += square[i][j];
		}
		cin.get();
	}

	// ||| 구조
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			s1 = range_sum({0, 0}, {n - 1, i});
			s2 = range_sum({0, i + 1}, {n - 1, j});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	
	// = 구조 
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			s1 = range_sum({0, 0}, {i, m - 1});
			s2 = range_sum({i + 1, 0}, {j, m - 1});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	
	// ㅏ 구조
	for (int j = 0; j < m - 1; j++) {
		s1 = range_sum({0, 0}, {n - 1, j});
		for (int i = 0; i < n - 1; i++) {
			s2 = range_sum({0, j + 1}, {i, m - 1});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	} 
	// ㅓ 구조
	for (int j = 0; j < m; j++) {
		s1 = range_sum({0, j + 1}, {n - 1, m - 1});
		for (int i = 0; i < n - 1; i++) {
			s2 = range_sum({0, 0}, {i, j});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	// ㅜ 구조
	for (int i = 0; i < n - 1; i++) {
		s1 = range_sum({0, 0}, {i, m - 1});
		for (int j = 0; j < m - 1; j++) {
			s2 = range_sum({i + 1, 0}, {n - 1, j});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	// ㅗ 구조 
	for (int i = 0; i < n; i++) {
		s1 = range_sum({i, 0}, {n - 1, m - 1});
		for (int j = 0; j < m - 1; j++) {
			s2 = range_sum({0, 0}, {i - 1, j});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	
	cout << max << '\n';
	return 0;
}
