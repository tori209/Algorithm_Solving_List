/*
	10819번
	문제: 차이를 최대로
	입력: 정수 배열 크기 n(3이상 8이하), 배열 구성원 (-100 이상 100 이하) 
	출력: 배열 순서를 적절히 변경하였을 때, 인접 수들의 차이의 합 중 최대값 
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
