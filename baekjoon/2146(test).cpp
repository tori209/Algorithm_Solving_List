#include <iostream>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

bool canMove(int x, int y, int length) {
	return (x >= 0 && x < length && y >= 0 && y < length);
}

int main() {
	//cin.tie(0);
	//cout.tie(0);
	//ios::sync_with_stdio(0);
	
	int n, step, min_step = INT_MAX;
	bool map[100][100];
	bool nearSea[100][100];
	int cont[100][100];
	int cont_num = 0;
	pair<int, int> cur;
	queue<pair<int, int>> * bfs;
	queue<pair<int, int>> * next_bfs;
	
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cont[i][j] = -1;
		nearSea[i][j] = false;
		cin >> map[i][j];
	}
	
	bfs = new queue<pair<int, int>>;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (cont[i][j] != -1 || !map[i][j]) continue;
		
		bfs->push(make_pair(i, j));
		cont[i][j] = cont_num;
		while(!bfs->empty()) {
			cur = bfs->front();
			bfs->pop();
			if (canMove(cur.first-1, cur.second, n)) {
				if (map[cur.first-1][cur.second] && cont[cur.first-1][cur.second] == -1) {
					bfs->push(make_pair(cur.first-1, cur.second));
					cont[cur.first-1][cur.second] = cont_num;
				} else if (!map[cur.first-1][cur.second]) nearSea[cur.first][cur.second] = true;
			}
			if (canMove(cur.first+1, cur.second, n)) {
				if (map[cur.first+1][cur.second] && cont[cur.first+1][cur.second] == -1) {
					bfs->push(make_pair(cur.first+1, cur.second));
					cont[cur.first+1][cur.second] = cont_num;
				} else if (!map[cur.first+1][cur.second]) nearSea[cur.first][cur.second] = true;
			}
			if (canMove(cur.first, cur.second-1, n)) {
				if (map[cur.first][cur.second-1] && cont[cur.first][cur.second-1] == -1) {
					bfs->push(make_pair(cur.first, cur.second-1));
					cont[cur.first][cur.second-1] = cont_num;
				} else if (!map[cur.first][cur.second-1]) nearSea[cur.first][cur.second] = true;
			}
			if (canMove(cur.first, cur.second+1, n)) {
				if (map[cur.first][cur.second+1] && cont[cur.first][cur.second+1] == -1) {
					bfs->push(make_pair(cur.first, cur.second+1));
					cont[cur.first][cur.second+1] = cont_num;
				} else if (!map[cur.first][cur.second+1]) nearSea[cur.first][cur.second] = true;
			}
		}
		cont_num++;
	}
	delete bfs;
	/*
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (cont[i][j] == -1 ? ' ' : (char)(cont[i][j] + '0'))	<< ' ';
		}
		cout << '\n';
	} 
	*/
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (cont[i][j] == -1 || !nearSea[i][j]) continue;
		
		bool visit[100][100] = {{false,},};
		
		visit[i][j] = true;
		bfs = new queue<pair<int, int>>;
		bfs->push(make_pair(i, j));
		cont_num = cont[i][j];
		
		//cout << "---------------------------------------\n";
		//cout << "Current Pos: (" << i << ", " << j << ")\n";
		//cout << "Current Continent: " << cont_num << '\n';
		
		step = 0;
		while(1) {
			next_bfs = new queue<pair<int, int>>;
			//cout << "Remained Spots: " << bfs->size() << '\n';
			while (!bfs->empty()) {
				cur = bfs->front();
				bfs->pop();
				if (canMove(cur.first-1, cur.second, n)) {
					if (!map[cur.first-1][cur.second] && !visit[cur.first-1][cur.second]) {
						next_bfs->push(make_pair(cur.first-1, cur.second));
						visit[cur.first-1][cur.second] = true;
					} else if (map[cur.first-1][cur.second] && cont[cur.first-1][cur.second] != cont_num) {
						while (!next_bfs->empty()) next_bfs->pop();
						break;
					}
				}
				if (canMove(cur.first+1, cur.second, n)) {
					if (!map[cur.first+1][cur.second] && !visit[cur.first+1][cur.second]) {
						next_bfs->push(make_pair(cur.first+1, cur.second));
						visit[cur.first+1][cur.second] = true;
					}
					else if (map[cur.first+1][cur.second] && cont[cur.first+1][cur.second] != cont_num) {
						while (!next_bfs->empty()) next_bfs->pop();
						break;
					}
				}
				if (canMove(cur.first, cur.second-1, n)) {
					if (!map[cur.first][cur.second-1] && !visit[cur.first][cur.second-1]) {
						next_bfs->push(make_pair(cur.first, cur.second-1));
						visit[cur.first][cur.second-1] = true;
					}
					else if (map[cur.first][cur.second-1] && cont[cur.first][cur.second-1] != cont_num) {
						while (!next_bfs->empty()) next_bfs->pop();
						break;
					}
				}
				if (canMove(cur.first, cur.second+1, n)) {
					if (!map[cur.first][cur.second+1] && !visit[cur.first][cur.second+1]) {
						next_bfs->push(make_pair(cur.first, cur.second+1));
						visit[cur.first][cur.second+1] = true;
					}
					else if (map[cur.first][cur.second+1] && cont[cur.first][cur.second+1] != cont_num) {
						while (!next_bfs->empty()) next_bfs->pop();
						break;
					}
				}
			}
			if (next_bfs->empty()) break;
			step++;
			delete bfs;
			bfs = next_bfs;
		}
		
		delete bfs;
		if (step < min_step) min_step = step;
		//cout << "minimum step: " << min_step << '\n';
	} 
	
	cout << min_step << '\n';
	
	return 0;
}
