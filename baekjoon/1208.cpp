/*
	1208번
	입력: 수열 크기 n(1 이상 40 이하)와 s(절댓값이 1,000,000 이하)
		개행 후 수열의 구성원 (절댓값이 100,000 이하)
	출력: 부분수열의 합이 s가 되는 경우의 수
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
int arr[40];
vector<int> arr1, arr2;

void setting(int idx1, int idx2) {
	if (idx1 > idx2) return;
	
	int si1 = arr1.size();
	int si2 = arr2.size();
	
	for (int i = 0; i < si1; i++) arr1.push_back(arr1[i] + arr[idx1]);
	if (idx1 < idx2) for (int i = 0; i < si2; i++) arr2.push_back(arr2[i] + arr[idx2]);
	setting(idx1 + 1, idx2 - 1);
	return;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	arr1.push_back(0);
	arr2.push_back(0);
	setting(0, n - 1);
	
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	
	int a_idx = 0, b_idx = arr2.size() - 1;
	int sum;
	long long ret = 0;
	
	while (a_idx < arr1.size() && b_idx >= 0) {
		sum = arr1[a_idx] + arr2[b_idx];
		if (sum < s) a_idx++;
		else if (sum > s) b_idx--;
		else {
			int a_num, b_num;
			for (a_num = a_idx; a_num < arr1.size() - 1; a_num++)
				if (arr1[a_num] != arr1[a_num + 1]) break;
			for (b_num = b_idx; b_num > 0; b_num--)
				if (arr2[b_num] != arr2[b_num - 1]) break;
			ret += (long long)(a_num - a_idx + 1) * (long long)(b_idx - b_num + 1);
			a_idx = a_num + 1;
			b_idx = b_num - 1;
		}
	}
	
	cout << ret - (s == 0 ? 1 : 0) << '\n';
	
	return 0;
} 
