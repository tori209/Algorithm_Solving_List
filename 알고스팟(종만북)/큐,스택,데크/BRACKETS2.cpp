/*
	BRACKETS2
	입력: 테스트 케이스 수 c (1 이상 100 이하)
		이후 []{}()으로 구성된 문자열 c개 (길이: 10,000 이하)
	출력: 괄호들이 cross(ex. [(]) )되지 않고, 괄호들이 제대로 닫혀있고, 괄호를 열었을 때 같은 종류의 괄호로 닫힐 경우 "YES",
		세 조건 중 하나라도 아닐 경우 "NO"
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
