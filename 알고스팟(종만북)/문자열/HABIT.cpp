#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {}
	bool operator () (int a, int b) {
		if (group[a] != group[b])
			return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

vector<int> initSuffixArray(const string& s) {
	int n = s.size();
	int t = 1;
	
	vector<int> group(n + 1);
	for (int i = 0; i < n; ++i)
		group[i] = s[i];
	group[n] = -1;
	
	vector<int> ret(n);
	for (int i = 0; i < n; ++i)
		ret[i] = i;
	
	while (t < n) {
		Comparator compareUsing2T(group, t);
		sort(ret.begin(), ret.end(), compareUsing2T);
		
		t *= 2;
		if (t >= n)
			break;
			
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[ret[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (compareUsing2T(ret[i - 1], ret[i]))
				newGroup[ret[i]] = newGroup[ret[i - 1]] + 1;
			else
				newGroup[ret[i]] = newGroup[ret[i - 1]];
		}
		group = newGroup;
	}
	
	return ret;
}

int getLongestHabitCnt(string& s, int low_limit) {
	if (low_limit == 1) return s.size();
	
	int n = s.size();
	int ret = 0;
	vector<int> suffixArr = initSuffixArray(s);
	
	// 접미사 배열을 생성하면, 사전 순으로 접미사를 정렬해준다.
	// 계속 등장하는 말버릇은 각 접미사의 접두사로서 반복 등장할 것.
	// 즉, 사전 순으로 정렬된 접미사 배열 상에 연속된 순서로 말버릇을 볼 수 있을 것.
	// 따라서, 임의의 idx i와 최소한의 반복 횟수 k가 주어졌을 때, s[suffixArr[i]]와 s[suffixArr[i+k-1]]에 대해,
	// 두 문자열의 공통 접두사의 최장길이의 접두사를 찾으면, 해당 접두사가 i~i+k-1 사이의 문자열에도 접두사로서 존재함.  
	for (int i = 0; i + low_limit <= n; i++) {
		int idx1 = suffixArr[i], idx2 = suffixArr[i + low_limit - 1], cnt = 0;
		while (idx1 != n && idx2 != n && s[idx1] == s[idx2]) {
			idx1++; idx2++; cnt++;
		}
		if (ret < cnt)
			ret = cnt;
	}
	
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, lower_limit;
	string s;
	cin >> c;
	while (c--) {
		cin >> lower_limit;
		cin >> s;
		cout << getLongestHabitCnt(s, lower_limit) << '\n';
	}
		
	return 0;
}
