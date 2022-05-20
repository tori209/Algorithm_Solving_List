/*
	9466번
	문제: 텀 프로젝트 
	입력: 테스트 케이스 수 T,
		개행 후 각 테스트 케이스에 대하여
		학생 수 n (2 이상 100,000 이하) / 1~n이 선택한 학생 번호 (순열로) 
	출력: 각 테스트 케이스에 대해 팀을 이루지 못한 경우.
	
	※ 팀을 이루는 경우 = Cycle 구성. (loop도 인정.) 
*/

#include <iostream>

using namespace std;

bool visit[100001];
int inCycle[100001];
int edge[100001];
int cnt;

int chkCycle(int vtx) {
	if (visit[vtx]) {
		if (inCycle[vtx] == 0) return vtx;
		else return -1;
	}
	
	visit[vtx] = true;
	int rslt = chkCycle(edge[vtx]);
	if (rslt == -1) {
		inCycle[vtx] = -1;
		cnt++;
		return -1;
	} else if (rslt == vtx) {
		inCycle[vtx] = 1;
		return -1;
	} else {
		inCycle[vtx] = 1;
		return rslt;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, n;
	
	cin >> t;
	while (t--) {
		fill_n(visit, 100001, false);
		fill_n(inCycle, 100001, 0);
		fill_n(edge, 100001, -1);
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> edge[i];
		
		for (int i = 1; i <= n; i++) {
			if (inCycle[i] != 0) continue;
			chkCycle(i);
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}
