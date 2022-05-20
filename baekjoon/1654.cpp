/*
	1654번
	문제: 랜선 자르기
	입력: 랜선 개수 K(1 이상 10,000 이하), 필요한 랜선 개수 N (1이상 1,000,000 이하) (K <= N)
		개행 후 K개의 랜선 각각의 길이 
	출력: K개의 랜선을 절단하여 N개의 같은 길이의 랜선을 만들때, 최대 길이. 
*/

#include <iostream>
typedef long long ll;
using namespace std;

int k, n;
ll len[10001];

ll binary(ll start, ll end) {
	if (end - start == 1) return start;
	
	ll mid = (start + end) / 2;
	ll cnt = 0;
	
	for (int i = 0; i < k; i++) cnt += (len[i] / mid);
	
	if (cnt < (long long)n) return binary(start, mid);
	else return binary(mid, end);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> len[i];
	
	cout << binary(1LL, 2147483648LL) << '\n';
	
	return 0;
} 
