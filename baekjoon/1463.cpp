/****************************
	1463��
	����: 1�� �����
	�Է�: 1 �̻� 10^6 ���� ���� N
	���: �ϴ��� ��Ģ�� ������ ��, N�� 1�� ����� ���� ��Ģ ���� Ƚ�� �ּҰ�
	
	��Ģ:
		1. X % 3 == 0�� TRUE�̸� 3���� ����
		2. X % 2 == 0�� TRUE�̸� 2�� ����
		3. 1�� ����. 
****************************/

#include <iostream>
#include <climits>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	unsigned short count[1000001];
	fill_n(count, 1000001, USHRT_MAX - 1);
	
	cin >> n;
	count[n] = 0;
	for (int i = n; i > 0; i--) {
		if (i % 3 == 0) count[i/3] = ((count[i/3] < count[i] + 1) ? count[i/3] : count[i] + 1);
		if (i % 2 == 0) count[i/2] = ((count[i/2] < count[i] + 1) ? count[i/2] : count[i] + 1);
		count[i - 1] = ((count[i - 1] < count[i] + 1) ? count[i - 1] : count[i] + 1);
	}
	
	cout << count[1] << '\n';
	return 0;
}
