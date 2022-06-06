/*
	2143번 
	문제: 두 배열의 합
	입력: 원하는 합 t (절댓값이 1,000,000,000 이하)
		배열 a의 크기 n(1 이상 1,000 이하), 개행 후 a의 구성원 (절댓값이 1,000,000 이하) 
		배열 b의 크기 m(1 이상 1,000 이하), 개행 후 b의 구성원 (절댓값이 1,000,000 이하) 
	출력: 배열 a의 구간합과 b의 구간합의 합이 t가 되는 경우의 수 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a_sum;
vector<int> b_sum;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long ret = 0;
	int t, n, m;
	int sum, subsum;
	int a[1000], b[1000];
	
	cin >> t >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			a_sum.push_back(sum);
		}
	}
	sort(a_sum.begin(), a_sum.end());
	
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = i; j < m; j++) {
			sum += b[j];
			b_sum.push_back(sum);
		}
	}
	sort(b_sum.begin(), b_sum.end());
	
	int a_idx = 0, b_idx = b_sum.size() - 1;
	while (1) {
		if (a_idx == a_sum.size() || b_idx == -1) break;
		
		sum = a_sum[a_idx] + b_sum[b_idx];
		if (sum < t) a_idx++;
		else if (sum > t) b_idx--;
		else {
			int a_num, b_num;
			for (a_num = a_idx; a_num < a_sum.size() - 1; a_num++)
				if (a_sum[a_num] != a_sum[a_num + 1]) break;
			for (b_num = b_idx; b_num > 0; b_num--)
				if (b_sum[b_num] != b_sum[b_num - 1]) break;
			ret += (long long)(a_num - a_idx + 1) * (long long)(b_idx - b_num + 1);
			a_idx = a_num + 1;
			b_idx = b_num - 1;
		}
	}
	
	cout << ret << '\n';
	
	return 0;
}
