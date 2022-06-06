/*
	1009��
	����: �л�ó��
	�Է�: �׽�Ʈ ���̽� t,
		�� �ٿ� ���� ���� a (1 �̻� 100 �̸�), b (1 �̻� 1,000,000 �̸�)
	���: �� �׽�Ʈ ���̽��� ���� ������ �����Ͱ� ó���Ǵ� ��ǻ���� ��ȣ.
	�� ��ǻ�Ͱ� �� 10�� ������, 1�� �����ʹ� 1�� ��ǻ��, 2�� �����ʹ� 2�� ��ǻ��, 3�� �����ʹ� 3�� ��ǻ��, ... ������ �������ִ�.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int cycle;
	int order[10];
	bool visited[10];
	int t, a, b;
	cin >> t;
	while (t--) {
		fill_n(visited, 10, false);
		cycle = 0;
		
		cin >> a >> b;
		
		int num = a % 10;
		while (!visited[num]) {
			visited[num] = true;
			order[cycle++] = num;
			num = (num * a) % 10;
		}
		cout << (order[(b-1) % cycle] == 0 ? 10 : order[(b-1) % cycle]) << '\n';
	}
	
	return 0;
} 
