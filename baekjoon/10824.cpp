/*
	10824��
	����: �� ��
	�Է�: ���� A, B, C, D
	���: ���ڿ� X, Y�� CONCATENATE�� ���� XY�� �� ��, AB + CD
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
