/*
	1167번
	문제: 트리의 지름
	입력: 정점 개수 V(2 이상 100,000 이하),
		개행 후 정점 번호, 이후 (인접 정점, 간선의 가중치)가 여러 개, 마지막 입력은 -1. 
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
	
	int v, v1, v2, length;
	pair<int, int> max;
	
	// 트리 구축 
	cin >> v;
	edges = new vector<pair<int, int>>[v + 1];
	for (int i = 0; i < v ; i++) {
		cin >> v1;
		
		while(1) {
			cin >> v2;
			if (v2 == -1) break;
			cin >> length;
			edges[v1].push_back(make_pair(v2, length));
		}
	}
	
	// leaf 찾기
	max = find_diameter(1, -1);
	max = find_diameter(max.first, -1);
	cout << max.second << '\n';
	
	delete[] edges;
	return 0;
} 
