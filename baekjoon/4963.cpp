/*
	4963번
	문제: 섬의 개수 
	입력: 지도의 너비 w, 높이 h (각각 1이상 50이하)
		개행 후 지도 정보 (1 = 땅 / 0 = 바다)
		※ 테스트 케이스가 여럿 제공될 수 있다. 
	출력: 지도 상 섬의 개수. 
		(가로/세로/대각선 방향으로 1칸 이동하여 땅과 땅사이를 이동할 수 있으면 같은 섬.) 
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
