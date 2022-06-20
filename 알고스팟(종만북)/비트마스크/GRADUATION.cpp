/*
	GRADUATION
	�Է� : �׽�Ʈ ���̽� �� c (50 ����)
		���� ���� �� N (1 �̻� 12 ����), �ּ� ���� ���� �� K (0 �̻� N ����), �б� �� M (1 �̻� 10 ����), �б� �� �ִ� ���� ���� Ƚ�� L(1 �̻� 10 ����)
		�� �� ������ 0 ~ n-1�� �ѹ��� �Ǿ� ����.
		N�ٿ� ���� �� ������ ���� ���� ������ ����� ���õ�. 
		�� ������������ ������ ���, �̸� �̸� ���� �Ϸ��� �İ� �Ǿ�� ������ �����ϴ�. 
		M�ٿ� ���� �ش� �б⿡ �����Ǵ� ���� �� �� ����� ���õ�. 
	��� : �ּ� ���� ���� ���� ä��� ���� �ٳ�� �� �ּ� �б�. �Ұ����� ��� "IMPOSSIBLE" ��� 
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
	
	// ���� �Ұ� �ɷ����� 
	for (int i = 0; i < n; i++) {
		if ((subject & (1U << i)) == 0) continue;
		if ((pre_subject[i] & finished) == pre_subject[i]) continue;
		subject &= ~(1U << i);
	}
	
	for (int reg = subject; reg != 0; reg = ((reg - 1) & subject)) {
		if (cntSubject(reg) > l) continue;
		ret = min(ret, registering (term + 1, finished | reg) + 1);
	}
	ret = min(ret, registering(term + 1, finished));	// ������ ��� 
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
