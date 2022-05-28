/*
	6549��
	����: ������׷����� ���� ū ���簢��
	�Է�: 0 �Է� �� ���� / �� ���ο� ���� ���簢�� ���� ���. (�ʺ�� �׻� 1) 
	���: �Էµ� ���簢������ �̾���� ������׷��� ���ԵǴ� ���簢�� �� ���� ū ���簢���� ����.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int st[1 << 19]; // Segment Tree = ���� �� ���� �ּڰ��� �Է�. (�̷��� ������ * ���� ���̷� ��� �����ϴٰ� ��.) 

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
