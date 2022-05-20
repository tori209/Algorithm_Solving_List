/*
	2331��
	����: �ݺ� ����
	�Է�: ���� 1��° �� A(1�̻� 10,000 �̸�)�� P(1 �̻� 5 ����)
	���: ��Ģ��� ������ �����Ͽ��� ��, �ݺ� ������ �����Ͽ��� �� ���� ������ ����
	
	���� ��ȭ��
	D[1] = A
	D[n] = D[n-1]�� �� �ڸ����� P�� ���� �͵��� ��
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	bool visit[400000] = {false,};
	vector<int> perm;
	int A, P, sum, cur;
	int ret;
	
	cin >> A >> P;
	perm.push_back(A);
	
	cur = A;
	while (!visit[cur]) {
		sum = 0;
		visit[cur] = true;
		while (cur) {
			sum += pow(cur % 10, P);
			cur /= 10;
		}
		cur = sum;
		perm.push_back(cur);
	}
	
	for (ret = 0; perm[ret] != cur; ret++) {}
	cout << ret << '\n';
	
	return 0;
}
