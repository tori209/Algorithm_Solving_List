/*
	1158��
	����: �似Ǫ�� ����
	�Է�: ���� ���� k, n (1 <= k <= n <= 5,000)
	���: �־��� ���� ������ �似Ǫ�� ����
	
	�� �似Ǫ�� ����
	n���� ����� ���� �̷�� �ɾ��ְ�, 1������ n������ ������ ��,
	k���� �����ϰ�, k+1���� �������� k��°�� �ִ� �ο��� �ٽ� �����Ѵ�.
	�̸� �ݺ��Ͽ� ��� �ο��� ������ ��, ���ŵ� ������� ��ȣ�� ������ ����  �似Ǫ�� �����̶�� �Ѵ�.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, k, cur;
	queue<int> q, ret;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)  q.push(i);
	
	n = 1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (n == k) {
			ret.push(cur);
			n = 1;
		} else {
			q.push(cur);
			n++;
		}
	}
	
	cout << '<';
	while (!ret.empty()) {
		cout << ret.front();
		if (ret.size() != 1) cout << ", ";
		ret.pop();
	}
	cout <<  ">\n";
	return 0;
}
