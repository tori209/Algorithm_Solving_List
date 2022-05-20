/*
	10866�� 
	����: ��
	�Է�: �� ��� �� n���� n���� ���
	���: ��� ó�� ���
	
	�� ��� ���۷���
	push_front x: x�� �� �տ� �ִ´� 
	push_back x: x�� �� �ڿ� �ִ´�  
	pop_front: �� �պκ��� ���� ����, �̸� ��� 
	pop_back: �� �޺κ��� ���� ����, �̸� ��� 
	size: ���� ũ�⸦ ��� 
	empty: ũ�Ⱑ 0���� Ȯ�� 
	front: �� �պκ��� ��� 
	back: �� �޺κ��� ��� 
*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Dequeue {
	private:
		int idx_front;
		int idx_back;
		size_t item_num;
		T * items;
	public:
		Dequeue() {
			items = new T[10000];
			idx_front = 0;
			idx_back = 0;
			item_num = 0;
		}
		bool push_front(T x) {
			if (item_num == 10000) return false;
			idx_front = (idx_front - 1 + 10000) % 10000;
			items[idx_front] = x;
			item_num++;
			return true;
		}
		bool push_back(T x) {
			if (item_num == 10000) return false;
			items[idx_back] = x;
			idx_back = (idx_back + 1) % 10000;
			item_num++;
			return true;
		}
		T pop_front() {
			if (item_num == 0) return -1;
			T ret = items[idx_front];
			idx_front = (idx_front + 1) % 10000;
			item_num--;
			return ret;
		}
		T pop_back() {
			if (item_num == 0) return -1;
			idx_back = (idx_back - 1 + 10000) % 10000;
			T ret = items[idx_back];
			item_num--;
			return ret;
		}
		size_t size() {   return item_num;   }
		bool empty() {   return (item_num == 0);   }
		T front() {   return (item_num == 0 ? -1 : items[idx_front]);   }
		T back() {   return (item_num == 0 ? -1 : items[(idx_back + 9999) % 10000]);   }
		~Dequeue() {
			delete[] items;
		}
		
		void test () {
			cout << "front idx: " << idx_front << " / back idx: " << idx_back << "\n\n";
		}
};

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	string str;
	Dequeue<int> dq;
	
	cin >> n;
	while (n--) {
		cin >> str;
		//cout << "Currend Cmd: " << str << '\n';
		if (str == "push_front") {
			cin >> str;
			dq.push_front(stoi(str));
		} else if (str == "push_back") {
			cin >> str;
			dq.push_back(stoi(str));
		} else if (str == "pop_front") {
			cout << dq.pop_front() << '\n';
		} else if (str == "pop_back") {
			cout << dq.pop_back() << '\n';
		} else if (str == "size") {
			cout << dq.size() << '\n';
		} else if (str == "empty") {
			cout << (dq.empty() ? 1 : 0) << '\n';
		} else if (str == "front") {
			cout << dq.front() << '\n';
		} else if (str == "back") {
			cout << dq.back() << '\n';
		} else continue;
		//dq.test();
	}
	
	return 0;
} 
