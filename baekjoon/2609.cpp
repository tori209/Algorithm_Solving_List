/*
	2609��
	����: �ִ������� �ּҰ����
	�Է�: �ڿ��� a, b (10,000����)
	���: a,b�� �ִ�����, ���� �ٿ� �ּҰ����
	
	�� ��Ŭ���� ȣ����
	  �� �ڿ����� �ִ������� ���ϴ� �˰���.
	  �ڿ��� a, b (a>=b)�� ���Ͽ�
	  a�� b�� ���� �������� v1�̶��,
	  b�� v1���� ���� �������� �ٽ� ���Ͽ� v2�� ���ϰ�,
	  v1�� v2�� ���� �������� ���Ͽ� v3�� ���ϰ�,
	  �̸� �ݺ��Ͽ� v3, v4, ... , vn�� ���Ѵ�.
	  �̶�, vn = 0�̶��, v n-1�� �ִ������� �ȴ�.
	  �� �������� �ݺ��Ǵ� ���꿡�� ������ ���������� ���� �������� �ϴ� ���� ã�� �����̴�.
	   
	  v n-2 = v n-1 * x + vn�̰�, v n-3 = v n-2 * y + v n-1�̹Ƿ�, v n-1�� v n-3�� ���� �� �ִ�.
	  v n-4 = v n-3 * z + v n-2�̰�, v n-3�� v n-2�� v n-1�� ���� �� �����Ƿ�, v n-4�� v n-1�� ���� �� �ִ�.
	  ������ �ͳ����� ���Ͽ�, a, b���� ���� �� �ִ� ���̴�. 
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
