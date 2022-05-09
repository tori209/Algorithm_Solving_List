/*
	10799��
	����: �踷��� 
	�Է�: (�� )�� ������ ���ڿ� 1�� 
	���: �ϴ��� ��Ģ�� ���� ��, �踷��� ���� �� 
	
	�� ��Ģ 
	�踷��⸦ �����ϴ� �������� ���ڿ� "()"���� ǥ���Ѵ�.
	�踷���� "(x)"�� ǥ���Ѵ�. �̶�, x�� (�� )���� ������ ���ڿ��̴�. 
*/

#include <iostream>
#include <stack>	// ���� ��������? �ϴ� �з��� �����̴ϱ� �������� Ǭ��. 
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int cnt = 0;
	string str;
	stack<char> s;
	char pre;
	
	cin >> str;
	for (char c : str) {
		if (c == '(')  {
			s.push('(');
		}
		else {
			s.pop();
			cnt += (pre == '(' ? s.size() : 1);
		}
		pre = c;
	}
	cout << cnt << '\n';
	
	return 0;
}
