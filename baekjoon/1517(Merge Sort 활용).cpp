/*
	1517��
	����: ���� ��Ʈ
	�Է�: ���� ũ�� n (1 �̻� 500,000 ����), ���� �� ���� ������
	���: ���� ��Ʈ �� Swap Ƚ��.
	
	�� Merge Sort�� Arrow Cross Ƚ���� Bubble Sort�� Swap Ƚ���̴�. 
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
