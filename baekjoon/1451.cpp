/*
	1451��
	����: ���簢������ ������
	�Է�: ���簢���� ���� ũ�� n, ���� ũ�� m, (���� 1 �̻� 50 ����) 
		���� �� �� �������� ĭ�� ���� ����
	���: ���簢���� 3���� ���� ���簢������ �����Ͽ��� ��, �� ���簢�� �� ������ ���� ��� ���� ���� �ִ밪. 
	
	������ ��ġ�� ����, sum ������ �Լ��� ���� AC�� ���´ٴ� ��ʰ� �ټ� ����.
		sum�Լ� ���� �� �̸� �̿��ؼ� �غ���. 
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef unsigned long long ull;

ull square[50][50] = {{0,},};

ull range_sum (pair<int, int> begin, pair<int, int> end) {
	int x1 = begin.first;
	int y1 = begin.second;
	int x2 = end.first;
	int y2 = end.second;
	ull ret = 0ULL;
	
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			ret += square[i][j];
		}
	}
	return ret;
} 

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m;
	ull s1, s2, max = 0ULL;
	ull tot = 0ULL;
	char c;
	
	// �Է� �ޱ�		
	cin >> n >> m;
	cin.get();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin.get(c);
			square[i][j] = (c - '0');
			tot += square[i][j];
		}
		cin.get();
	}

	// ||| ����
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			s1 = range_sum({0, 0}, {n - 1, i});
			s2 = range_sum({0, i + 1}, {n - 1, j});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	
	// = ���� 
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			s1 = range_sum({0, 0}, {i, m - 1});
			s2 = range_sum({i + 1, 0}, {j, m - 1});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	
	// �� ����
	for (int j = 0; j < m - 1; j++) {
		s1 = range_sum({0, 0}, {n - 1, j});
		for (int i = 0; i < n - 1; i++) {
			s2 = range_sum({0, j + 1}, {i, m - 1});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	} 
	// �� ����
	for (int j = 0; j < m; j++) {
		s1 = range_sum({0, j + 1}, {n - 1, m - 1});
		for (int i = 0; i < n - 1; i++) {
			s2 = range_sum({0, 0}, {i, j});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	// �� ����
	for (int i = 0; i < n - 1; i++) {
		s1 = range_sum({0, 0}, {i, m - 1});
		for (int j = 0; j < m - 1; j++) {
			s2 = range_sum({i + 1, 0}, {n - 1, j});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	// �� ���� 
	for (int i = 0; i < n; i++) {
		s1 = range_sum({i, 0}, {n - 1, m - 1});
		for (int j = 0; j < m - 1; j++) {
			s2 = range_sum({0, 0}, {i - 1, j});
			if (max < s1 * s2 * (tot - s1 - s2)) max = s1 * s2 * (tot - s1 - s2);
		}
	}
	
	cout << max << '\n';
	return 0;
}
