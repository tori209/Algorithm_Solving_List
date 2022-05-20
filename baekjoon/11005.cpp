/*
	11005��
	����: ���� ��ȯ 2
	�Է�: 10���� �� n�� �ڿ��� b
	���: n�� b������ ��ȯ�� ��.
	(10: A, 11: B, ... , 34: Y, 35: Z�� ����.)
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
