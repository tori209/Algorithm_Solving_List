/*
	2609번
	문제: 최대공약수와 최소공배수
	입력: 자연수 a, b (10,000이하)
	출력: a,b의 최대공약수, 다음 줄에 최소공배수
	
	※ 유클리드 호제법
	  두 자연수의 최대공약수를 구하는 알고리즘.
	  자연수 a, b (a>=b)에 대하여
	  a를 b로 나눈 나머지가 v1이라면,
	  b를 v1으로 나눈 나머지를 다시 구하여 v2를 구하고,
	  v1을 v2로 나눈 나머지를 구하여 v3을 구하고,
	  이를 반복하여 v3, v4, ... , vn을 구한다.
	  이때, vn = 0이라면, v n-1은 최대공약수가 된다.
	  이 절차들은 반복되는 연산에서 나오는 나머지들을 나눠 떨어지게 하는 수를 찾는 과정이다.
	   
	  v n-2 = v n-1 * x + vn이고, v n-3 = v n-2 * y + v n-1이므로, v n-1은 v n-3을 나눌 수 있다.
	  v n-4 = v n-3 * z + v n-2이고, v n-3과 v n-2는 v n-1로 나눌 수 있으므로, v n-4도 v n-1로 나눌 수 있다.
	  수학적 귀납법에 의하여, a, b까지 나눌 수 있는 것이다. 
*/

#include <iostream>

using namespace std;

int euclidean_algorithm(int val1, int val2) {
	if (val1 % val2 == 0) return val2;
	return euclidean_algorithm(val2, val1 % val2);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int a, b;
	int gcd, lcm;
	cin >> a >> b;
	gcd = (a > b ? euclidean_algorithm(a, b) : euclidean_algorithm(b, a));
	lcm = (a / gcd) * b;
	cout << gcd << '\n' << lcm << '\n';
	
	return 0;
}
