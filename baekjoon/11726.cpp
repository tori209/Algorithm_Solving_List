/****************************
	11726��
	����: 2xn Ÿ�ϸ�  
	�Է�: ���簢���� ���� ���� n 
	���: 2xn�� 1x2, 2x1�� ä��� ����� ��  
****************************/

#include <iostream>
#include <climits>	// �� �ڷ����� �ִ밪�� ����. 

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	int numOfWays[1001];
	numOfWays[1] = 1;
	numOfWays[2] = 2;
	cin >> n;
	for (int i = 3; i < n + 1; i++) {
		numOfWays[i] = (numOfWays[i-1] + numOfWays[i - 2]) % 10007;
	}
	cout << numOfWays[n] << '\n';
	return 0;
}
