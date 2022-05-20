/*
	9466��
	����: �� ������Ʈ 
	�Է�: �׽�Ʈ ���̽� �� T,
		���� �� �� �׽�Ʈ ���̽��� ���Ͽ�
		�л� �� n (2 �̻� 100,000 ����) / 1~n�� ������ �л� ��ȣ (������) 
	���: �� �׽�Ʈ ���̽��� ���� ���� �̷��� ���� ���.
	
	�� ���� �̷�� ��� = Cycle ����. (loop�� ����.) 
*/

#include <iostream>

using namespace std;

bool visit[100001];
int inCycle[100001];
int edge[100001];
int cnt;

int chkCycle(int vtx) {
	if (visit[vtx]) {
		if (inCycle[vtx] == 0) return vtx;
		else return -1;
	}
	
	visit[vtx] = true;
	int rslt = chkCycle(edge[vtx]);
	if (rslt == -1) {
		inCycle[vtx] = -1;
		cnt++;
		return -1;
	} else if (rslt == vtx) {
		inCycle[vtx] = 1;
		return -1;
	} else {
		inCycle[vtx] = 1;
		return rslt;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, n;
	
	cin >> t;
	while (t--) {
		fill_n(visit, 100001, false);
		fill_n(inCycle, 100001, 0);
		fill_n(edge, 100001, -1);
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> edge[i];
		
		for (int i = 1; i <= n; i++) {
			if (inCycle[i] != 0) continue;
			chkCycle(i);
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}
