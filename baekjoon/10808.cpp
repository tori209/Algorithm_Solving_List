/*
	10808번
	문제: 알파벳 개수
	입력: a-z로 구성된 단어 S
	출력: S에 포함된 a-z 각각의 개수
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string s;
	int cnt[26] = {0,};
	cin >> s;
	for(char c : s) cnt[c - 'a']++;
	for (int i : cnt) cout << i << ' ';
	cout << '\n';
	
	return 0;
}
