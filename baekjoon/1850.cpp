/*
	1850번
	입력: 모든 자리가 1로만 이루어진 두 자연수 a, b 각각이 지닌 1의 개수
	출력: a, b의 최대공약수
	--> 말이 어려워서 그렇지, 그냥 입력된 두 수의 최대공약수를 구해서 그만큼 1을 출력하라는 것임. 
*/

#include <iostream>
#include <string>

using namespace std;

unsigned long long gcd(unsigned long long val1, unsigned long long val2) {
	return (val2 ? gcd(val2, val1 % val2) : val1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned long long a, b;
	cin >> a >> b;
	string ret ((a > b ? gcd(a, b) : gcd(b, a)), '1');
	cout << ret << '\n';
	return 0;
}
