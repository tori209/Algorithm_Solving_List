/*
	2251번
	문제: 물통
	입력: 물통 A,B,C의 용량 정수 a, b, c (1 이상 200 이하)
	출력: 물통 a를 비워진 경우, c가 가질 수 있는 물의 양.
	
	※ 물을 옮길 때 흘리는 양은 없고, 물은 붇는 통이 비워지거나, 채우는 통이 가득 찰 때까지 부워야 한다. 
	※ 처음에 물통 A, B는 비워져있고, C는 꽉 채워져 있다. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> ans;
bool visit[201][201] = {{false,}, };
int full[3];


void bfs(vector<int *> vec) {
	if (vec.size() == 0) return;
	
	vector<int *> next;
	
	int * next_w;
	for (int* cur_w : vec) {
		if (cur_w[0] == 0) ans.push_back(cur_w[2]);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j || cur_w[i] == 0) continue;
				
				next_w = new int[3];
				
				if (cur_w[i] + cur_w[j] <= full[j]) {
					next_w[i] = 0;
					next_w[j] = cur_w[i] + cur_w[j];
				} else {
					next_w[i] = cur_w[i] + cur_w[j] - full[j];
					next_w[j] = full[j];
				}
				next_w[3 - i - j] = cur_w[3 - i - j];
				
				if (!visit[next_w[0]][next_w[1]]) {
					next.push_back(next_w);
					visit[next_w[0]][next_w[1]] = true;
				}
			}
		}
	}
	
	bfs(next);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int cur[3];
	
	for (int i = 0; i < 3; i++) {
		cin >> full[i];
	}
	
	cur[0] = 0;
	cur[1] = 0;
	cur[2] = full[2];
	
	visit[0][0] = true;
	vector<int*> vec;
	vec.push_back(cur);
	
	bfs(vec);
	sort(ans.begin(), ans.end());
	for (int n : ans) cout << n << ' ';
	cout << '\n'; 
	
	return 0;
}
