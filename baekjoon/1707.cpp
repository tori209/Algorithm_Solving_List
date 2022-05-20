/*
	1707번
	문제: 이분 그래프
	입력: 테스트 케이스 t,
		각 테스트 케이스에 대해 정점 개수 V, 간선 개수 e, 각 간선에 의해 연결된 정점 2개 
		(t: 2이상 5이하 자연수 /  V: 1이상 20,000 이하 자연수 / e: 1이상 200,000 이하 자연수)
		※ 간선은 방향성을 가지지 않는다.  
	출력: 각 테스트 케이스에 대해 이분 그래프이면 "YES" 아니면 "NO"
	
	※ 이분 그래프
	그래프의 정점들을 두 개의 집합으로 분할하였을 때,
	같은 집합에 있는 임의의 두 정점은 인접하지 않는 그래프. (인접 = 간선 연결)
	== 직관적으로, 2개의 색으로 정점을 색칠할 때, 인접한(간선으로 연결된) 두 정점은 다른 색으로 칠할 수 있는 그래프.
		만약 색을 칠하는 모든 경우의 수에 대하여 인접한 두 정점이 같은 색으로 칠해지면 이분 그래프가 아님.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, v, e, vtx1, vtx2;
	short color[20001];
	bool isBipartite;
	queue<int> bfs;
	
	cin >> t;
	while (t--) {
		// 그래프 준비 
		vector<int> edges[20001];
		fill_n(color, 20001, 0);
		cin >> v >> e;
		while(e--) {
			cin >> vtx1 >> vtx2;
			edges[vtx1].push_back(vtx2);
			edges[vtx2].push_back(vtx1);
		}
		
		// 그래프 탐색
		isBipartite = true;
		for (int i = 1; i <= v; i++) {
			if (color[i] != 0) continue;
			
			bfs.push(i);
			color[i] = 1;
			while(!bfs.empty()) {
				vtx1 = bfs.front();
				bfs.pop();
				for (int vtx : edges[vtx1]) {
					if (color[vtx] == 0) {
						color[vtx] = -color[vtx1];
						bfs.push(vtx);
					}
					else if (color[vtx] == color[vtx1]) {
						isBipartite = false;
						break;
					} else continue;
				}
			}
		}
		cout << (isBipartite ? "YES\n" : "NO\n");
	}
	
	return 0;
} 
