/*
	10451번
	문제: 순열 사이클
	입력: 테스트 케이스 개수 t,
		각 테스트 케이스에 대하여 순열 크기 n과 순열
	출력: 각 테스트 케이스의 순열 사이클 개수
	
	모든 정점에 대하여 inbound 1개, outbound 1개이므로 (순열이므로.),
	각 정점은 단 하나의 사이클에 반드시 포함되어야만 하며,
	이는 하나의 SCC에 단 하나의 사이클만 존재한다는 뜻이 된다.
	즉, SCC 개수를 찾으면 끝난다.
	(근데 어차피 이문제의 SCC는 일반 연결 요소 찾는 방법으로 찾아짐.) 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, n, cur;
	int cnt;
	int perm[1001];
	bool visit[1001];
	
	cin >> t;
	while(t--) {
		fill_n(visit, 1001, false);
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> perm[i];
		
		for (int i = 1; i <= n; i++) {
			if (visit[i]) continue;
			cur = i;
			do {
				visit[cur] = true;
				cur = perm[cur];
			} while (cur != i);
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
} 
