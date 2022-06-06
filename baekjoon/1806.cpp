/*
	1806번
	문제: 부분합 
	입력: n(1 이상 100,000 이하) , s (1 이상 100,000,000 이하)
		개행 후 n개의 수열 원소들. (10,000 이하 자연수)\
	출력: 구간합이 s 이상이 되는 구간의 최소 길이. 불가능 할 경우 0 출력.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned int n, s;
	unsigned int sum = 0, ret = 100001, b_idx = 0, e_idx = 0;
	unsigned int arr[100000];
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	while (b_idx != n) {
		if (sum < s) {
			if (e_idx == n) break;
			sum += arr[e_idx++];
		} else {
			ret = (ret > e_idx - b_idx ? e_idx - b_idx : ret);
			sum -= arr[b_idx++];
		}
	}
	
	cout << (ret == 100001 ? 0 : ret) << '\n';
	
	return 0;
} 
