/****************************
	9465��
	����: ��ƼĿ 
	�Է�: �׽�Ʈ ���̽� ���� T
			�� �׽�Ʈ�� ����,
			2xn�� n, �� ���ο� ���� 2n���� ���� 
	���: ���� ���� �ִ밪.
	�� �ϳ��� ���ϸ� �¿������ ������ �����Ѵ�. 
****************************/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t, n;
	//int value[2][1000000];
	//int sum[2][1000000];
	int** value = new int*[2];
	int** sum = new int*[2];
	value[0] = new int[1000000];
	value[1] = new int[1000000];
	sum[0] = new int[1000000];
	sum[1] = new int[1000000];
	
	cin >> t;
	while (t-- > 0) {
		fill_n(value[0], 1000000, 0);
		fill_n(value[1], 1000000, 0);
		cin >> n;
		for (int i = 0; i < n; i++) cin >> value[0][i];
		for (int i = 0; i < n; i++) cin >> value[1][i];
		
		sum[0][0] = value[0][0];
		sum[1][0] = value[1][0];
		sum[0][1] = sum[1][0] + value[0][1];
		sum[1][1] = sum[0][0] + value[1][1];
		for (int i = 2; i < n; i++) {
			sum[0][i] = value[0][i] + ((sum[1][i-1] > sum[1][i-2]) ? sum[1][i-1]: sum[1][i-2]);
			sum[1][i] = value[1][i] + ((sum[0][i-1] > sum[0][i-2]) ? sum[0][i-1]: sum[0][i-2]);
		}
		cout << ((sum[0][n - 1] > sum[1][n - 1]) ? sum[0][n - 1] : sum[1][n - 1]) << '\n';
	}
	
	delete value[0], value[1];
	delete sum[0], sum[1];
	delete sum, value;
	
	return 0;
}
