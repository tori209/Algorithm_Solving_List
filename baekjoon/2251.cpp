/*
	2251��
	����: ����
	�Է�: ���� A,B,C�� �뷮 ���� a, b, c (1 �̻� 200 ����)
	���: ���� a�� ����� ���, c�� ���� �� �ִ� ���� ��.
	
	�� ���� �ű� �� �긮�� ���� ����, ���� �Ѵ� ���� ������ų�, ä��� ���� ���� �� ������ �ο��� �Ѵ�. 
	�� ó���� ���� A, B�� ������ְ�, C�� �� ä���� �ִ�. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> ans;
bool visit[201][201] = {{false,}, };
int full[3];


void bfs(vector<int *> vec) {
	if (vec.size() == 0) return;
	
	vector<int *> next;
	
	int * next_w;
	for (int* cur_w : vec) {
		if (cur_w[0] == 0) ans.push_back(cur_w[2]);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j || cur_w[i] == 0) continue;
				
				next_w = new int[3];
				
				if (cur_w[i] + cur_w[j] <= full[j]) {
					next_w[i] = 0;
					next_w[j] = cur_w[i] + cur_w[j];
				} else {
					next_w[i] = cur_w[i] + cur_w[j] - full[j];
					next_w[j] = full[j];
				}
				next_w[3 - i - j] = cur_w[3 - i - j];
				
				if (!visit[next_w[0]][next_w[1]]) {
					next.push_back(next_w);
					visit[next_w[0]][next_w[1]] = true;
				}
			}
		}
	}
	
	bfs(next);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int cur[3];
	
	for (int i = 0; i < 3; i++) {
		cin >> full[i];
	}
	
	cur[0] = 0;
	cur[1] = 0;
	cur[2] = full[2];
	
	visit[0][0] = true;
	vector<int*> vec;
	vec.push_back(cur);
	
	bfs(vec);
	sort(ans.begin(), ans.end());
	for (int n : ans) cout << n << ' ';
	cout << '\n'; 
	
	return 0;
}
