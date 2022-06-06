/*
	6603번
	문제: 로또
	입력: 각 테스트 케이스에 대해,
		집합 크기 k (6 초과 13 미만), 집합에 포함되는 수 k개 (오름차순 정렬됨)
		k == 0이면 종료.
	출력: 각 테스트 케이스에 대해,
		6개의 수를 고를 때 나올 수 있는 모든 경우의 수.
		각 테스트 케이스 사이에는 공백 줄을 추가한다. 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int k, cnt;
	int set[12];
	int idx[6];
	
	while(1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> set[i];
		for (int i = 0; i < 6; i++) idx[i] = i;
		
		while(1) {
			for (int i = 0; i < 6; i++) cout << set[idx[i]] << ' ';
			cout << '\n';
			
			cnt = 0;
			for (int i = 0; i < 6; i++) {
				if (idx[i] == k - 6 + i) cnt++;
			}
			
			if (cnt == 0) idx[5]++;
			else if (cnt == 6) break;
			else {
				idx[5 - cnt]++;
				for (int i = 6 - cnt; i < 6; i++) idx[i] = idx[i - 1] + 1;
			}
		}
		
		cout << '\n';
	}
	
	return 0; 
}
