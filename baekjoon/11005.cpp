/*
	11005번
	문제: 진법 변환 2
	입력: 10진법 수 n과 자연수 b
	출력: n을 b진수로 변환한 값.
	(10: A, 11: B, ... , 34: Y, 35: Z로 쓴다.)
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	char digits[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	stack<char> trans;
	int num;
	int radix;
	
	cin >> num >> radix;
	while (num != 0) {
		trans.push(digits[num % radix]);
		num /= radix;
	}
	while (!trans.empty()) {
		cout << trans.top();
		trans.pop();
	}
	cout << '\n';
	
	return 0;
} 
