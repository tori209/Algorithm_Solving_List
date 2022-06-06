#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	char word[16];
	int ret = 0;
	int num[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
	
	
	cin >> word;
	for (int i = 0; word[i] != '\0'; i++) ret += num[word[i] - 'A'];
	cout << ret << '\n';
	
	return 0;
}
