/*
	1783번
	문제: 병든 나이트
	입력: 체스판의 세로 길이 n, 가로 길이 m (2,000,000,000 이하 자연수) 
	출력: 방문할 수 있는 칸의 개수 중 최댓값
	// 이동을 최대 몇번까지 할 수 있는가를 뜻하지, 어느 칸을 몇번이나 이동할 수 있는지를 묻는 것이 아니다. 
	※ 나이트 이동
	오른쪽 2칸, 위/아래 1칸
	오른쪽 1칸, 위/아래 2칸
*/

#include <iostream>

typedef unsigned long long ull;
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	ull n, m, cnt = 1;
	cin >> n >> m;
	
	if (n == 1) {
		cout << 1 << '\n';
	} else if (n == 2) {
		cout << (m > 7 ? 4 : (m - 1)/2 + 1) << '\n';
	} else if (m < 7) {
		cout << (m > 4 ? 4 : m) << '\n';
	} else {
		cout << m - 2 << '\n';
	}
	return 0;
} 
