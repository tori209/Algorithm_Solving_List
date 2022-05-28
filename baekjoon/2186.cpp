/*
	2186��
	����:������
	�Է�: �������� ����, ���� ���� n, m(1 �̻� 100 ����), ��ǥ�� �ִ� �̵� �Ÿ� k (1 �̻� 5 ����)
		���� �� n*m ������
		���� �� ������� ���ڿ�
	���: ���ڿ��� ����� ����� ����� ��
	
	�� �̵����� �ʴ� ���� �������� ������, ���� ��ġ�� �ߺ��湮 �� �� �ִ�. 
*/

#include <iostream>
#include <utility>
#include <queue>

typedef unsigned long long ull;
using namespace std;

char tboard[101][101];
char str[81];
int n, m, k, s_len;

ull bfs (int step, ull ** cnter) {
	if (step == s_len) {
		ull cnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cnt += cnter[i][j];
		return cnt;
	}
	
	bool nextExist = false;
	ull ** ncnter = new ull*[100];
	for (int i = 0; i < 100; i++) ncnter[i] = new ull[100] {0,};
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (cnter[i][j] == 0) continue;
		for (int l = -k; l <= k; l++) {
			if (l == 0) continue;
			if (i + l >= 0 && i + l <= n) if (tboard[i + l][j] == str[step]) {
				ncnter[i + l][j] += cnter[i][j];
				nextExist = true;
			}
			if (j + l >= 0 && j + l <= m) if (tboard[i][j + l] == str[step]) {
				ncnter[i][j + l] += cnter[i][j];
				nextExist = true;
			} 
		}
	}
	
	for (int i = 0; i < 100; i++) delete[] cnter[i];
	delete[] cnter;
	return (nextExist ? bfs(step + 1, ncnter) : 0);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int ret = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> tboard[i];
	
	cin >> str;
	for (s_len = 0; str[s_len] != '\0'; s_len++);
	
	ull ** cnter = new ull*[100];
	for (int i = 0; i < 100; i++) cnter[i] = new ull[100] {0,};
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (tboard[i][j] == str[0]) cnter[i][j]++;
	}
	
	cout << bfs(1, cnter) << '\n';
	
	return 0;
} 
