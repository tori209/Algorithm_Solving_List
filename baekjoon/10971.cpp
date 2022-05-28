/*
	10971��
	����: ���ǿ� ��ȸ 2
	�Է�: ������ �� N(2 �̻� 10 ����), ��� ���
	���: ��ȸ�� �ʿ��� �ּ� ���
	�� �׻� ��ȸ�� �� �ִ� �Է¸� �����ȴ�. 
	
	�� ��� ���
	�������� ���� W[i][j]�� ���� i���� j�� ���� ���� ����̴�.
	�̶�, W[i][j] == 0�̸� ���� i���� j�� �� �� ����.
	����, �ڱ� �ڽ����� ���ƿ��� ������ ����.
*/
#include <iostream>
#include <climits>

using namespace std;

unsigned int w[10][10];
int n;
unsigned int m = 10000001;

void dfs(int node, int step, int val, int visit) {
	if (step == n) {
		if (w[node][0] != 0) m = (m > val + w[node][0] ? val + w[node][0] : m);
		return;  
	}
	
	int mask = 1;
	for (int i = 1; i < n; i++) {
		mask = mask << 1;
		if (w[node][i] == 0 || ((visit & mask) != 0)) continue;
		dfs(i, step + 1, val + w[node][i], visit | mask); 
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> w[i][j];
	for (int i = 0; i < n; i++) bitmask += (1 << i);
	
	dfs(0, 1, 0, 1);
	
	cout << m << '\n';
	
	return 0;
} 
