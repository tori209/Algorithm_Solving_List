/*
	9019��
	����: DLSR
	�Է�: �׽�Ʈ ���̽� �� t,
		���� �� ���� a, b (0 �̻� 10,000 ����) 
	���: a���� b�� ��ȯ�ϱ� ���� �ʿ��� �ּ����� ��ɾ� ����
	�� ���ڴ� ���� ���� 4�ڸ� �������� ������ �� �ִٰ� �Ѵ�. 
	
	�� ��ɾ�
	D: n�� 2��� ��ȯ�ϸ�, 10000 �̻��� ��� ���������� ���Ѵ�.
	S: n���� 1�� ����. n�� 0�� ��� 9999�� �ȴ�.
	L: n�� �������� �ڸ��̵��ϸ�, d1�� ��ġ�ϴ� �ڸ��� d4�� �̵��Ѵ�.
	R: n�� ���������� �ڸ��̵��ϸ�, d4�� ��ġ�ϴ� �ڸ��� d1���� �̵��Ѵ�.
*/

#include <iostream>
#include <utility>
#include <queue>
#include <string>

using namespace std;

int a, b;
queue<pair<int, string>> nodes;
bool visit[10000];

int D (int n) {   return (2 * n) % 10000;   }
int S (int n) {   return (n == 0 ? 9999 : n - 1);   }
int L (int n) {   return (n * 10) % 10000 + n / 1000;   }
int R (int n) {   return (n / 10) + (n % 10) * 1000;   }

string bfs (int node_num) {
	int next_num = 0;
	while (node_num--) {
		pair<int, string> num = nodes.front();
		nodes.pop();
		
		if (num.first == b) {
			return num.second;
		}
		
		if (!visit[D(num.first)]) {
			nodes.push({D(num.first), num.second + "D"});
			visit[D(num.first)] = true;
			next_num++;
		}
		if (!visit[S(num.first)]) {
			nodes.push({S(num.first), num.second + "S"});
			visit[S(num.first)] = true;
			next_num++;
		}
		if (!visit[L(num.first)]) {
			nodes.push({L(num.first), num.second + "L"});
			visit[L(num.first)] = true;
			next_num++;
		}
		if (!visit[R(num.first)]) {
			nodes.push({R(num.first), num.second + "R"});
			visit[R(num.first)] = true;
			next_num++;
		}
	}
	return bfs(next_num);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		nodes.push({a, ""});
		fill_n(visit, 10000, false);
		visit[a] = true;
		cout << bfs(1) << '\n';
		while (!nodes.empty()) nodes.pop();
	}
	
	return 0;
}
