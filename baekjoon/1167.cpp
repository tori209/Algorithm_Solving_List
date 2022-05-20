/*
	1167��
	����: Ʈ���� ����
	�Է�: ���� ���� V(2 �̻� 100,000 ����),
		���� �� ���� ��ȣ, ���� (���� ����, ������ ����ġ)�� ���� ��, ������ �Է��� -1. 
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
	
	int v, v1, v2, length;
	pair<int, int> max;
	
	// Ʈ�� ���� 
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
	
	// leaf ã��
	max = find_diameter(1, -1);
	max = find_diameter(max.first, -1);
	cout << max.second << '\n';
	
	delete[] edges;
	return 0;
} 
