/*
	11656번
	문제: 접미사 배열
	입력: 영어 소문자로 이루어진 문자열 s
	출력: 접미사를 사전정렬하여 출력 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string str;
	vector<string> vec;
	cin >> str;
	for(;str.size() != 0; str.erase(str.begin())) {
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end());
	
	for(string s : vec) cout << s << '\n';
		
	return 0;
}
