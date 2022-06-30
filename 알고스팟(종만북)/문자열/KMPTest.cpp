#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPi(const string& N) {
	int s = N.size();
	vector<int> pi(s, 0);
	int begin = 1, matched = 0;
	
	while (begin + matched < s) {
		if (N[begin+matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int main() {
	string H, N;
	
	cin >> H;
	cin >> N;
	
	vector<int> pi = getPi(N);
	vector<int> loc;
	
	int b = 0, m = 0;
	int s = H.size();
	int ss = N.size();
	
	while (b <= s - ss) {
		if (m < ss && H[b + m] == N[m]) {
			m++;
			if (m == ss) loc.push_back(b);
		} else {
			if (m == 0) b++;
			else {
				b += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}
	
	for (int idx : loc) cout << idx << ' ';
	cout << '\n';
	
	return 0;
}
