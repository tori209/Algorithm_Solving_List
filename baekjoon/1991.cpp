/*
	1991��
	����: Ʈ�� ��ȸ
	�Է�: ����Ʈ���� ��� �� n(1�̻� 26����), n���� (���, ���� �ڽ� ���, ������ �ڽ� ���) ����.
	���: preorder, inorder, postorder ������ ��ȸ�� ����� ���.
		(root�� �׻� A�̴�.)
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
