/*
	9019번
	문제: DLSR
	입력: 테스트 케이스 수 t,
		개행 후 정수 a, b (0 이상 10,000 이하) 
	출력: a에서 b로 변환하기 위해 필요한 최소한의 명령어 나열
	※ 숫자는 양의 정수 4자리 수까지만 저장할 수 있다고 한다. 
	
	※ 명령어
	D: n을 2배로 변환하며, 10000 이상일 경우 나머지만을 취한다.
	S: n에서 1을 뺀다. n이 0일 경우 9999가 된다.
	L: n을 왼쪽으로 자리이동하며, d1에 위치하는 자리는 d4로 이동한다.
	R: n을 오른쪽으로 자리이동하며, d4에 위치하는 자리는 d1으로 이동한다.
*/

#include <iostream>
#include <utility>
#include <queue>
#include <string>

using namespace std;

int a, b;
queue<pair<int, string>> nodes;
bool visit[10000];

int D (int n) {   return (2 * n) % 10000;   }
int S (int n) {   return (n == 0 ? 9999 : n - 1);   }
int L (int n) {   return (n * 10) % 10000 + n / 1000;   }
int R (int n) {   return (n / 10) + (n % 10) * 1000;   }

string bfs (int node_num) {
	int next_num = 0;
	while (node_num--) {
		pair<int, string> num = nodes.front();
		nodes.pop();
		
		if (num.first == b) {
			return num.second;
		}
		
		if (!visit[D(num.first)]) {
			nodes.push({D(num.first), num.second + "D"});
			visit[D(num.first)] = true;
			next_num++;
		}
		if (!visit[S(num.first)]) {
			nodes.push({S(num.first), num.second + "S"});
			visit[S(num.first)] = true;
			next_num++;
		}
		if (!visit[L(num.first)]) {
			nodes.push({L(num.first), num.second + "L"});
			visit[L(num.first)] = true;
			next_num++;
		}
		if (!visit[R(num.first)]) {
			nodes.push({R(num.first), num.second + "R"});
			visit[R(num.first)] = true;
			next_num++;
		}
	}
	return bfs(next_num);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		nodes.push({a, ""});
		fill_n(visit, 10000, false);
		visit[a] = true;
		cout << bfs(1) << '\n';
		while (!nodes.empty()) nodes.pop();
	}
	
	return 0;
}
