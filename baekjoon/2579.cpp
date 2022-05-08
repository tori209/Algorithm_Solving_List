/********************
	2579�� 
	����: ��� ������ 
	�Է�: �� ��� �� (300����)�� �� ����� ���� (10,000 ���� �ڿ���) 
	���: ��Ģ�� ���� ����� �ö��� ��, ���� �� �ִ� �� ������ �ִ밪
	
	�� ��Ģ
		1. ����� �ѹ��� �� ���, Ȥ�� �� ��� ���� �� �ִ�.
		2. ���ӵ� �� ����� ��� ���� �� ����. ��, �������� ����� �ƴϴ�.
		3. �������� �׻� ������ ����� ��´�. 
********************/

#include <iostream>
#include <climits>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	int score[301] = {0,};
	int sum[2][301];
	cin >> n;
	score[0] = 0;
	for (int i = 1; i < n+1; i++) cin >> score[i];
	
	sum[0][0] = 0;
	sum[1][0] = 0;
	sum[0][1] = score[1];
	sum[1][1] = INT_MIN;
	for (int i = 2; i < n + 1; i++) {
		sum[0][i] = score[i] + (sum[0][i-2] > sum[1][i-2] ? sum[0][i-2] : sum[1][i-2]);
		sum[1][i] = score[i] + sum[0][i-1];
	}
	
	cout << (sum[0][n] > sum[1][n] ? sum[0][n] : sum[1][n]) << '\n';
	return 0;	
}
