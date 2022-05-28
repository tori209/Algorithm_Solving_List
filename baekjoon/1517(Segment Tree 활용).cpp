/*
	1517��
	����: ���� ��Ʈ
	�Է�: ���� ũ�� n (1 �̻� 500,000 ����), ���� �� ���� ������
	���: ���� ��Ʈ �� Swap Ƚ��.
	
	�� Bubble Sort���� �� ������ �̵� Ƚ���� ���� ��ġ�� ������ �����ϴ� ���� ������ �����̴�.
	  �迭�� ����, ���� ��ġ�� �����Ͽ� ������������ ������ �� ��, ���� ������� ��ȸ�� ���ٰ� �� ��,
	  ���� ���׸�Ʈ Ʈ���� ���� �� ��ȸ�� ��Ҵ� 1�� ������ ��, 
	  ���� ��ġ ~ �������� ���� ���� ��û�Ѵٸ� �̴� ���� ��ġ�� ������ �����ϴ� ���� ������ ������ �� ���̴�.
	  ����, �� ������ ��� ���Ѵٸ� ���� �ȴ�. 
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
