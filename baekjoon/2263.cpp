/*
	2263��
	����: Ʈ���� ��ȸ
	�Է�: ����Ʈ���� ���� �� n (1 �̻� 100,000 ����)�� inorder / postorder ��ȸ �� ��� ����
	���: preorder �� ��� ����
*/

#include <iostream>

using namespace std;

int tree[100001][2];
int in[100000];
int post[100000];

void findTree(int post_bidx, int post_eidx, int in_bidx, int in_eidx) {
	if (post_bidx >= post_eidx) return; 	// ����? 
	if (post_eidx - post_bidx == 1) {		// leaf ���� 
		tree[post[post_eidx - 1]][0] = tree[post[post_bidx]][1] = -1;
		return;
	} 
	
	// �ּ��� �ڽ� 1���� �ִ� ����. 
	int root = post[post_eidx - 1];		// subtree�� root 
	int left = -1, right = - 1;	// subtree root�� ��/�� �ڽ� 
	int in_ridx;	// inOrder �󿡼� subtree root�� idx 
	
	
	
	for (in_ridx = in_bidx; in_ridx < in_eidx; in_ridx++) {
		if (in[in_ridx] == root) break;
	}
	
	if (in_ridx == in_bidx) {
		// inOrder �������� root�� ù��°�� ���� --> ���� �ڽ��� ���ٴ� �� 
		right = post[post_eidx - 2];
		findTree(post_bidx, post_eidx - 1, in_bidx + 1, in_eidx);
	} else if (in_ridx == in_eidx - 1) {
		// inOrder �������� root�� �������� ���� --> ������ �ڽ��� ���ٴ� ��
		left = post[post_eidx - 2];
		findTree(post_bidx, post_eidx - 1, in_bidx, in_eidx - 1);
	} else {
		// inOrder �������� root�� �߰��� ���� --> ��/�� ��� ����.
		// [in_bidx, in_ridx) --> root�� ���� �ڽ��� inOrder ��ġ 
		// in_ridx --> root�� inOrder index 
		// [in_ridx + 1, in_eidx) --> root�� ���� �ڽ��� inOrder ��ġ 
		// [post_bidx, post_bidx + (in_ridx - in_bidx) ) -- > root�� ���� �ڽ��� PostOrder ��ġ 
		// [post_bidx + (in_ridx - in_bidx), post_eidx - 1 ) -- > root�� ���� �ڽ��� PostOrder ��ġ 
		right = post[post_eidx - 2];
		left = post[post_bidx + (in_ridx - in_bidx) - 1];
		findTree(post_bidx, post_bidx + (in_ridx - in_bidx), in_bidx, in_ridx);
		findTree(post_bidx + (in_ridx - in_bidx), post_eidx - 1, in_ridx + 1, in_eidx);
	}
	
	tree[root][0] = left;
	tree[root][1] = right;
	
	return;
}

void preOrder(int idx) {
	cout << idx << ' ';
	if (tree[idx][0] != -1) preOrder(tree[idx][0]);
	if (tree[idx][1] != -1) preOrder(tree[idx][1]);
} 

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	int root;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> in[i];
	for (int i = 0; i < n; i++) cin >> post[i];
	
	findTree(0, n, 0, n);
	preOrder(post[n - 1]);
	cout << '\n';
	
	return 0;
} 
