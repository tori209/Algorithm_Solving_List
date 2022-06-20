/*
	CHRISTMAS
	����: k���� ������ ���ְ��� �峭�� ������ �ִ� n���� �������� �� h��~t�� ���ڸ� ��� �����Ͽ� ��� �ο����� ��Ȯ�� ���� ���� ������ �����ְ�, ���� ������ ���Բ� �Ϸ��� �Ѵ�.
		�̶�, �� ���� �ֹ��Ѵٸ� ������ �ֹ� ����� ����̸�, ���� �� �ֹ��� �� �ִٸ� �ֹ��� ��ġ�� �ʰ� �ִ� �� �� �ֹ��� �� �ִ°�? 
	�Է�: �׽�Ʈ ���̽� �� t (60 ����)
		���� ���� ���� n�� ��� �� k (���� 1 �̻� 100,000 ����)
		�� ���� ���ڿ� ����ִ� ���� ���� Di (1 �̻� 100,000 ����) 
	���: ��� �ο����� ���� ���� ������ �������ְ� ���� ������ ������ �ϱ� ����, 
		�� �� �ֹ��� ��� ������ �ֹ� ���,
		���� �� �ֹ��� ��� ������ �ֹ� �ִ� Ƚ�� 
		�� �� ����� ' '���� �����Ѵ�.
*/

#include <iostream>

#define MAX 987654321
#define MIN -987654321

using namespace std;

int n, k;
int cummulative_sum[100000];

// ������ �� �̻��� ������ �Ǵܵ�. 
int getCount(int pre_idx, int remainder, int cnt) {
	int ret = (remainder == 0 ? cnt : MIN);
	
	// i ~ j�� ������ 
	for (int i = pre_idx + 2; i < n; i++) {
		for (int j = i; j < n; j++) {
			ret = max(
				ret,
				getCount(j, (remainder + cummulative_sum[j] - (i > 0 ? cummulative_sum[i - 1] : 0)) % k, cnt + 1)
			);
		}
	}
	//if (remainder == 0) cout << pre_idx << ' ';
	
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	
	cin >> t;
	while (t--) {
		int ret1 = 0, ret2 = MAX;
		
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (i) cummulative_sum[i] = (cummulative_sum[i - 1] + num) % k;
			else cummulative_sum[i] = num % k;
		}
		
		// �� ���� �ֹ��ϴ� ��� 
		for (int i = 0; i < n; i++) {
			if (cummulative_sum[i] == 0) ret1++;
			for (int j = 1; j <= i; j++)
				if (cummulative_sum[i] - cummulative_sum[j - 1] == 0) (ret1++) % 20091101;
		}
		
		// ���� �� �ֹ��ϴ� ���
		ret2 = max(getCount(-2, 0, 0), 0);
		
		cout << ret1 << ' ' << ret2 << '\n'; 
	}
	
	return 0;
}		 
