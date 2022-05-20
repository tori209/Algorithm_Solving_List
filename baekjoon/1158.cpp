/*
	1158번
	문제: 요세푸스 문제
	입력: 양의 정수 k, n (1 <= k <= n <= 5,000)
	출력: 주어진 수로 구성한 요세푸스 순열
	
	※ 요세푸스 순열
	n명의 사람이 원을 이루고 앉아있고, 1번부터 n번까지 존재할 때,
	k번을 제거하고, k+1번을 기준으로 k번째에 있는 인원을 다시 제거한다.
	이를 반복하여 모든 인원을 제거한 뒤, 제거된 순서대로 번호를 나열한 것을  요세푸스 순열이라고 한다.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, k, cur;
	queue<int> q, ret;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)  q.push(i);
	
	n = 1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (n == k) {
			ret.push(cur);
			n = 1;
		} else {
			q.push(cur);
			n++;
		}
	}
	
	cout << '<';
	while (!ret.empty()) {
		cout << ret.front();
		if (ret.size() != 1) cout << ", ";
		ret.pop();
	}
	cout <<  ">\n";
	return 0;
}
