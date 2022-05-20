/*
	1991번
	문제: 트리 순회
	입력: 이진트리의 노드 수 n(1이상 26이하), n개의 (노드, 왼쪽 자식 노드, 오른쪽 자식 노드) 구성.
	출력: preorder, inorder, postorder 순으로 순회한 결과를 출력.
		(root는 항상 A이다.)
*/

#include <iostream>
#include <utility>
#include <map>
#include <string>

using namespace std;

map<char, pair<char, char>> tree;

string visit(char node, int mode) {
	// mode:1 = pre / 2 = in / 3 = post
	if (node == '.') return "";
	
	if (mode == 1) return node + visit(tree[node].first, mode) + visit(tree[node].second, mode);
	if (mode == 2) return visit(tree[node].first, mode) + node + visit(tree[node].second, mode);
	if (mode == 3) return visit(tree[node].first, mode) + visit(tree[node].second, mode) + node;
	return "error";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	char c, l, r;
	int n;
	
	cin >> n;
	while(n--) {
		cin >> c >> l >> r;
		tree[c] = make_pair(l, r);
	}
	
	cout << visit('A', 1) << '\n';
	cout << visit('A', 2) << '\n';
	cout << visit('A', 3) << '\n';
	
	return 0;
} 
