/*
	1987번
	입력: 보드 길이 r, c(1 이상 20이하) 및 보드에 적힌 알파벳
	출력: 말이 좌측 상단에서 시작하여 이동할 수 있는 칸의 최대 개수. (도달하는 칸의 알파벳은 겹치지 않는다.)
*/

#include <iostream>

using namespace std;

char board[20][20];
int r, c;
int m[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int move(int x, int y, int mask, int step) {
	int ret = step;
	int temp;
	for (int i = 0; i < 4; i++) {
		int x1 = x + m[i][0];
		int y1 = y + m[i][1];
		if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c) {
			if ((mask & (1 << (board[x1][y1] - 'A'))) != 0) continue;
			temp = move(x1, y1, mask | (1 << (board[x1][y1] - 'A')), step + 1);
			if (ret < temp) ret = temp;
		}
	}
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];
	
	cout << move(0, 0, 1 << (board[0][0] - 'A'), 1) << '\n';
	
	return 0;
}
