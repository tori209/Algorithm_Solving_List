/*
	10451��
	����: ���� ����Ŭ
	�Է�: �׽�Ʈ ���̽� ���� t,
		�� �׽�Ʈ ���̽��� ���Ͽ� ���� ũ�� n�� ����
	���: �� �׽�Ʈ ���̽��� ���� ����Ŭ ����
	
	��� ������ ���Ͽ� inbound 1��, outbound 1���̹Ƿ� (�����̹Ƿ�.),
	�� ������ �� �ϳ��� ����Ŭ�� �ݵ�� ���ԵǾ�߸� �ϸ�,
	�̴� �ϳ��� SCC�� �� �ϳ��� ����Ŭ�� �����Ѵٴ� ���� �ȴ�.
	��, SCC ������ ã���� ������.
	(�ٵ� ������ �̹����� SCC�� �Ϲ� ���� ��� ã�� ������� ã����.) 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, n, cur;
	int cnt;
	int perm[1001];
	bool visit[1001];
	
	cin >> t;
	while(t--) {
		fill_n(visit, 1001, false);
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> perm[i];
		
		for (int i = 1; i <= n; i++) {
			if (visit[i]) continue;
			cur = i;
			do {
				visit[cur] = true;
				cur = perm[cur];
			} while (cur != i);
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
} 
