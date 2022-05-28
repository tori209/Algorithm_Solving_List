/*
	1517번
	문제: 버블 소트
	입력: 수열 크기 n (1 이상 500,000 이하), 개행 후 수열 구성원
	출력: 버블 소트 시 Swap 횟수.
	
	※ Merge Sort의 Arrow Cross 횟수가 Bubble Sort의 Swap 횟수이다. 
*/

#include <iostream>

using namespace std;

long long n, ret = 0;
int arr[500000];

void ms(int s, int e) {
	if (e - s == 1) return;
	int mid = (s + e) / 2;
	ms(s, mid);
	ms(mid, e);
	
	long long cnt = 0;
	int idx1 = s, idx2 = mid;
	int temp[e-s];
	for (int idx = 0; idx < e-s; idx++) {
		if (idx1 == mid) {
			temp[idx] = arr[idx2++];
			continue;
		}
		if (idx2 == e) {
			temp[idx] = arr[idx1++];
			ret += cnt;
			continue;
		}
		
		if (arr[idx1] > arr[idx2]) {
			temp[idx] = arr[idx2++];
			cnt++;
		} else {
			temp[idx] = arr[idx1++];
			ret += cnt;
		}
	}
	for (int i = 0; i < e-s; i++) arr[i + s] = temp[i];
	return;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ms(0, n);
	cout << ret << '\n';
	 
	return 0;
} 
