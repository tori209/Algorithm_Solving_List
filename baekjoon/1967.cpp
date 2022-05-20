/*
	1967��
	����: Ʈ���� ����
	�Է�: ���� V(2 �̻� 100,000 ����),
		�� �ະ�� ���� ��� 2��, ���� ����ġ 
		�� ����ġ�� 10,000 ���� �ڿ����̴�
	���: Ʈ���� ���� (������ �� ���� ������ �Ÿ�(=����ġ�� ��) �� �ִ밪.)
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
	
	// Ʈ�� ���� 
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
	
	// leaf ã��
	max = find_diameter(1, -1);
	max = find_diameter(max.first, -1);
	cout << max.second << '\n';
	
	delete[] edges;
	return 0;
} 
