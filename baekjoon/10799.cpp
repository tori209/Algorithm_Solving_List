/*
	10799번
	문제: 쇠막대기 
	입력: (과 )로 구성된 문자열 1개 
	출력: 하단의 규칙에 따를 때, 쇠막대기 조각 수 
	
	※ 규칙 
	쇠막대기를 절단하는 레이저는 문자열 "()"으로 표현한다.
	쇠막대기는 "(x)"로 표현한다. 이때, x는 (과 )으로 구성된 문자열이다. 
*/

#include <iostream>
#include <stack>	// 굳이 스택으로? 일단 분류가 스택이니까 스택으로 푼다. 
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
