/********************
	9461번 
	문제: 파도반 수열 
	입력: 테스트 케이스 개수 T와 T개의 자연수 (100 이하 자연수) 
	출력: 파도반 수열 P(n)의 값 T개 
********************/	

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0); 
	ios::sync_with_stdio(0);
	
	int t, n;
	long long padovan[101] = {0, 1, 1, 1, 2, 2,};
	
	cin >> t;
	for (int i = 6; i <= 100; i++) {
		padovan[i] = padovan[i-5] + padovan[i-1];
	}
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << padovan[n] << '\n';
	}
	
	return 0;	
}
