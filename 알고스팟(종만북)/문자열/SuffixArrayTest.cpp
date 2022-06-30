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

int main() {
	string s;
	cin >> s;
	
	vector<int> suffix_array = initSuffixArray(s);
	for (int idx : suffix_array)
		cout << s.substr(idx) << '\n';
		
	return 0;
}
