/****************************
	1463번
	문제: 1로 만들기
	입력: 1 이상 10^6 이하 정수 N
	출력: 하단의 규칙을 따랐을 때, N을 1로 만들기 위한 규칙 적용 횟수 최소값
	
	규칙:
		1. X % 3 == 0이 TRUE이면 3으로 나눔
		2. X % 2 == 0이 TRUE이면 2로 나눔
		3. 1을 뺀다. 
****************************/

#include <iostream>
#include <climits>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	unsigned short count[1000001];
	fill_n(count, 1000001, USHRT_MAX - 1);
	
	cin >> n;
	count[n] = 0;
	for (int i = n; i > 0; i--) {
		if (i % 3 == 0) count[i/3] = ((count[i/3] < count[i] + 1) ? count[i/3] : count[i] + 1);
		if (i % 2 == 0) count[i/2] = ((count[i/2] < count[i] + 1) ? count[i/2] : count[i] + 1);
		count[i - 1] = ((count[i - 1] < count[i] + 1) ? count[i - 1] : count[i] + 1);
	}
	
	cout << count[1] << '\n';
	return 0;
}
