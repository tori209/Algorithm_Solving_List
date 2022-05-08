#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	vector<int> vec;
	int n, srch;
	
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	
	cin >> n;
	while(n-- > 0) {
		cin >> srch;
		if(binary_search(vec.begin(), vec.end(), srch)) cout << '1' << '\n';
		else cout << '0' << '\n';
	}
	
	return 0;
}
