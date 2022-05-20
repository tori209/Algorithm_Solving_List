/*
	4963��
	����: ���� ���� 
	�Է�: ������ �ʺ� w, ���� h (���� 1�̻� 50����)
		���� �� ���� ���� (1 = �� / 0 = �ٴ�)
		�� �׽�Ʈ ���̽��� ���� ������ �� �ִ�. 
	���: ���� �� ���� ����. 
		(����/����/�밢�� �������� 1ĭ �̵��Ͽ� ���� �����̸� �̵��� �� ������ ���� ��.) 
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int w, h;
	int cnt;
	bool map[50][50];
	bool visit[50][50];
	queue<pair<int, int>> bfs;
	pair<int, int> cur;
		
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				visit[i][j] = false;
			}
		}
		
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visit[i][j] || !map[i][j]) continue;
				
				bfs.push(make_pair(i,j));
				visit[i][j] = true;
				
				while (!bfs.empty()) {
					cur = bfs.front();
					bfs.pop();
					for (int x = -1; x <= 1; x++) {
						for (int y = -1; y <= 1; y++) {
							if (x == 0 && y == 0) continue;
							if (cur.first + x >= 0 && cur.first + x < h && cur.second + y >= 0 && cur.second + y < w) {
								if (!visit[cur.first + x][cur.second + y] && map[cur.first + x][cur.second + y]) {
									bfs.push(make_pair(cur.first + x, cur.second + y));
									visit[cur.first + x][cur.second + y] = true;
								}
							}
						}
					}
				}
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}
