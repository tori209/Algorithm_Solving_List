/****************************
	11726번
	문제: 2xn 타일링  
	입력: 직사각형의 가로 길이 n 
	출력: 2xn을 1x2, 2x1로 채우는 방법의 수  
****************************/

#include <iostream>
#include <climits>	// 각 자료형의 최대값을 정의. 

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	int numOfWays[1001];
	numOfWays[1] = 1;
	numOfWays[2] = 2;
	cin >> n;
	for (int i = 3; i < n + 1; i++) {
		numOfWays[i] = (numOfWays[i-1] + numOfWays[i - 2]) % 10007;
	}
	cout << numOfWays[n] << '\n';
	return 0;
}
