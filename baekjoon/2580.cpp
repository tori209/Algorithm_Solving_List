/*
	2580번
	문제: 스도쿠
	입력: 스도쿠 문제
	출력: 문제 해답
	※ 채우는 과정에 사이클이 구성되면 추정으로 해결해야함. (당연히 없는 줄...) 
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
	
	// 같은 칸
	for (int x = i / 3 * 3; x < i / 3 * 3 + 3; x++)
	for (int y = j / 3 * 3; y < j / 3 * 3 + 3; y++) {
		if (x == i && y == j) continue;
		filled[sudoku[x][y]] = true;
	} 
	// 같은 가로줄
	for (int x = 0; x < 9; x++) {
		if (x == i) continue;
		filled[sudoku[x][j]] = true;
	}
	// 같은 세로줄
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
