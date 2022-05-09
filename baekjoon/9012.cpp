/*
	9012��
	����: ��ȣ 
	�Է�: ���ڿ� ���� n�� �Ұ�ȣ�� ������ ���ڿ� n�� 
	���: �� ���ڿ��� VPS ���θ� YES or NO�� ���.
	
	�� VPS
	��ȣ�� ������ ������ ���� ���ڿ�.
	����, ()�� �⺻ VPS��� �θ���,
	VPS�� X�� ���� ���ο� ���ڿ� (X) ���� VPS��� �� �� �ִ�. 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, cnt;
	string vps;
	
	cin >> n;
	while (n-- > 0) {
		cnt = 0;
		cin >> vps;
		for (char c : vps) {
			if (c == '(') cnt++;
			else cnt--;
			
			if (cnt < 0) break;
		}
		cout << (cnt == 0 ? "YES\n" : "NO\n");
	}
	
	return 0;
}
