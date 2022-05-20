/*
	2331번
	문제: 반복 수열
	입력: 수열 1번째 수 A(1이상 10,000 미만)와 P(1 이상 5 이하)
	출력: 규칙대로 수열을 구성하였을 때, 반복 수열을 제거하였을 때 남는 수들의 개수
	
	수열 점화식
	D[1] = A
	D[n] = D[n-1]의 각 자리수를 P번 곱한 것들의 합
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
