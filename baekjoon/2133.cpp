/********************
	2133번 
	문제: 타일 채우기 
	입력: 3xN 크기의 벽의 가로길이 n 
	출력: 3xN의 벽을 2x1, 1x2로 채우는 경우의 수
********************/	

#include <iostream>
#include <climits> 
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, count;
	int num[31];
	num[0] = 0;
	num[1] = 0;
	num[2] = 3;
	
	cin >> n;
	if (n%2 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	
	for (int i = 4; i <= n; i += 2) {
		count = 0;
		for (int j = 2; j <= i; j += 2) {
			if (j == 2) count += 3 * num[i - j];
			else if (i == j) count += 2;
			else count += 2 * num[i - j];
		}
		num[i] = count;
	}
	
	cout << num[n] << '\n';
	
	return 0;	
}
