/*
	GRADUATION
	입력 : 테스트 케이스 수 c (50 이하)
		전공 과목 수 N (1 이상 12 이하), 최소 수강 과목 수 K (0 이상 N 이하), 학기 수 M (1 이상 10 이하), 학기 당 최대 수강 가능 횟수 L(1 이상 10 이하)
		※ 각 과목은 0 ~ n-1로 넘버링 되어 있음.
		N줄에 걸쳐 각 과목의 선수 과목 개수와 목록이 제시됨. 
		※ 선수과목으로 지정된 경우, 이를 미리 수강 완료한 후가 되어야 수강이 가능하다. 
		M줄에 걸쳐 해당 학기에 개설되는 과목 수 와 목록이 제시됨. 
	출력 : 최소 수강 과목 수를 채우기 위해 다녀야 할 최소 학기. 불가능할 경우 "IMPOSSIBLE" 출력 
*/
#include <iostream>
#include <cmath>

#define IMAX 987654321

using namespace std;

int n, k, m, l;
unsigned int open_subject[10];
unsigned int pre_subject[12];
int dp[10][1 << 13]; 

int cntSubject(unsigned int num) {
	return __builtin_popcount(num);
}

int registering (int term, unsigned int finished) {
	if (cntSubject(finished) >= k) return 0;
	if (term == m) return IMAX;
	
	int& ret = dp[term][finished];
	if (ret != -1) return ret;
	ret = IMAX;
	
	unsigned int subject = open_subject[term] & (~finished);
	
	// 수강 불가 걸러내기 
	for (int i = 0; i < n; i++) {
		if ((subject & (1U << i)) == 0) continue;
		if ((pre_subject[i] & finished) == pre_subject[i]) continue;
		subject &= ~(1U << i);
	}
	
	for (int reg = subject; reg != 0; reg = ((reg - 1) & subject)) {
		if (cntSubject(reg) > l) continue;
		ret = min(ret, registering (term + 1, finished | reg) + 1);
	}
	ret = min(ret, registering(term + 1, finished));	// 휴학할 경우 
	return ret;
} 

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c;
	
	cin >> c;
	while (c--) {
		for (int i = 0; i < 10; i++) 
			fill_n(dp[i], 1 << 13, -1);
			
		cin >> n >> k >> m >> l;
		for (int i = 0; i < n; i++) {
			int r, t;
			
			pre_subject[i] = 0;
			cin >> r;
			while (r--) {
				cin >> t;
				pre_subject[i] |= (1U << t);
			}
		}
		
		for (int i = 0; i < m; i++) {
			int r, t;
			
			open_subject[i] = 0;
			cin >> r;
			while (r--) {
				cin >> t;
				open_subject[i] |= (1U << t);
			}
		}
		
		int ret = registering (0, 0U);
		if (ret > m) cout << "IMPOSSIBLE\n";
		else cout << ret << '\n';
	}
	
	return 0;
} 
