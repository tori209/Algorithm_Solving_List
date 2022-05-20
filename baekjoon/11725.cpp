/*
	11725번
	문제: 트리의 부모 찾기
	입력: 트리의 노드 개수 n, 인접한 노드 쌍 n개
	출력: 2~n번 노드의 부모 노드 (1은 root라 가정.) 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, v1, v2;
	int parent[100001] = {0, 1,};
	vector<int> * edges = new vector<int>[100001];
	queue<int> q;
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}
	
	q.push(1);
	while(!q.empty()) {
		v1 = q.front();
		q.pop();
		
		for (int v : edges[v1]) {
			if (parent[v] != 0) continue;
			parent[v] = v1;
			q.push(v);
		}
	}
	
	for (int i = 2; i <= n; i++) cout << parent[i] << '\n';
	
	return 0;
}
