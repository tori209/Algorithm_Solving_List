/*
	11656��
	����: ���̻� �迭
	�Է�: ���� �ҹ��ڷ� �̷���� ���ڿ� s
	���: ���̻縦 ���������Ͽ� ��� 
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
