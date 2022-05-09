/*
	10828��
	����: ���� 
	�Է�: ���� ��� ���� n �� n���� ��� 
	���: ��� ó�� ���.
	
	�� ���� Ǯ�̴� ������ '����' �ϴ� ���̹Ƿ� ������ ������ ��. 
	�� ��� ���۷���
	push X: ���� X�� ���ÿ� �ִ´�.
	pop: top �κ��� �����ϰ�, �̸� ����Ѵ�. �̶�, empty�� ��� -1�� ���
	size: ���ÿ� ����ִ� ������ ����
	empty: ������� ��� 1, �ƴ� ��� 0 ���
	top: ������ ���� ���κ��� ���. empty�� ��� -1 ��� 
*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class stack {
	private:
		int top_pos;
		T * items;
		int stk_size;
		
	public:
		stack() {
			top_pos = -1;
			stk_size = 10000;
			items = new T[10000];
		}
		
		bool empty() {   return (top_pos == -1);   }
		bool push(T item) {
			if (top_pos + 1 == stk_size) return false;
			items[++top_pos] = item;
			return true;
		}
		T pop() {
			if (top_pos == -1) return -1;
			return items[top_pos--];
		}
		T top() {
			if (top_pos == -1) return -1;
			return items[top_pos];
		}
		int size() {
			return top_pos + 1;
		}
		~stack() {
			delete items;
		}
}; 

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	string cmd;
	stack<int> s;
	cin >> n;
	while (n-- > 0) {
		cin >> cmd;
		if(cmd == "push") {
			cin >> cmd;
			s.push(stoi(cmd));
		} else if (cmd == "pop") {
			cout << s.pop() << '\n';
		} else if (cmd == "empty") {
			cout << (s.empty() ? 1 : 0) << '\n';
		} else if (cmd == "top") {
			cout << s.top() << '\n';
		} else if (cmd == "size") {
			cout << s.size() << '\n';
		}
	}
	
	return 0;
}
