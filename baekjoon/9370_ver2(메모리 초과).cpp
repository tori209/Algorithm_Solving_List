#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int tot_weight[2001];
vector<int> prev_vertex[2001];
vector<pair<int, int>> edges[2001];

void dijkstra(int v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int cur_vtx, next_vtx, weight;
	
	tot_weight[v] = 0;
	
	pq.push({0, v});
	while (!pq.empty()) {
		cur_vtx = pq.top().second;
		weight = pq.top().first;
		pq.pop();
		
		for (pair<int, int> p : edges[cur_vtx]) {
			next_vtx = p.first;
			if (tot_weight[next_vtx] > weight + p.second) {
				prev_vertex[next_vtx].clear();
				prev_vertex[next_vtx].push_back(cur_vtx);
				tot_weight[next_vtx] = weight + p.second;
				pq.push({tot_weight[next_vtx], next_vtx});
				continue;
			}
			if (tot_weight[next_vtx] == weight + p.second) {
				prev_vertex[next_vtx].push_back(cur_vtx);
				pq.push({tot_weight[next_vtx], next_vtx});
				continue;
			}
		}
	}
	
	return;
}

bool isCorrect(int start, int dest, int tar1, int tar2) {
	vector<int> cur_vtx(1, dest);
	
	bool visited[2001] = {false,};
	visited[dest] = true;
	while (!cur_vtx.empty()) {
		vector<int> next_vtx;
		for (int cur: cur_vtx) {
			if (cur == tar1 || cur == tar2) {
				for (int prev: prev_vertex[cur])
					if (prev == tar1 || prev == tar2)
						return true;
			}
			for (int vtx: prev_vertex[cur]) {
				if (visited[vtx]) continue;
				next_vtx.push_back(vtx);
				visited[vtx] = true;
			}
		}
		cur_vtx = next_vtx;
	}
	return false;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c;
	cin >> c;
	while (c--) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		
		for (int i = 0; i <= n; i++) {
			edges[i].clear();
			prev_vertex[i].clear();
		}
		fill_n(tot_weight, 2001, 987654321);
		
		while (m--) {
			int x, y, val;
			cin >> x >> y >> val;
			edges[x].push_back({y, val});
			edges[y].push_back({x, val});
		}
		
		vector<int> cand_des(t);
		for (int i = 0; i < t; i++)
			cin >> cand_des[i];
		sort(cand_des.begin(), cand_des.end());
		
		dijkstra(s);
		
		for (int v : cand_des)
			if (isCorrect(s, v, g, h)) cout << v << ' ';
		cout << '\n';
	}
	return 0;
}
