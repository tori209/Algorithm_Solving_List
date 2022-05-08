/*
	2011��
	����: ��ȣ�ڵ�
	�Է�: 5000�ڸ� ���� ���� 1��.
	���: A=1, B=2, ... Z=26�̶� �� ��, ������ �ؼ��� ����� �� 
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
			�ؼ� �� ������ �Ǵ� ���
			1. 0������ 0 ����	(�ʹݺο� ó��) 
			2. 0�� ���޾� 2�� ���� ���	(digit1 == digit2 == 0�� ���) 
			3. 0�� ������ ��, �� ���ڿ� ��ģ ��� 10, 20�� �ƴ� ���. (0, 30, 40, ... �� ����� ġȯ �Ұ�) (digit1 == 0 && digit2 != 10 && digit2 != 20)
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
