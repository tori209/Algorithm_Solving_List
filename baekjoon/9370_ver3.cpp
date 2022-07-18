#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, t, s, g, h;
bool visited[2001];
bool routeVisited[2001];
int tot_weight[2001];
int prev_vertex[2001];
vector<pair<int, int>> edges[2001];

bool findTargetRoute(int v) {
	int cur = v;
	while (cur != s) {
		if ((cur == g || cur == h) && (prev_vertex[cur] == g || prev_vertex[cur] == h))
			return true; 
		cur = prev_vertex[cur];
	}
	return false;
}

void dijkstra(int v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int cur_vtx, next_vtx, weight;
	
	tot_weight[v] = 0;
	
	pq.push({0, v});
	while (!pq.empty()) {
		cur_vtx = pq.top().second;
		weight = pq.top().first;
		pq.pop();
		
		if (visited[cur_vtx]) continue;
		visited[cur_vtx] = true;
		
		if (cur_vtx == g && prev_vertex[cur_vtx] == h || cur_vtx == h && prev_vertex[cur_vtx] == g)
			routeVisited[cur_vtx] = true;
		else
			routeVisited[cur_vtx] = routeVisited[prev_vertex[cur_vtx]];
		
		for (pair<int, int> p : edges[cur_vtx]) {
			next_vtx = p.first;
			if (tot_weight[next_vtx] > weight + p.second) {
				prev_vertex[next_vtx] = cur_vtx;
				tot_weight[next_vtx] = weight + p.second;
				pq.push({tot_weight[next_vtx], next_vtx});
				continue;
			}
			if (tot_weight[next_vtx] == weight + p.second) {
				if (routeVisited[cur_vtx] || (cur_vtx == g || cur_vtx == h) && (next_vtx == g || next_vtx == h)) 
					prev_vertex[next_vtx] = cur_vtx;
			}
		}
	}
	return;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		
		for (int i = 0; i <= n; i++) 
			edges[i].clear();
		fill_n(prev_vertex, 2001, -1);
		fill_n(tot_weight, 2001, 987654321);
		fill_n(routeVisited, 2001, false);
		fill_n(visited, 2001, false);
		
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
			if (routeVisited[v]) cout << v << ' ';
		cout << '\n';
	}
	return 0;
}
