#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Queue {
	#define MAX_QUEUE 10000
	private:
		T * items;
		unsigned int item_num;
		unsigned int idx_front;
		unsigned int idx_back;
	public:
		Queue() {
			item_num = 0;
			idx_front = 0;
			idx_back = 0;
			items = new T[MAX_QUEUE];
		}
		
		bool push(T x) {
			if(item_num == MAX_QUEUE) return false;
			items[idx_back] = x;
			idx_back = (idx_back + 1) % MAX_QUEUE;
			item_num++;
			return true;
		}
		
		T pop() {
			if (item_num == 0) return -1;
			T ret = items[idx_front];
			idx_front = (idx_front + 1) % MAX_QUEUE;
			item_num--;
			return ret;
		}
		
		int size() {
			return item_num;
		}
		
		bool empty() {
			return (idx_front == idx_back);
		}
		
		T front() {
			return (item_num == 0 ? -1 : items[idx_front]);
		}
		
		T back() {
			return (item_num == 0 ? -1 : items[idx_back-1]);
		}
		
		~Queue() {
			delete[] items;
		}
};

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	Queue<int> q;
	int n;
	string str;
	
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push") {
			cin >> str;
			q.push(stoi(str));
		} else if (str == "pop") {
			cout << q.pop() << '\n';
		} else if (str == "size") {
			cout << q.size() << '\n';
		} else if (str == "empty") {
			cout << (q.empty() ? 1 : 0) << '\n'; 
		} else if (str == "front") {
			cout << q.front() << '\n';
		} else if (str == "back") {
			cout << q.back() << '\n';
		} else continue;
	}
	
	return 0;
}
