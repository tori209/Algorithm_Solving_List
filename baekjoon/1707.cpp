/*
	1707��
	����: �̺� �׷���
	�Է�: �׽�Ʈ ���̽� t,
		�� �׽�Ʈ ���̽��� ���� ���� ���� V, ���� ���� e, �� ������ ���� ����� ���� 2�� 
		(t: 2�̻� 5���� �ڿ��� /  V: 1�̻� 20,000 ���� �ڿ��� / e: 1�̻� 200,000 ���� �ڿ���)
		�� ������ ���⼺�� ������ �ʴ´�.  
	���: �� �׽�Ʈ ���̽��� ���� �̺� �׷����̸� "YES" �ƴϸ� "NO"
	
	�� �̺� �׷���
	�׷����� �������� �� ���� �������� �����Ͽ��� ��,
	���� ���տ� �ִ� ������ �� ������ �������� �ʴ� �׷���. (���� = ���� ����)
	== ����������, 2���� ������ ������ ��ĥ�� ��, ������(�������� �����) �� ������ �ٸ� ������ ĥ�� �� �ִ� �׷���.
		���� ���� ĥ�ϴ� ��� ����� ���� ���Ͽ� ������ �� ������ ���� ������ ĥ������ �̺� �׷����� �ƴ�.
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
		// �׷��� �غ� 
		vector<int> edges[20001];
		fill_n(color, 20001, 0);
		cin >> v >> e;
		while(e--) {
			cin >> vtx1 >> vtx2;
			edges[vtx1].push_back(vtx2);
			edges[vtx2].push_back(vtx1);
		}
		
		// �׷��� Ž��
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
