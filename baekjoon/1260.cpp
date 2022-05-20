/*
	1260번
	문제: DFS와 BFS
	입력: 정점 개수 n, 간선 개수 m, 시작 정점 v
	출력: DFS 수행 결과, 개행 후 BFS 수행 결과
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m, v;
	int vtx1, vtx2;
	bool link[1001][1001] = {{0,},};
	bool visit[1001];
	
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> vtx1 >> vtx2;
		link[vtx1][vtx2] = link[vtx2][vtx1] = true;
	}
	
	stack<int> dfs;
	queue<int> bfs;
	dfs.push(v);
	bfs.push(v);
	
	fill_n(visit, 1001, false);
	while(!dfs.empty()) {
		vtx1 = dfs.top();
		dfs.pop();
		if (visit[vtx1]) continue;
		else visit[vtx1] = true;
		
		for (int i = n; i > 0; i--) {
			if (link[vtx1][i] && !visit[i]) dfs.push(i);
		}
		cout << vtx1 << ' ';
	}
	cout << '\n';
	
	fill_n(visit, 1001, false);
	while(!bfs.empty()) {
		vtx1 = bfs.front();
		bfs.pop();
		if (visit[vtx1]) continue;
		else visit[vtx1] = true;
		
		for (int i = 1; i <= n; i++) {
			if (link[vtx1][i] && !visit[i]) bfs.push(i);
		}
		cout << vtx1 << ' ';
	}
	cout << '\n';
	
	return 0;
} 
