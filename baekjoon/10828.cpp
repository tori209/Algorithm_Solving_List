/*
	10828번
	문제: 스택 
	입력: 스택 명령 개수 n 및 n개의 명령 
	출력: 명령 처리 결과.
	
	※ 정식 풀이는 스택을 '구현' 하는 것이므로 실제로 구현할 것. 
	※ 명령 레퍼런스
	push X: 정수 X를 스택에 넣는다.
	pop: top 부분을 제거하고, 이를 출력한다. 이때, empty일 경우 -1을 출력
	size: 스택에 들어있는 정수의 개수
	empty: 비어있을 경우 1, 아닐 경우 0 출력
	top: 스택의 가장 윗부분을 출력. empty일 경우 -1 출력 
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
