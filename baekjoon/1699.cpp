/********************
	1699번 
	문제: 제곱수의 합 
	입력: 100,000 이하의 자연수 N 
	출력: n을 제곱수로 나타낼 때, 항 개수의 최소값. 
********************/

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, min;
	int n_sqrt;
	int num[100001] = {0, 1,};
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		min = INT_MAX;
		n_sqrt = sqrt(i);
		for (int j = 1; j <= n_sqrt; j++) {
			min = (min < num[i - j*j] + 1 ? min : num[i-j*j] + 1);
		}
		num[i] = min;
	}
	
	cout << num[n] << '\n';
	
	return 0;	
}
