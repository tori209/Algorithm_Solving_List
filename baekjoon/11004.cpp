/*
	11004번
	문제: K번째 수 
	입력: 숫자 개수 n(1~5,000,000)와 k(1이상 n 이하) / n개의 숫자 
	출력: 오름차순 정렬 시 앞에서 k번째 수 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, k;
	int temp;
	vector<int> vec;
	cin >> n >> k;
	while (n-- > 0) {
		cin >> temp;
		vec.push_back(temp);
	}
 	sort (vec.begin(), vec.end());
 	
 	cout << vec[k-1] << '\n';
	return 0;
}
