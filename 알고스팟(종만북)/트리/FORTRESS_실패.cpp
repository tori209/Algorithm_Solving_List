#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Circle {
	int x, y;
	int radius;
	
	Circle() {  x = 0; y = 0; radius = 0;  }
	Circle(int _x, int _y, int _r) {  x = _x; y = _y; radius = _r;  }
	
	bool isContain(Circle& tar) {
		int _x = (x - tar.x);
		int _y = (y - tar.y);
		return (radius > tar.radius) && (_x * _x + _y * _y < radius * radius);
	}
	bool isContain(Circle* tar) {
		int _x = (x - tar->x);
		int _y = (y - tar->y);
		return (radius > tar->radius) && (_x * _x + _y * _y < radius * radius);
	}
};

struct CastleNode {
	Circle* Node;
	list<CastleNode*> child;
	
	CastleNode (Circle* node) {  Node = node;  }
	~CastleNode() {
		for (CastleNode* c: child) 
			delete c;
		delete Node;
	}
	
	void findParent(CastleNode* parent_cand) {
		bool nextNotExist = true;
		list<CastleNode*>& parent_child = parent_cand->child;
		
		for (list<CastleNode*>::iterator it = parent_child.begin(); it != parent_child.end();) {
			if (nextNotExist && (*it)->Node->isContain(this->Node)) {
				nextNotExist = false;
				findParent(*it);
				it++;
			}
			else if (this->Node->isContain((*it)->Node)) {
				child.push_back(*it);
				it = parent_child.erase(it);
			} else it++;
		}
		
		if (nextNotExist) 
			parent_cand->child.push_back(this);
		return;
	} 
	
	void showChild() {
		cout << "Parent: " << Node->x << ' ' << Node->y << ' ' << Node->radius << '\n';
		if (child.empty()) {
			cout << "Child: Nothing\n";
			return;
		}
		
		for (CastleNode* cn : child) 
			cout << "Child: " << cn->Node->x << ' ' << cn->Node->y << ' ' << cn->Node->radius << '\n';
		for (CastleNode* cn : child) 
			cn->showChild();
	}
	
	int getDepth() {
		if (child.empty())
			return 0;
		
		int ret = 0;
		for (CastleNode* ch : child) 
			ret = max(ret, ch->getDepth() + 1);
		return ret;
	}
};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n;
	cin >> c;
	while (c--) {
		cin >> n;
		vector<Circle*> castle(n);
		for (int i = 0; i < n; i++) {
			castle[i] = new Circle();
			cin >> castle[i]->x >> castle[i]->y >> castle[i]->radius;
		}
		
		// 특수 케이스 처리 
		if (n == 1) {
			cout << 0 << '\n';
			for (int i = 0; i < n; i++) delete castle[i];
			continue;
		}
		if (n == 2) {
			cout << 1 << '\n';
			for (int i = 0; i < n; i++) delete castle[i];
			continue;
		}
		
		vector<int> len;
		CastleNode* root = new CastleNode(castle[0]);
		CastleNode* cur;
		
		for (int i = 1; i < n; i++) {
			cur = new CastleNode(castle[i]);
			cur->findParent(root);
		}
		
		for (CastleNode* c : root->child)
			len.push_back(c->getDepth() + 1);
		
		sort(len.begin(), len.end(), [](int i1, int i2)->bool{  return (i1 >= i2);  });
		int ret = len[0];
		if (len.size() > 1)
			ret += len[1];
		cout << ret << '\n';
		
		delete root;
	}
	
	return 0;
}
