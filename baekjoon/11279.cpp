/*
	11279��
	����: �ִ� ��
	�Է�: ���� ���� n (1 �̻� 100,000 ����)�� n���� ���� x
		(x > 0�̸� �ش� ���� ����, x == 0�̸� �ִ� ��ȯ)
	���: 0�� �Էµ� ��ŭ ��� ����. 
	
	�⺻ ����: ���� ���� Ʈ��
	���� ����:
		���� ���� Ʈ���� ���� ���� leaf ��ġ�� ���ο� ���� �߰��Ѵ�.
		�ش� ���� parent�� ���Ͽ��� ��, leaf�� ũ�ٸ� �� ���� switching �Ѵ�.
		���� �׷��� �ƴ��ϸ� break�Ѵ�.
		�̸� parent�� ���� ��õ��Ѵ�. 
		�̸� root�� ������ ������, Ȥ�� ����� ������ �ݺ��Ѵ�. (O(logN))
	���� ����:
		root�� ���� ����� ��, ���� �ֱٿ� �߰��� leaf�� ���� root�� ������.
		���� root�� ��/�� child�� ���Ͽ��� �� �� �� �� �ϳ��� root���� ũ�� �� ���� swap�Ѵ�.
		�ƴ� ��� break�Ѵ�.
		swap�� �Ͼ ���, swap�� child�� ���� ���� ������ �ٽ� �����Ѵ�.
		leaf�� �����ϰų� ������ ����� ������ ���� ������ �ݺ��Ѵ�. (O(logN)) 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned int val[100001];
	int n, x, valnum = 0;
	
	cin >> n;
	while (n--) {
		cin >> x;
		
		if (x == 0) { // �ִ� ��� 
			if (valnum == 0) cout << 0 << '\n';
			else {
				cout << val[1] << '\n';
				val[1] = val[valnum--];
				
				int left, right, temp;
				for (int idx = 1;;) {
					left = 2*idx;
					right = 2*idx + 1;
					
					if (left > valnum && right > valnum) break;	// leaf ����
					if (val[idx] >= val[left] && val[idx] >= val[right]) break; // ���̻� ���ư� ������ ����. 
					
					if (val[left] >= val[right]) {
						temp = val[idx];
						val[idx] = val[left];
						val[left] = temp;
						idx *= 2;
					} else {
						temp = val[idx];
						val[idx] = val[right];
						val[right] = temp;
						idx = 2*idx + 1;
					}
				}
			}
		} else {
			val[++valnum] = x;
			for (int idx = valnum;;) {
				if (idx == 1) break;
				
				int temp;
				if (val[idx] > val[idx/2]) {
					temp = val[idx];
					val[idx] = val[idx/2];
					val[idx/2] = temp;
					idx /= 2;
				} else break;
			}
		}
	}
	
	return 0;
}
