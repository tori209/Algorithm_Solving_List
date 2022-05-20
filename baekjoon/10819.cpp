/*
	10819��
	����: ���̸� �ִ��
	�Է�: ���� �迭 ũ�� n(3�̻� 8����), �迭 ������ (-100 �̻� 100 ����) 
	���: �迭 ������ ������ �����Ͽ��� ��, ���� ������ ������ �� �� �ִ밪 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(int tar, vector<int> arr) {
	if (arr.size() == 1) return abs(tar - arr[0]);
	int local_max = 0, max = 0;
	for (int t : arr) {
		vector<int> vec (arr);
		vec.erase(find(vec.begin(), vec.end(), t));
		local_max = abs(tar - t) + find_max(t, vec);
		if (max < local_max) max = local_max;
	}
	return max;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, max = 0, local_max;
	vector<int> arr;
	cin >> n;
	while (n--) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	
	for (int t : arr) {
		vector<int> vec (arr);
		vec.erase(find(vec.begin(), vec.end(), t));
		local_max = find_max(t, vec);
		if (max < local_max) max = local_max;
	}
	
	cout << max << '\n';
	
	return 0;
}
