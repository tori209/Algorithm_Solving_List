#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

struct Edge {
	int v1, v2;
	int val;
	Edge (int _v1, int _v2, int _val) {
		v1 = _v1; v2 = _v2, val = _val;
	}
	
	bool operator < (Edge e) const {
		return this->val < e.val;
	}
	bool operator> (Edge e) const {
		return this->val > e.val;
	}
};

bool visited[2001];
int tot_weight[2001];
int prev_vertex[2001];
vector<Edge> edges[2001];

bool vertexPassed(int v1, int v2) {
	return visited[v1] && visited[v2];
}

void dijkstra(int v) {
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	int cnt = 0;
	
	for (Edge p : edges[v])
		pq.push(p);
	prev_vertex[v] = 0;
	visited[v] = true;
	
	while (!pq.empty()) {
		Edge cur_edge = pq.top();
		pq.pop();
		
		if (vertexPassed(cur_edge.v1, cur_edge.v2))
			continue;
			
		int prev, cur;
		if (visited[cur_edge.v1]) {
			prev = cur_edge.v1;
			cur = cur_edge.v2;
		}
		else {
			prev = cur_edge.v2;
			cur = cur_edge.v1;
		}
		
		visited[cur] = true;
		prev_vertex[cur] = prev;
		tot_weight[cur] = cur_edge.val;
		
		for (Edge e : edges[cur]) {
			e.val += tot_weight[cur];
			pq.push(e);	
		}
	}
	return;
}

bool isCorrect(int dest, int tar1, int tar2) {
	if (!visited[dest])
		return false;
	
	int cur = dest;
	while (cur != 0) {
		if (cur == tar1 && prev_vertex[cur] == tar2)
			return true;
		if (cur == tar2 && prev_vertex[cur] == tar1)
			return true;
		cur = prev_vertex[cur];
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
		
		for (int i = 0; i <= n; i++)
			edges[i].clear();
		fill_n(prev_vertex, 2001, -1);
		fill_n(visited, 2001, false);
		
		while (m--) {
			int x, y, val;
			cin >> x >> y >> val;
			
			Edge e1(x, y, val);
			Edge e2(y, x, val);
			edges[x].push_back(e1);
			edges[y].push_back(e2);
		}
		
		vector<int> cand_des(t);
		for (int i = 0; i < t; i++)
			cin >> cand_des[i];
		sort(cand_des.begin(), cand_des.end());
		
		dijkstra(s);
		
		for (int i = 1; i <= n; i++)
			assert(visited[i]);
		
		for (int i : cand_des)
			if (isCorrect(i, g, h)) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}
