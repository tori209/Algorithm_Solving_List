/********************
	9461�� 
	����: �ĵ��� ���� 
	�Է�: �׽�Ʈ ���̽� ���� T�� T���� �ڿ��� (100 ���� �ڿ���) 
	���: �ĵ��� ���� P(n)�� �� T�� 
********************/	

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0); 
	ios::sync_with_stdio(0);
	
	int t, n;
	long long padovan[101] = {0, 1, 1, 1, 2, 2,};
	
	cin >> t;
	for (int i = 6; i <= 100; i++) {
		padovan[i] = padovan[i-5] + padovan[i-1];
	}
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << padovan[n] << '\n';
	}
	
	return 0;	
}
