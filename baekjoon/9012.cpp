/*
	9012번
	문제: 괄호 
	입력: 문자열 개수 n과 소괄호로 구성된 문자열 n개 
	출력: 각 문자열의 VPS 여부를 YES or NO로 출력.
	
	※ VPS
	괄호가 온전히 열리고 닫힌 문자열.
	가령, ()을 기본 VPS라고 부르며,
	VPS인 X에 대해 새로운 문자열 (X) 또한 VPS라고 할 수 있다. 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, cnt;
	string vps;
	
	cin >> n;
	while (n-- > 0) {
		cnt = 0;
		cin >> vps;
		for (char c : vps) {
			if (c == '(') cnt++;
			else cnt--;
			
			if (cnt < 0) break;
		}
		cout << (cnt == 0 ? "YES\n" : "NO\n");
	}
	
	return 0;
}
