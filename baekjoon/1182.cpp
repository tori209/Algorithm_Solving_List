/*
	1182번
	문제: 부분수열의 합 
	입력: 정수의 개수 n (1 이상 20 이하)과 정수 s (절댓값이 1,000,000 이하)
		개행 후 n개의 정수 (절댓값이 100,000 이하) 
	출력: 합이 s가 되는 부분수열의 개수 
*/

#include <iostream>

using namespace std;

int n, s;
int num[20];

int finder(int idx, int cnt, int cur_sum) {
	if (idx == n) return (cur_sum == s && cnt != 0 ? 1 : 0);
	else return finder(idx + 1, cnt + 1, cur_sum + num[idx]) + finder(idx + 1, cnt, cur_sum);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> num[i];
	
	cout << finder(0, 0, 0) << '\n';
	
	return 0; 
}
