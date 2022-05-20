/*
	2745번
	문제: 진법 변환
	입력: b진법 수 n과 자연수 b
	출력: n을 10진법으로 변환한 값
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	stack<char> s;
	char c;
	int b;
	long long sum = 0LL;
	long long digit = 1;
	
	while (cin.get(c) && c != '\n' && c != ' ') {
		s.push(c);
	}
	cin >> b;
	while (!s.empty()) {
		c = s.top();
		if (c >= '0' && c <= '9') sum += digit * (long long)(c - '0');
		else sum += digit * (long long)(c - 'A' + 10);
		digit *= (long long)b;
		s.pop();
	}
	
	cout << sum << '\n';
	
	
	return 0;
} 
