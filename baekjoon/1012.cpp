#include <iostream>
#include <queue>

using namespace std;

bool farm[50][50];
bool visited[50][50];
int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	int m, n, k, x, y, ret;
	queue<int*> bfs, plant;
	
	cin >> t;
	while (t--) {
		ret = 0;
		for (int i = 0; i < 50; i++) fill_n(visited[i], 50, false);
		for (int i = 0; i < 50; i++) fill_n(farm[i], 50, false);
		
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			plant.push(new int[2] {x, y});
			farm[x][y] = true;
		}
		
		while (!plant.empty()) {
			int * xy = plant.front();
			plant.pop();
			
			if (visited[xy[0]][xy[1]]) {
				delete[] xy;
				continue;
			} 
			
			visited[xy[0]][xy[1]] = true;
			bfs.push(xy);
			
			while (!bfs.empty()) {
				xy = bfs.front();
				bfs.pop();
				for (int* mo : mov) {
					if (xy[0] + mo[0] >= 0 && xy[0] + mo[0] < m && xy[1] + mo[1] >= 0 && xy[1] + mo[1] < n) {
						if (!visited[xy[0] + mo[0]][xy[1] + mo[1]] && farm[xy[0] + mo[0]][xy[1] + mo[1]]) {
							visited[xy[0] + mo[0]][xy[1] + mo[1]] = true;
							bfs.push(new int[2] {xy[0] + mo[0], xy[1] + mo[1]});
						}
					}
				}
				delete[] xy;
			}
			ret++;
		}
		
		cout << ret << '\n';
	}
	
	
	return 0;
}
