/*
	1525��
	����: ����
	�Է�: 3x3 ���� ����. (1~8, ���� = 0)
	���: 3x3 ���� ������ [[1, 2, 3],[4, 5, 6][7, 8, 0]]���� �����ϴ� �ּ��� �̵�Ƚ��. �Ұ��� �� -1.
*/

#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <map>

#define RESULT "123456780"

using namespace std;

queue<pair<string, int>> q;
map<string, bool> visit;

int bfs(int step, int num) {
	if (num == 0) return -1;
	
	int next_num = 0;
	
	while(num--) {
		string puz = q.front().first;
		int zeroIdx = q.front().second;
		q.pop();
		
		if (puz == RESULT) return step;
		
		string temp;
		if (zeroIdx - 3 >= 0) {
			temp = puz;
			swap(temp[zeroIdx], temp[zeroIdx - 3]);
			if (!visit[temp]) {
				q.push({temp, zeroIdx - 3});
				next_num++;
				visit[temp] = true;
			}
		}
		if (zeroIdx + 3 < 9) {
			temp = puz;
			swap(temp[zeroIdx], temp[zeroIdx + 3]);
			if (!visit[temp]) {
				q.push({temp, zeroIdx + 3});
				next_num++;
				visit[temp] = true;
			}
		}
		if (zeroIdx % 3 != 0) {
			temp = puz;
			swap(temp[zeroIdx], temp[zeroIdx - 1]);
			if (!visit[temp]) {
				q.push({temp, zeroIdx - 1});
				next_num++;
				visit[temp] = true;
			}	
		}
		if (zeroIdx % 3 != 2) {
			temp = puz;
			swap(temp[zeroIdx], temp[zeroIdx + 1]);
			if (!visit[temp]) {
				q.push({temp, zeroIdx + 1});
				next_num++;
				visit[temp] = true;
			}
		}
	}
	
	return bfs(step+1, next_num);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	string s = "";
	string temp;
	int zeroIdx;
	for (int i = 0; i < 9; i++) {
		cin >> temp;
		s += temp;
		if (temp == "0") zeroIdx = i;
	}
	
	visit[s] = true;
	q.push({s, zeroIdx});
	cout << bfs(0, 1) << '\n';
	
	
	return 0;
} 
