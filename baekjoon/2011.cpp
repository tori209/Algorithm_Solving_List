/*
	2011번
	문제: 암호코드
	입력: 5000자리 이하 정수 1개.
	출력: A=1, B=2, ... Z=26이라 할 때, 가능한 해석의 경우의 수 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int cnt[5001] = {0,};
	int digit1, digit2;
	
	string crypto;
	cin >> crypto;
	if (crypto[0] == '0') {
		cout << 0 << '\n';
		return 0;
	}
	
	cnt[0] = 1;
	if (crypto.size() > 1) cnt[1] = (stoi(crypto.substr(1,1)) != 0 ? 1 : 0) + (stoi(crypto.substr(0, 2)) <= 26 ? 1 : 0);
	for (int i = 2; i < crypto.size(); i++) {
		/*****************
			해석 시 문제가 되는 경우
			1. 0번지에 0 저장	(초반부에 처리) 
			2. 0이 연달아 2번 나올 경우	(digit1 == digit2 == 0인 경우) 
			3. 0이 나왔을 때, 앞 글자와 합친 결과 10, 20이 아닌 경우. (0, 30, 40, ... 은 영어로 치환 불가) (digit1 == 0 && digit2 != 10 && digit2 != 20)
		******************/		
		digit1 = stoi(crypto.substr(i, 1));
		digit2 = stoi(crypto.substr(i-1, 2));
		if (digit1 != 0) cnt[i] += cnt[i-1];
		else if (digit2 == 0 || digit2 != 10 && digit2 != 20) {
			cnt[crypto.size() - 1] = 0;
			break;
		}
		
		if (digit2 >= 10 && digit2 <= 26) cnt[i] += cnt[i-2];
		cnt[i] %= 1000000;
	}
	
	cout << cnt[crypto.size() - 1] << '\n';
	
	return 0;
}
