/*
	2580��
	����: ������
	�Է�: ������ ����
	���: ���� �ش�
	�� ä��� ������ ����Ŭ�� �����Ǹ� �������� �ذ��ؾ���. (�翬�� ���� ��...) 
*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> blank;

bool solve(int idx) {
	if (idx == blank.size()) return true;
	
	int i = blank[idx].first;
	int j = blank[idx].second;
	
	bool filled[10] = {true,};
	
	// ���� ĭ
	for (int x = i / 3 * 3; x < i / 3 * 3 + 3; x++)
	for (int y = j / 3 * 3; y < j / 3 * 3 + 3; y++) {
		if (x == i && y == j) continue;
		filled[sudoku[x][y]] = true;
	} 
	// ���� ������
	for (int x = 0; x < 9; x++) {
		if (x == i) continue;
		filled[sudoku[x][j]] = true;
	}
	// ���� ������
	for (int y = 0; y < 9; y++) {
		if (y == j) continue;
		filled[sudoku[i][y]] = true;
	}

	int cnt = 0;
	for (int idx = 1; idx < 10; idx++) {
		if (filled[idx])  cnt++;
	}
	
	if (cnt == 9) return false;
	else {
		for (int v = 1; v < 10; v++) {
			if (filled[v]) continue;
			sudoku[i][j] = v;
			if (solve(idx + 1)) {
				return true;
			}
			else sudoku[i][j] = 0;
		}
		return false;
	}
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
		cin >> sudoku[i][j];
		if (sudoku[i][j] == 0) blank.push_back({i, j});
	}
	
	solve(0);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cout << sudoku[i][j] << ' ';
		cout << '\n';
	}
	
	return 0;
}
