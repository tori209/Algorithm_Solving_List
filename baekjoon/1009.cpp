/*
	1009번
	문제: 분산처리
	입력: 테스트 케이스 t,
		각 줄에 대해 정수 a (1 이상 100 미만), b (1 이상 1,000,000 미만)
	출력: 각 테스트 케이스에 대해 마지막 데이터가 처리되는 컴퓨터의 번호.
	※ 컴퓨터가 총 10대 있으며, 1번 데이터는 1번 컴퓨터, 2번 데이터는 2번 컴퓨터, 3번 데이터는 3번 컴퓨터, ... 식으로 정해져있다.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int cycle;
	int order[10];
	bool visited[10];
	int t, a, b;
	cin >> t;
	while (t--) {
		fill_n(visited, 10, false);
		cycle = 0;
		
		cin >> a >> b;
		
		int num = a % 10;
		while (!visited[num]) {
			visited[num] = true;
			order[cycle++] = num;
			num = (num * a) % 10;
		}
		cout << (order[(b-1) % cycle] == 0 ? 10 : order[(b-1) % cycle]) << '\n';
	}
	
	return 0;
} 
