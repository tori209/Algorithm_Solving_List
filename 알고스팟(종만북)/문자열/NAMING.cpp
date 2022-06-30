#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string a, b;
	int n, begin, match;
	int pi[400001] = {0,};
	vector<int> ret;
	
	cin >> a >> b;
	a += b;
	n = a.size();
	
	begin = 1; match = 0;
	while (begin + match < n) {
		if (a[begin + match] == a[match]) {
			match++;
			pi[begin + match - 1] = match;
		}
		else {
			if (match == 0) {
				begin++;
				continue;
			}
			begin += match - pi[match - 1];
			match = pi[match - 1];
		}
	}
	
	for (int k = n; k > 0;) {
		ret.push_back(k);
		k = pi[k - 1];
	}
	for (vector<int>::reverse_iterator it = ret.rbegin(); it != ret.rend(); it++)
		cout << *it << ' ';
	
	return 0;
}
