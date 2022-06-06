/*
	2143�� 
	����: �� �迭�� ��
	�Է�: ���ϴ� �� t (������ 1,000,000,000 ����)
		�迭 a�� ũ�� n(1 �̻� 1,000 ����), ���� �� a�� ������ (������ 1,000,000 ����) 
		�迭 b�� ũ�� m(1 �̻� 1,000 ����), ���� �� b�� ������ (������ 1,000,000 ����) 
	���: �迭 a�� �����հ� b�� �������� ���� t�� �Ǵ� ����� �� 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a_sum;
vector<int> b_sum;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long ret = 0;
	int t, n, m;
	int sum, subsum;
	int a[1000], b[1000];
	
	cin >> t >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			a_sum.push_back(sum);
		}
	}
	sort(a_sum.begin(), a_sum.end());
	
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = i; j < m; j++) {
			sum += b[j];
			b_sum.push_back(sum);
		}
	}
	sort(b_sum.begin(), b_sum.end());
	
	int a_idx = 0, b_idx = b_sum.size() - 1;
	while (1) {
		if (a_idx == a_sum.size() || b_idx == -1) break;
		
		sum = a_sum[a_idx] + b_sum[b_idx];
		if (sum < t) a_idx++;
		else if (sum > t) b_idx--;
		else {
			int a_num, b_num;
			for (a_num = a_idx; a_num < a_sum.size() - 1; a_num++)
				if (a_sum[a_num] != a_sum[a_num + 1]) break;
			for (b_num = b_idx; b_num > 0; b_num--)
				if (b_sum[b_num] != b_sum[b_num - 1]) break;
			ret += (long long)(a_num - a_idx + 1) * (long long)(b_idx - b_num + 1);
			a_idx = a_num + 1;
			b_idx = b_num - 1;
		}
	}
	
	cout << ret << '\n';
	
	return 0;
}
