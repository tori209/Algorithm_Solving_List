/*
	11655번
	문제: ROT13
	입력: 문자열 S
	출력: 카이사르 암호, 13을 키값으로 S를 암호화한 문자열. (영어 소문자, 대문자만.) 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string s;
	getline(cin, s);
	
	for (char c : s) {
		if (c >= 'a' && c <= 'z') cout << (char)('a' + (c - 'a' + 13) % 26);
		else if (c >= 'A' && c <= 'Z') cout << (char)((c - 'A' + 13) % 26 + 'A');
		else cout << c;
	}
	cout << '\n';
	
	return 0;
} 
