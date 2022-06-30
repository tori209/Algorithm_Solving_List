/*
	6549��
	����: ������׷����� ���� ū ���簢�� 
	�Է�: �ʺ� 1�� ���簢���� ���� n (1 �̻� 100,000 ����)
		�� 0�� �ԷµǸ� �����Ѵ�. 
		���� n���� ���簢������ ���� hi (0 �̻� 1,000,000,000 ����)
	���: ���簢������ ������� �ٿ� ������ ���� ��, �ش� ������ ������ �� �ִ� ���簢���� �ִ� ũ��
	
	�� �ع��� �������� ������ ���� �����Ͽ���. 
	�ٽ�: i��° ���簢���� ���̺��� ���� ���簢���� �� ���簢���� ���� ����� ����/���� �ε����� ���Ѵ�. (���� left[i], right[i]) 
	
	���� i��° ���簢���� left[i]�� right[i]�� �˰� �ִٸ�,
	�ش� ���簢���� ���̷� ���� ���簢���� �ִ� ũ���, (right[i] - left[i] - 1) * height[i]�� �ȴ�.
	
	����, �� ���簢���� ���� left�� right�� ������ ���Ѵٸ�, ��/��� ���� Ž���� �ϰ� �ǹǷ� O(n^2)�� �ȴ�.
	����, �ٸ� �ع��� ã�ƾ߸� �Ѵ�.
	
	����, �ϴ��� ����� ���� �������� �Ѵٸ� left�� right�� ���� �� �ִ�.
	�켱, stack�� �뵵�� '���� right�� �� �� ���� ���簢������ ����'���� ������.
	right�� �� �� ���ٴ� ���� '���±��� �� ���簢���鿡 ���Ͽ�����(��, 0~i��°) �ڱ� �ڽź��� ���̰� ���� ���簢���� ����.'��� ���̴�.
	��, stack�� �ٴڿ� �������� ���簢���� ���̴� �۴ٴ� ���̸�, ���� stack ���ο��� ���簢���� ���̰� ������������ �����Ǿ��ִٰ� �� �� �ִ�.
	�̴� ��, �ּ��� stack ���� �ִ� �͵��� left�� �˰� �ִٴ� ������ �ؼ��� �� ������, left�� stack �󿡼� �ڱ� �ڽ� �ٷ� �ڿ� �ִ� ���簢���̶�� ������ �� �ִ�. 
	�׷��⿡ stack �󿡼��� ���̰� ������ ���簢���� �����ϸ� �ȵǸ�, ���� ���̰� ������ ���簢���� stack�� ������ �� ������ �ؾ��Ѵ�.
	
	���� ���̵� ����, ������ ���� ��Ģ�� ���� �� �ִ�.
		���� i��° ���簢���� ���̸� ���� �ִٰ� �� ��,
		stack.top(= top)�� ���Ͽ� 
		1) height[top] > height[i]
			top��° ���ڿ� ����, i��° ���簢���� right�� ������ �ϰ� �Ǹ�,
			top �ٷ� �ڿ� ��ġ�ϴ� ���簢��(= prev(top))�� left�� ������ �Ѵ�. 
			��, top��° ���ڸ� �����ϴ� ���簢���� ũ���� �ִ��� height[top] * (i - prev(top) - 1) �� �ȴ�.
			�� stack�� top�� ���� ���, prev(top) - 1 ��� 0���� ó���Ѵ�. 
			top��° ������ left, right�� ��� �˰� �Ǿ����Ƿ�, top�� stack���� �����Ѵ�.
			
			ó�� ����, i��° ���簢���� prev(top)�� right�� �� ���� �����Ƿ�, �б⸦ �ٽ� �õ��Ѵ�. 
		2) height[top] < height[i] 
			i��° ���ڰ� top��° ������ right�� �� �� �����Ƿ�, �ϴ� �Ѿ��.
			�̶�, top��° ���ڴ� i��° ������ left�� �Ǳ� ������ i�� stack�� push�Ѵ�.
		3) height[top] == height[i]
			stack�� ���� �� i�� �����ų�, top�� pop�� �� i�� �־�� �Ѵ�.
			������, ���� i�� �ְ� �ȴٸ� ���� �߰��Ǵ� ���簢������ left�� i��° ���ڰ� �ȴٴ� ���ε�,
			���� top�� �����ϰ�, i�� ������ �ȴٸ�,
			���� stack�� �ٸ� ���� j�� ���� ��, j�� left�� top�̶�� ���� �ȴ�.
			������ ���������� j�� left�� i�� �Ǿ���ϱ⿡, �׸��� ���� ��µȴ�.
			
			����, top�� ������ i�� �߰��Ͽ��� �Ѵ�.
			
	���� ó���� �������� ��, stack�� �ݵ�� 1�� �̻��� ���� ���� �ȴ�.
	�������� stack�� ���� ���簢������ right�� ���ٴ� ���̱⿡,
	�̵��� �����ϴ� ���簢���� �ִ� ũ��� (n - prev(top) - 1) * height[top]�� �ȴ�.
	�� stack�� top�� ���� ���, prev(top) - 1 ��� 0�� �ִ´�.  
*/
// ���̵��� ������ 19�忡�� �˰� �Ǿ���. 

#include <iostream>
#include <stack>

using namespace std;

long long height[100000];

long long solve(int n) {
	long long ret = 0LL;
	stack<int> remain_idx;
	
	for (int i = 0; i < n; i++) 
		cin >> height[i];
	
	remain_idx.push(0);
	for (int i = 1; i < n; i++) {
		while (height[remain_idx.top()] >= height[i]) {
			int tar = remain_idx.top();
			remain_idx.pop();
			
			if (remain_idx.empty()) {
				ret = max(ret, height[tar] * i);
				break;
			}
			else
				ret = max(ret, height[tar] * (i - remain_idx.top() - 1));
		}
		remain_idx.push(i);
	}
	
	while (!remain_idx.empty()) {
		int tar = remain_idx.top();
		remain_idx.pop();
		if (remain_idx.empty())
			ret = max(ret, n * height[tar]);
		else
			ret = max(ret, (n - remain_idx.top() - 1) * height[tar]);
	}
	
	return ret;
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << solve(n) << '\n';
	}
	
	return 0;
}
