/*
	2225번
	문제: 합분해
	입력: 두 자연수 N(1이상 200이하), K(1이상 200이하)
	출력: 0~N의 정수 K개를 더해 N이 되는 경우의 수 % 1,000,000,000
	※한가지 수를 여러개 사용 가능 / 덧셈 순서가 바뀌면 다른 경우.
*/

#include <iostream>

using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned int n, k;
	unsigned long long cnt[201][201] = {{0,},}; // 카운트 * 합 
	
	cin >> n >> k;
	fill_n(cnt[0], 201, 0);
	fill_n(cnt[1], 201, 1);
	for (int count = 2; count <= k; count++) {
		cnt[count][0] = 1;
		for (int sum = 1; sum <= n; sum++) {
			cnt[count][sum] = cnt[count-1][sum] + cnt[count][sum-1];
			// cnt[count][sum]은 cnt[count-1]에서 idx = 0 to sum 을 모두 합친 값이다.
			// cnt[count-1] 에 대해 숫자 0, 1, ..., sum을 뒤에 연결한 것이기 때문. 
		}
	}

 	cout << cnt[k][n] << '\n';
	return 0;
} 
