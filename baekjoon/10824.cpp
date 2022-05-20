/*
	10824번
	문제: 네 수
	입력: 숫자 A, B, C, D
	출력: 문자열 X, Y를 CONCATENATE한 것을 XY라 할 때, AB + CD
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long sum = 0LL;
	string s1, s2;
	cin >> s1 >> s2;
	sum += stoll(s1+s2);
	cin >> s1 >> s2;
	sum += stoll(s1+s2);
	
	cout << sum << '\n';
	
	return 0;
} 
