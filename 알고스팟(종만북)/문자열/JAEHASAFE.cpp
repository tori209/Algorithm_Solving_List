// ó������ �ð����, ������ �ð�ݴ�, �� ������ �ð����, ... �� �ݺ���.
// ��, �� ���¿� �����ϸ� ���� ���¿� �����ϱ� ���� �ݴ�������� ���ư�. 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a���� b�� �˻��Ѵ�.
// ��ȯ���� ���̰� len�� a�� prefix = b�� suffix�� �����ϴ� len�� �ִ�.

vector<int> initPi(string& a) {
	int n = a.size();
	vector<int> pi(n, 0);
	
	int begin = 1, match = 0;
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
	
	return pi;
}

int finder(string a, string b) {
	int n = a.size();
	int m = b.size();
	vector<int> pi = initPi(b);
	
	int begin = 0, match = 0;
	while (begin <= n - m) {
		if (match < m && a[begin + match] == b[match]) {
			match++;
			if (match == m)
				return begin;
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
	return m;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n, ret;
	string state[101];
	
	cin >> c;
	while (c--) {
		cin >> n;
		ret = 0;
		for (int i = 0; i < n + 1; i++)
			cin >> state[i];
		for (int i = 0; i < n; i++) {
			if (i % 2) ret += finder(state[i] + state[i], state[i + 1]);
			else ret += finder(state[i + 1] + state[i + 1], state[i]);
		}
		cout << ret << '\n';
	}
	
	return 0;
}
