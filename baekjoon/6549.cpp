/*
	6549번
	문제: 히스토그램에서 가장 큰 직사각형
	입력: 0 입력 시 종료 / 한 라인에 여러 직사각형 높이 출력. (너비는 항상 1) 
	출력: 입력된 직사각형들을 이어붙인 히스토그램에 포함되는 직사각형 중 가장 큰 직사각형의 넓이.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int st[1 << 19]; // Segment Tree = 구간 내 높이 최솟값을 입력. (이러면 구간합 * 구간 길이로 계산 가능하다고 봄.) 

int build(int idx, int s_range, int e_range) {
	if (s_range == e_range) return st[idx] = arr[s_range];
	
	int mid = (s_range + e_range) / 2;
	unsigned long long left = build(2*idx, s_range, mid);
	unsigned long long right = build(2*idx + 1, mid + 1, e_range);
	
	return st[idx] = (left < right ? left : right);
}

int getVal(int idx, int s_range, int e_range, int s_tar, int e_tar) {
	if (s_range == s_tar && e_range == e_tar) return st[idx];
	
	int mid = (s_range + e_range) / 2;
	if (e_tar <= mid) return getVal(2*idx, s_range, mid, s_tar, e_tar);
	else if (s_tar > mid) return getVal(2*idx + 1, mid + 1, e_range, s_tar, e_tar);
	else {
		int left = getVal(2*idx, s_range, mid, s_tar, mid);
		int right = getVal(2*idx + 1, mid + 1, e_range, mid + 1, e_tar);
		return (left < right ? left : right);
	}
}

int main() {
	//cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> arr[i];
		}
		
		build(1, 0, n - 1);
		
		unsigned long long ret = (unsigned long long)*max_element(arr, arr+n);
		unsigned long long temp;
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
			temp = (unsigned long long)(j - i + 1) * (unsigned long long)getVal(1, 0, n - 1, i, j);
			ret = (temp < ret ? ret : temp);
		}
		cout << ret << '\n';
	}
	
	return 0;
}
