/*
	2667번
	문제: 단지번호붙이기 
	입력: 정사각형 지도의 크기 N(5 이상 25 이하), 지도 정보. (1: 집, 0: 길) 
	출력: 지도 상 붙어있는 집들을 1개 단지로 정의할 때, 단지 수. 
*/

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, cnt = 0;
	int houseNum[314] = {0, };
	bool map[25][25]; 
	bool visit[25][25] = {{false,},};
	queue<pair<int, int>> bfs;
	pair<int, int> cur;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin.get();
		for (int j = 0; j < n; j++) map[i][j] = (cin.get() == '1');
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] || !map[i][j]) continue;
			bfs.push(make_pair(i,j));
			visit[i][j] = true;
			while (!bfs.empty()) {
				cur = bfs.front();
				bfs.pop();
				if (cur.first < n - 1 && !visit[cur.first+1][cur.second] && map[cur.first+1][cur.second]) {
					bfs.push(make_pair(cur.first+1, cur.second));
					visit[cur.first+1][cur.second] = true;
				}
				if (cur.second < n - 1 && !visit[cur.first][cur.second+1] && map[cur.first][cur.second+1]) {
					bfs.push(make_pair(cur.first, cur.second+1));
					visit[cur.first][cur.second+1] = true;
				}
				if (cur.first > 0 && !visit[cur.first-1][cur.second] && map[cur.first-1][cur.second]) {
					bfs.push(make_pair(cur.first-1, cur.second));
					visit[cur.first-1][cur.second] = true;
				}
				if (cur.second > 0 && !visit[cur.first][cur.second-1] && map[cur.first][cur.second-1]) {
					bfs.push(make_pair(cur.first, cur.second-1));
					visit[cur.first][cur.second-1] = true;
				}
				houseNum[cnt]++;
			}
			cnt++;
		}
	}
	
	sort(houseNum, houseNum+cnt);
	
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) cout << houseNum[i] << '\n';
	return 0;
}
