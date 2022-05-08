/********************
	2579번 
	문제: 계단 오르기 
	입력: 총 계단 수 (300이하)와 각 계단의 배점 (10,000 이하 자연수) 
	출력: 규칙을 따라 계단을 올랐을 때, 얻을 수 있는 총 점수의 최대값
	
	※ 규칙
		1. 계단은 한번에 한 계단, 혹은 두 계단 오를 수 있다.
		2. 연속된 세 계단을 모두 밟을 수 없다. 단, 시작점은 계단이 아니다.
		3. 마지막은 항상 마지막 계단을 밟는다. 
********************/

#include <iostream>
#include <climits>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	int score[301] = {0,};
	int sum[2][301];
	cin >> n;
	score[0] = 0;
	for (int i = 1; i < n+1; i++) cin >> score[i];
	
	sum[0][0] = 0;
	sum[1][0] = 0;
	sum[0][1] = score[1];
	sum[1][1] = INT_MIN;
	for (int i = 2; i < n + 1; i++) {
		sum[0][i] = score[i] + (sum[0][i-2] > sum[1][i-2] ? sum[0][i-2] : sum[1][i-2]);
		sum[1][i] = score[i] + sum[0][i-1];
	}
	
	cout << (sum[0][n] > sum[1][n] ? sum[0][n] : sum[1][n]) << '\n';
	return 0;	
}
