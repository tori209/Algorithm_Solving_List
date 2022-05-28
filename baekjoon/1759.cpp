#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int l, c;
	bool isVowel[26] = {0,};
	char charset[15];
	stack<int> str;
	isVowel[0] = isVowel['e'-'a'] = isVowel['i'-'a'] = isVowel['o'-'a'] = isVowel['u'-'a'] = 1;
	
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> charset[i];
	sort(charset, charset + c); 
	
	//str에 charset의 index가 들어간다.
	str.push(0);
	while (!str.empty()) {
		if (str.size() < l) {
			if (str.top() + 1 < c) str.push(str.top() + 1);
			else {
				str.pop();
				if (str.empty()) break;
				
				int temp = str.top();
				str.pop();
				str.push(temp + 1);
			}
		} else {
			int vowelNum = 0;
			stack<int> tstr;
			while (!str.empty()) {
				tstr.push(str.top());
				str.pop();
				vowelNum += isVowel[charset[tstr.top()] - 'a'];
			}
			
			while (!tstr.empty()) {
				if (vowelNum > 0 && vowelNum < l - 1) cout << charset[tstr.top()];
				str.push(tstr.top());
				tstr.pop();
			}
			if (vowelNum > 0 && vowelNum < l - 1) cout << '\n';
			
			int temp = str.top();
			str.pop();
			if (temp + 1 >= c)  {
				temp = str.top();
				str.pop();
			}
			str.push(temp + 1);
		}
	}
	
	return 0;
}
