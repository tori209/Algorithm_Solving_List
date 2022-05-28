/*
	1963번
	입력: 테스트 케이스 수 t
		개행 후 초기값, 기대값 쌍 t개
	출력: 각 테스트 케이스에 대해 초기값에서 기대값으로 바꾸는데 걸리는 횟수의 최소값
	(한번에 1자리만 바꿀 수 있고, 바뀌는 결과값들은 모두 소수여야만 한다.)
*/

#include <iostream>
#include <vector>

using namespace std;

bool visit[10000];
bool isPrime[10000];
int a, b;

int bfs(int step, vector<int> * cur_node) {
	if (cur_node->size() == 0) return -1;
	
	vector<int> * next_node = new vector<int>;
	int d1, d2, d3, d4;
	for(int num : *cur_node) {
		if (num == b) {
			delete cur_node;
			delete next_node;
			return step;
		}
		
		d1 = num / 1000;
		num %= 1000;
		d2 = num / 100;
		num %= 100;
		d3 = num / 10;
		d4 = num % 10;
		
		for (int i = 0; i < 10; i++) {
			if (isPrime[i * 1000 + d2 * 100 + d3 * 10 + d4] && !visit[i * 1000 + d2 * 100 + d3 * 10 + d4]) {
				next_node->push_back(i * 1000 + d2 * 100 + d3 * 10 + d4);
				visit[i * 1000 + d2 * 100 + d3 * 10 + d4] = true;
			}
			if (isPrime[d1 * 1000 + i * 100 + d3 * 10 + d4] && !visit[d1 * 1000 + i * 100 + d3 * 10 + d4]) {
				next_node->push_back(d1 * 1000 + i * 100 + d3 * 10 + d4);
				visit[d1 * 1000 + i * 100 + d3 * 10 + d4] = true;
			}
			if (isPrime[d1 * 1000 + d2 * 100 + i * 10 + d4] && !visit[d1 * 1000 + d2 * 100 + i * 10 + d4]) {
				next_node->push_back(d1 * 1000 + d2 * 100 + i * 10 + d4);
				visit[d1 * 1000 + d2 * 100 + i * 10 + d4] = true;
			}
			if (isPrime[d1 * 1000 + d2 * 100 + d3 * 10 + i] && !visit[d1 * 1000 + d2 * 100 + d3 * 10 + i]) {
				next_node->push_back(d1 * 1000 + d2 * 100 + d3 * 10 + i);
				visit[d1 * 1000 + d2 * 100 + d3 * 10 + i] = true;
			}
		}
	}
	delete cur_node;
	return bfs(step + 1, next_node);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	int ret;
	vector<int> primes;
	
	primes.push_back(2);
	fill_n(isPrime, 10000, true);
	isPrime[1] = false;
	
	for (int i = 3; i < 10000; i++) {
		for (int p : primes) {
			if (i % p == 0) {
				isPrime[i] = false;
				break;
			}
		}
		if (isPrime[i]) primes.push_back(i);
	}
	
	// 어차피 4자리 소수만 볼거고, 0으로 교체하는 경우에 세자리 이하 숫자를 배제하기 위함. 
	fill_n(isPrime, 1000, false);
	
	cin >> t;
	while(t--) {
		cin >> a >> b;
		vector<int> * vec = new vector<int>;
		vec->push_back(a);
		
		fill_n(visit, 10000, false);
		ret = bfs(0, vec);
		if (ret == -1) cout << "Impossible\n";
		else cout << ret << '\n';
	}
	
	return 0;
} 
