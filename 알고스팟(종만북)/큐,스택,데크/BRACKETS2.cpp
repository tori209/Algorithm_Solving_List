/*
	BRACKETS2
	�Է�: �׽�Ʈ ���̽� �� c (1 �̻� 100 ����)
		���� []{}()���� ������ ���ڿ� c�� (����: 10,000 ����)
	���: ��ȣ���� cross(ex. [(]) )���� �ʰ�, ��ȣ���� ����� �����ְ�, ��ȣ�� ������ �� ���� ������ ��ȣ�� ���� ��� "YES",
		�� ���� �� �ϳ��� �ƴ� ��� "NO"
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	bool isMatched;
	int c, n;
	char str[10001];
	stack<char> bracket;
	
	cin >> c;
	while (c--) {
		isMatched = true;
		while (!bracket.empty()) bracket.pop();
		
		cin >> str;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
				bracket.push(str[i]);
				continue;
			}
				
			
			if (str[i] == ')') {
				if (bracket.empty() || bracket.top() != '(') {
					isMatched = false;
					break;
				}
				bracket.pop();
				continue;
			}
			
			if (str[i] == ']') {
				if (bracket.empty() || bracket.top() != '[') {
					isMatched = false;
					break;
				}
				bracket.pop();
				continue;
			}
			
			if (str[i] == '}') {
				if (bracket.empty() || bracket.top() != '{') {
					isMatched = false;
					break;
				}
				bracket.pop();
				continue;
			}
		}
		cout << (isMatched && bracket.empty() ? "YES\n" : "NO\n");
	}
	
	return 0;
} 
