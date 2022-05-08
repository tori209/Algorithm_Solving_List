/****************************
	10844번
	문제: 쉬운 계단 수 
	입력: 1이상 100 이하 자연수 N 
	출력: 길이가 N인 계단 수의 개수 % 10^9. (계단수: 인접한 모든 자리수의 차이가 1인 수. 45654 등.) 
****************************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, sum = 0;
	int num[101][10] = {{0,}, {1,1,1,1,1,1,1,1,1,1},};
	
	cin >> n;
	for (int i = 2; i < n + 1; i++) {
		num[i][0] = num[i-1][1];
		for (int j = 1; j < 9; j++) 
			num[i][j] = (num[i-1][j-1] + num[i-1][j+1]) % 1000000000;
		num[i][9] = num[i-1][8];
	}
	
	for (int i = 1; i < 10; i++) sum = (sum + num[n][i]) % 1000000000;
	
	cout << sum << '\n';
	
	return 0;
}
