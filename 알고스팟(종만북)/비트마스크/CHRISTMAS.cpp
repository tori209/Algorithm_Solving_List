/*
	CHRISTMAS
	설명: k명에게 인형을 사주고자 장난감 상점에 있는 n개의 인형상자 중 h번~t번 상자를 모두 구매하여 모든 인원에게 정확히 같은 수의 인형을 나눠주고, 남는 인형이 없게끔 하려고 한다.
		이때, 한 번만 주문한다면 가능한 주문 방법은 몇가지이며, 여러 번 주문할 수 있다면 주문이 겹치지 않게 최대 몇 번 주문할 수 있는가? 
	입력: 테스트 케이스 수 t (60 이하)
		인형 상자 개수 n과 어린이 수 k (각각 1 이상 100,000 이하)
		각 인형 상자에 들어있는 인형 개수 Di (1 이상 100,000 이하) 
	출력: 모든 인원에게 같은 수의 인형을 나누어주고 남는 인형이 없도록 하기 위해, 
		한 번 주문할 경우 가능한 주문 방법,
		여러 번 주문할 경우 가능한 주문 최대 횟수 
		※ 두 출력은 ' '으로 구분한다.
*/

#include <iostream>

#define MAX 987654321
#define MIN -987654321

using namespace std;

int n, k;
int cummulative_sum[100000];

// 문제가 좀 이상한 것으로 판단됨. 
int getCount(int pre_idx, int remainder, int cnt) {
	int ret = (remainder == 0 ? cnt : MIN);
	
	// i ~ j의 구간합 
	for (int i = pre_idx + 2; i < n; i++) {
		for (int j = i; j < n; j++) {
			ret = max(
				ret,
				getCount(j, (remainder + cummulative_sum[j] - (i > 0 ? cummulative_sum[i - 1] : 0)) % k, cnt + 1)
			);
		}
	}
	//if (remainder == 0) cout << pre_idx << ' ';
	
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	
	cin >> t;
	while (t--) {
		int ret1 = 0, ret2 = MAX;
		
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (i) cummulative_sum[i] = (cummulative_sum[i - 1] + num) % k;
			else cummulative_sum[i] = num % k;
		}
		
		// 한 번만 주문하는 경우 
		for (int i = 0; i < n; i++) {
			if (cummulative_sum[i] == 0) ret1++;
			for (int j = 1; j <= i; j++)
				if (cummulative_sum[i] - cummulative_sum[j - 1] == 0) (ret1++) % 20091101;
		}
		
		// 여러 번 주문하는 경우
		ret2 = max(getCount(-2, 0, 0), 0);
		
		cout << ret1 << ' ' << ret2 << '\n'; 
	}
	
	return 0;
}		 
