/*
	11004��
	����: K��° �� 
	�Է�: ���� ���� n(1~5,000,000)�� k(1�̻� n ����) / n���� ���� 
	���: �������� ���� �� �տ��� k��° �� 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, k;
	int temp;
	vector<int> vec;
	cin >> n >> k;
	while (n-- > 0) {
		cin >> temp;
		vec.push_back(temp);
	}
 	sort (vec.begin(), vec.end());
 	
 	cout << vec[k-1] << '\n';
	return 0;
}
