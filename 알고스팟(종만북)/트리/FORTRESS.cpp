/*
	실패 원인:
	leaf와 leaf의 최장거리는 항상 root를 지날 것이라는 잘못된 결론을 내었음.
	그 결과 return값을 다르게 얻는 케이스가 발생함. 
	 /\
	/\		--> 이 케이스의 경우 root를 거치는 최장거리는 4, 거치지 않는 경우는 6이 됨. (예외 케이스) 
   /\/\
  /\  /\
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
	vector<int> child;
};

int n, longest;
vector<int> x(100), y(100), r(100);
vector<TreeNode> tree(100);

int sqr(int val) {  return val * val;  }

int getSqrLength(int a, int b) {
	int _x = sqr(x[a] - x[b]);
	int _y = sqr(y[a] - y[b]);
	return _x + _y;
} 

bool isEnclose(int p, int c) {
	return (r[p] > r[c] && getSqrLength(p, c) < sqr(r[p] - r[c]));
}

bool isChild(int p, int c) {
	if (!isEnclose(p, c)) return false;
	for (int i = 0; i < n; i++) {
		if (i == p || i == c) continue;
		if (isEnclose(p, i) && isEnclose(i, c)) return false;
	}
	return true;
}

void createTree() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (isChild(i, j)) 
				tree[i].child.push_back(j);
		}
	}
	return;
}

void showTree() {
	int cnt = 0;
	queue<int> cur;
	cur.push(0);
	while (!cur.empty()) {
		queue<int> next;
		cout << "Depth: " << cnt << ", Node: ";
		while (!cur.empty()) {
			cout << cur.front() << ' ';
			for (int ch : tree[cur.front()].child)
				next.push(ch);
			cur.pop();
		}
		cout << '\n';
		cur = next;
		cnt++;
	}
}

int getDepth(int node) {
	if (tree[node].child.empty())
		return 0;
		
	vector<int> depth(tree[node].child.size());
	for (int i = 0; i < tree[node].child.size(); i++)
		depth[i] = getDepth(tree[node].child[i]);
	sort(depth.begin(), depth.end());
	if (depth.size() >= 2)
		longest = max(longest, 2 + depth[depth.size() - 1] + depth[depth.size() - 2]);
	return depth[depth.size() - 1] + 1;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0; i < n; i++) 
			tree[i].child.clear();
		
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i] >> r[i];
		
		TreeNode& root = tree[0];
		createTree();
		
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		}
		vector<int> len;
		
		longest = 0;
		int ret = getDepth(0);
		cout << max(ret, longest) << '\n';
	}
	
	return 0;
}
