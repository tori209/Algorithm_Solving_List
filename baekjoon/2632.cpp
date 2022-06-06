/*
	2632번
	문제: 피자판매
	입력: 원하는 피자 크기 (2,000,000 이하 자연수)
		개행 후 피자 A, B의 크기 (3 이상 1,000 이하)
		A의 각 피자 조각의 크기, 이후 B의 각 피자 조각의 크기 (각 조각은 1,000 이하) 
	출력: A,B 합쳐서 피자조각을 골랐을 때 판매 가능한 경우의 수. (없으면 0) 
		(판매 시 반드시 연속된 조각들을 골라 판매해야한다.)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int s, a, b, sum, ret = 0;
	int idx, b_idx;
	int ap[1000], bp[1000];
	vector<int> a_case, b_case;
	
	cin >> s;
	cin >> a >> b;
	for (int i = 0; i < a; i++) cin >> ap[i];
	for (int i = 0; i < b; i++) cin >> bp[i];
	
	a_case.push_back(0);
	for (idx = 0; idx != a; idx++) {
		sum = 0;
		for (int i = idx; i != (idx + a - 1) % a; i = (i + 1) % a) {
			sum += ap[i];
			a_case.push_back(sum);
		}
		if (idx == 0) {
			if (a == 1) a_case.push_back(ap[0]);
			else a_case.push_back(sum + ap[a - 1]);
		}
	}
	
	b_case.push_back(0);
	for (idx = 0; idx != b; idx++) {
		sum = bp[idx];
		b_case.push_back(sum);
		for (int i = (idx + 1) % b; i != (idx + b - 1) % b; i = (i + 1) % b) {
			sum += bp[i];
			b_case.push_back(sum);
		}
		if (idx == 0) {
			if (b == 1) b_case.push_back(bp[0]);
			else b_case.push_back(sum + bp[b-1]);
		}
	}
	
	sort(a_case.begin(), a_case.end());
	sort(b_case.begin(), b_case.end());
	
	idx = 0;
	b_idx = b_case.size() - 1;
	while (idx < a_case.size() && b_idx >= 0) {
		if (a_case[idx] > s) break;
		
		sum = a_case[idx] + b_case[b_idx];
		if (sum > s) b_idx--;
		else if (sum < s) idx++;
		else {
			int a_num, b_num;
			for (a_num = idx; a_num < a_case.size() - 1; a_num++) if (a_case[a_num] != a_case[a_num + 1]) break;
			for (b_num = b_idx; b_num > 0; b_num--) if (b_case[b_num] != b_case[b_num - 1]) break;
			ret += (a_num - idx + 1) * (b_idx - b_num + 1);
			idx = a_num + 1;
			b_idx = b_num - 1;
		}
	}
	
	cout << ret << '\n';
	
	return 0;
}	
