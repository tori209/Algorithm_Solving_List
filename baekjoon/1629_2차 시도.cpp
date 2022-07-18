#include <iostream>

using namespace std;

long long sqrRemainder(long long a, long long c) {
	return ((a % c) * (a % c)) % c;
}

int mul(long long a, long long b, long long c) {
	if (b == 0) return 0;
	if (b == 1) return a;
	
	if (b % 2)
		return ((a % c) * (mul(sqrRemainder(a, c), b / 2, c) % c)) % c;
	else
		return mul(sqrRemainder(a, c), b / 2, c) % c;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if (a >= c)
		a %= c;
	cout << mul(a, b, c) << '\n';
	return 0;
}
