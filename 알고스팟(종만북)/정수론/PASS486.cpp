/*
	PASS486
	입력: 테스트 케이스 수 c (50 이하),
		비밀번호의 약수 개수 n (400 미만), 범위 [lo, hi] (1 <= lo <= hi <= 10,000,000) 
	출력: [lo, hi] 내에 약수 개수가 n개인 자연수들의 개수  
*/

#include <iostream>

#define RANGE_MAX 10000000

using namespace std;

int factorNum[10000001];

void initArray() {
	fill_n(factorNum, 10000001, 2);
	factorNum[0] = factorNum[1] = -1;
	
	for (int i = 2; i <= RANGE_MAX; i++) {
		for (int j = 2; i * j < RANGE_MAX; j++)
			factorNum[i*j]++;
	}
	
	return;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n, lo, hi, cnt;
	
	initArray();
	
	cin >> c;
	while (c--) {
		cin >> n >> lo >> hi;
		
		cnt = 0;
		for (int idx = lo; idx <= hi; idx++) {
			//cout << idx << "'s prime factor# : " << factorNum[idx] << '\n';
			if (factorNum[idx] == n) cnt++;
		}
		cout << cnt << '\n';
	}
	
	return 0; 
} 
