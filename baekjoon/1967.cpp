/*
	1967번
	문제: 트리의 지름
	입력: 간선 V(2 이상 100,000 이하),
		각 행별로 인접 노드 2개, 간선 가중치 
		※ 가중치는 10,000 이하 자연수이다
	출력: 트리의 지름 (임의의 두 정점 사이의 거리(=가중치의 합) 중 최대값.)
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> * edges;

pair<int, int> find_diameter(int node, int parent) {
	if (edges[node].size() == 1 && edges[node][0].first == parent) return make_pair(node, 0);
	pair<int, int> max = make_pair(-1, -1);
	pair<int, int> temp;
	for (pair<int, int> child : edges[node]) {
		if (child.first == parent) continue;
		temp = find_diameter(child.first, node);
		temp.second += child.second;
		if (max.second < temp.second) max = temp;
	}
	return max;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, v1, v2, weight;
	pair<int, int> max;
	
	// 트리 구축 
	cin >> n;
	if (n <= 1) {
		cout << 0 << '\n';
		return 0;
	} 
	edges = new vector<pair<int, int>>[10001];
	for (int i = 0; i < n - 1; i++) {
		cin >> v1 >> v2 >> weight;
		edges[v1].push_back(make_pair(v2, weight));
		edges[v2].push_back(make_pair(v1, weight));
	}
	
	// leaf 찾기
	max = find_diameter(1, -1);
	max = find_diameter(max.first, -1);
	cout << max.second << '\n';
	
	delete[] edges;
	return 0;
} 
