/*
	1168��
	����: �似Ǫ�� ����2 (1�� ��Ÿ�� 2��������, 2�� ��Ÿ�� 0.15�� �ָԱ��������� ���� ��Ǭ��.) 
	�Է�: ���� ���� k, n (1 <= k <= n <= 5,000)
	���: �־��� ���� ������ �似Ǫ�� ����
	
	�� �似Ǫ�� ����
	n���� ����� ���� �̷�� �ɾ��ְ�, 1������ n������ ������ ��,
	k���� �����ϰ�, k+1���� �������� k��°�� �ִ� �ο��� �ٽ� �����Ѵ�.
	�̸� �ݺ��Ͽ� ��� �ο��� ������ ��, ���ŵ� ������� ��ȣ�� ������ ����  �似Ǫ�� �����̶�� �Ѵ�.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class ST_Node {
	private:
		bool bLeaf;	// true�� value�� ��������, false�� �������� ��. 
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
