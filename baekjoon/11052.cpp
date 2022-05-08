/*
	11052번
	문제: 카드 구매하기 
	입력: 구매하려고 하는 카드 개수 N / 카드팩 P1, P2, ... PN의 가격 
	출력: N개의 카드를 구매하기 위해 지불해야하는 금액의 최댓값.
		※ 단, N개를 초과하여 구매한 후 버리는 선택지는 불가하다.
		※ Pi 는 i개의 카드가 들어있는 카드팩을 의미한다. 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	int price[1001] = {0,};
	int sum[1001] = {0,};
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> price[i];
	sum[1] = price[1];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (sum[i] < sum[i - j] + price[j]) sum[i] = sum[i - j] + price[j];
		}
	}
	
	cout << sum[n] << '\n';
	return 0;
} 
