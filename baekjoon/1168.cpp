/*
	1168번
	문제: 요세푸스 문제2 (1은 런타임 2초이지만, 2는 런타임 0.15라서 주먹구구식으로 절대 못푼다.) 
	입력: 양의 정수 k, n (1 <= k <= n <= 5,000)
	출력: 주어진 수로 구성한 요세푸스 순열
	
	※ 요세푸스 순열
	n명의 사람이 원을 이루고 앉아있고, 1번부터 n번까지 존재할 때,
	k번을 제거하고, k+1번을 기준으로 k번째에 있는 인원을 다시 제거한다.
	이를 반복하여 모든 인원을 제거한 뒤, 제거된 순서대로 번호를 나열한 것을  요세푸스 순열이라고 한다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class ST_Node {
	private:
		bool bLeaf;	// true면 value에 개별값이, false면 구간값이 들어감. 
		int value;
		ST_Node* ptr_lnode;
		ST_Node* ptr_rnode;
	public:
		ST_Node(int value) {
			bLeaf = true;
			this->value = value;
			ptr_lnode = NULL;
			ptr_rnode = NULL;
		}
		
		ST_Node(int value, ST_Node* node) {
			bLeaf = false;
			this->value = value;
			ptr_lnode = node;
			ptr_rnode = NULL; 
		}
		
		ST_Node(int value, ST_Node* node1, ST_Node* node2) {
			bLeaf = false;
			this->value = value;
			ptr_lnode = node1;
			ptr_rnode = node2; 
		}
		
		bool isLeaf() {   return bLeaf;   }
		int getValue() {   return value;   }
		ST_Node* getLNodePtr() {   return ptr_lnode;   }
		ST_Node* getRNodePtr() {   return ptr_rnode;   }
		void setLNodePtr(ST_Node* node) {   ptr_lnode = node;   }
		void setRNodePtr(ST_Node* node) {   ptr_rnode = node;   }
		
		~ST_Node() {}
};

class Segment_Tree {
	private:
		ST_Node* root;
		ST_Node* Create_Tree(vector<int> vals) {
			if (vals.size() == 1) return new ST_Node(vals[0]);
			else if (vals.size() == 0) return NULL;
			ST_Node lnode = Create_Tree(new vector<int>(vals.begin(), vals.begin() + vals.size() / 2));
			ST_Node rnode = Create_Tree(new vector<int>(vals.begin() + vals.size() / 2, vals.end()));
			return new ST_Node(vals.size(), lnode, rnode);
		}
	public:
		Segment_Tree(vector<int> vals) {
			root = Create_Tree(vals);
		}
		
		bool remove(int k) {
			
		}
		
		vector<int> getVec(int k) {
			vector<int> ret;
			
		}
		
		~Segment_Tree() {
			ST_Node* cur;
			queue<ST_Node*> q;
			vec.push_back(root);
			while(!q.empty()) {
				cur = q.front();
				q.pop();
				if (cur->getLNodePtr() != NULL) q.push(cur->getLNodePtr());
				if (cur->getRNodePtr() != NULL) q.push(cur->getRNodePtr());
				delete cur;
			}
		}
};

int main() {
	
	return 0;
}
