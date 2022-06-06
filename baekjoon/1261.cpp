/*
	1261번
	문제: 알고스팟 
	입력: n (1 이상 10,000 이하), m (1 이하 300,000,000 이하)
		개행 후 크기 n의 수열의 구성원 (1 이상 30,000 이하) 
	출력: 합이 m이 되는 구간합의 개수. 
*/

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
int dist[100][100];
bool wall[100][100] = {{0,},};
bool visit[100][100] = {{false,},};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m;
	priority_queue<pair<int, pair<int, int>>> pq;
	
	cin >> m >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) wall[i][j] = (cin.get() == '1' ? true : false);
		cin.get();
	}
	
	pq.push({0, {0, 0}});
	dist[0][0] = 0;
	visit[0][0] = true;
	while (!pq.empty()) {
		int len = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (x == n - 1 && y == m - 1) {
			break;
		}
		
		for (int* mo : mov) {
			if (x + mo[0] >= 0 && x + mo[0] < n && y + mo[1] >= 0 && y + mo[1] < m) {
				if (!visit[x + mo[0]][y + mo[1]]) {
					dist[x + mo[0]][y + mo[1]] = len + (wall[x + mo[0]][y + mo[1]] ? 1 : 0);
					visit[x + mo[0]][y + mo[1]] = true;
					pq.push({-dist[x + mo[0]][y + mo[1]], {x + mo[0], y + mo[1]}});
				}
			}
		}
	}
	
	cout << dist[n-1][m-1] << '\n';
	
	return 0;
}
