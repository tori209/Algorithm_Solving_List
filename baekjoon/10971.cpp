/*
	10971번
	문제: 외판원 순회 2
	입력: 도시의 수 N(2 이상 10 이하), 비용 행렬
	출력: 순회에 필요한 최소 비용
	※ 항상 순회할 수 있는 입력만 제공된다. 
	
	※ 비용 행렬
	비용행렬의 성분 W[i][j]는 도시 i에서 j로 가기 위한 비용이다.
	이때, W[i][j] == 0이면 도시 i에서 j로 갈 수 없다.
	또한, 자기 자신으로 돌아오는 루프는 없다.
*/
#include <iostream>
#include <climits>

using namespace std;

unsigned int w[10][10];
int n;
unsigned int m = 10000001;

void dfs(int node, int step, int val, int visit) {
	if (step == n) {
		if (w[node][0] != 0) m = (m > val + w[node][0] ? val + w[node][0] : m);
		return;  
	}
	
	int mask = 1;
	for (int i = 1; i < n; i++) {
		mask = mask << 1;
		if (w[node][i] == 0 || ((visit & mask) != 0)) continue;
		dfs(i, step + 1, val + w[node][i], visit | mask); 
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> w[i][j];
	for (int i = 0; i < n; i++) bitmask += (1 << i);
	
	dfs(0, 1, 0, 1);
	
	cout << m << '\n';
	
	return 0;
} 
