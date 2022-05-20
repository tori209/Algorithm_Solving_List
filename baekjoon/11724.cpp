/*
	11724��
	����: ���� ����� ����
	�Է�: �׷��� ���� �� n, ���� �� m, ���� �� ������ �� ����
	���: ���� ���(connected component) ���� (���� �׷���) 
	
	�� ��� (component)
		graph G�� G�� subgraph S�� ����
		S�� G�� ����, ������ �ߺ��Ͽ� ������ �ʴ´ٸ�,
		S�� G�� ���(component)��� �Ѵ�. 
	�� ���� ��� (connected component)
		G�� component C�� ���Ͽ�, G�� ��� ������ ���⼺�� ���� ��, (== G�� ���� �׷����϶�) 
		C�� ��� �������� �ٸ� ��� ������ ������ �� �ִ� ��ΰ� �����ϸ�,
		C�� G�� connected component��� �θ���.
		
	��(����) ���� ���� ��� (Strongly Connected Component)
		G�� component C�� ���Ͽ�, G�� ������ ���⼺�� ������ ��, (== G�� ���� �׷����϶�)
		C�� ��� �������� �ٸ� ��� ������ ������ �� �ִ� ��ΰ� �����ϸ�,
		C�� G�� ���� ���� ��Ҷ�� �θ���.
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
