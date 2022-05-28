/*
	1517번
	문제: 버블 소트
	입력: 수열 크기 n (1 이상 500,000 이하), 개행 후 수열 구성원
	출력: 버블 소트 시 Swap 횟수.
	
	※ Bubble Sort에서 한 원소의 이동 횟수는 기존 위치의 우측에 존재하는 작은 수들의 개수이다.
	  배열에 숫자, 기존 위치를 삽입하여 오름차순으로 정렬을 한 뒤, 작은 순서대로 순회를 돈다고 할 때,
	  만약 세그먼트 트리를 만든 뒤 순회한 요소는 1을 대입한 뒤, 
	  기존 위치 ~ 끝까지의 구간 합을 요청한다면 이는 기존 위치의 우측에 존재하는 작은 수들의 개수가 될 것이다.
	  따라서, 이 수들을 모두 더한다면 답이 된다. 
*/

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> arr[500000];
int st[1 << 20] = {0,}; 

int update(int idx, int s_range, int e_range, int tar) {
	if (s_range == e_range) return st[idx] = 1;
	
	st[idx]++;
	int mid = (s_range + e_range) / 2;
	if (mid >= tar) return update(2*idx, s_range, mid, tar);
	else return update(2*idx + 1, mid + 1, e_range, tar);
}

int getVal(int idx, int s_range, int e_range, int s_tar, int e_tar) {
	if (s_range == s_tar && e_range == e_tar) return st[idx];
	
	int mid = (s_range + e_range) / 2;
	if (e_tar <= mid) return getVal(2*idx, s_range, mid, s_tar, e_tar);
	else if (s_tar > mid) return getVal(2*idx + 1, mid + 1, e_range, s_tar, e_tar);
	else return getVal(2*idx, s_range, mid, s_tar, mid) + getVal(2*idx + 1, mid + 1, e_range, mid + 1, e_tar);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long ret = 0, n;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arr[i] = {val, i};
	}
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		int b_idx = arr[i].second;
		ret += getVal(1, 0, n - 1, b_idx, n - 1);
		update(1, 0, n - 1, b_idx);
	}
	
	cout << ret << '\n';
	
	return 0;
} 
