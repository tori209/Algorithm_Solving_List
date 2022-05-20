/*
	11724번
	문제: 연결 요소의 개수
	입력: 그래프 정점 수 n, 간선 수 m, 개행 후 간선의 양 끝점
	출력: 연결 요소(connected component) 개수 (무향 그래프) 
	
	※ 요소 (component)
		graph G와 G의 subgraph S에 대해
		S가 G의 정점, 간선을 중복하여 가지지 않는다면,
		S를 G의 요소(component)라고 한다. 
	※ 연결 요소 (connected component)
		G의 component C에 대하여, G의 모든 간선에 방향성이 없을 때, (== G가 무향 그래프일때) 
		C의 모든 정점들이 다른 모든 정점에 도달할 수 있는 경로가 존재하면,
		C를 G의 connected component라고 부른다.
		
	※(참고) 강력 연결 요소 (Strongly Connected Component)
		G의 component C에 대하여, G의 간선에 방향성이 존재할 때, (== G가 유향 그래프일때)
		C의 모든 정점들이 다른 모든 정점에 도달할 수 있는 경로가 존재하면,
		C를 G의 강력 연결 요소라고 부른다.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	queue<int> bfs;
	int n, m, vtx1, vtx2, ret = 0;
	bool visit[1001] = {false,};
	bool edge[1001][1001] = {{false,},}; 
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> vtx1 >> vtx2;
		edge[vtx1][vtx2] = edge[vtx2][vtx1] = true;
	}
	
	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		bfs.push(i);
		while(!bfs.empty()) {
			vtx1 = bfs.front();
			bfs.pop();
			if (visit[vtx1]) continue;
			visit[vtx1] = true;
			for (vtx2 = 1; vtx2 <= n; vtx2++) {
				if (edge[vtx1][vtx2] && !visit[vtx2]) bfs.push(vtx2);
			}
		}
		ret++;
	}
	
	cout << ret << '\n';
	
	return 0;
} 
