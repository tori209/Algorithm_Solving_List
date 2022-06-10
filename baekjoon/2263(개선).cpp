/*
	2263��
	����: Ʈ���� ��ȸ
	�Է�: ����Ʈ���� ���� �� n (1 �̻� 100,000 ����)�� inorder / postorder ��ȸ �� ��� ����
	���: preorder �� ��� ����
*/

#include <iostream>

using namespace std;

// inOrder�� ��/���� �ڽ��� root�� ���� subtree�� �� node ������ ���ϱ� ���� ����.
// preOrder�� �� subtree�� root�� ��/���� �ڽ��� �˱� ���� ����.
int in_index[100001];
int in[100000];
int post[100000]; 

void findTree(int post_bidx, int post_eidx, int in_bidx, int in_eidx) {
	int root = post[post_eidx - 1];		// subtree�� root 
	int in_ridx = in_index[root];	// inOrder �󿡼� subtree root�� idx 
	
	// ������ root->��->�� ������ ����ϰ�, �Ʒ� ���������� ��->��� ���ȣ���ϵ��� ���������Ƿ� �̻� ����. 
	cout << root << ' '; 
	
	if (post_bidx >= post_eidx) return; 	// ����? 
	if (post_eidx - post_bidx == 1) {		// leaf ���� 
		return;
	} 
	
	// �ּ��� �ڽ� 1���� �ִ� ����. 
	if (in_ridx == in_bidx) {
		// inOrder �������� root�� ù��°�� ���� --> ���� �ڽ��� ���ٴ� �� 
		findTree(post_bidx, post_eidx - 1, in_bidx + 1, in_eidx);
	} else if (in_ridx == in_eidx - 1) {
		// inOrder �������� root�� �������� ���� --> ������ �ڽ��� ���ٴ� ��
		findTree(post_bidx, post_eidx - 1, in_bidx, in_eidx - 1);
	} else {
		// inOrder �������� root�� �߰��� ���� --> ��/�� ��� ����.
		// [in_bidx, in_ridx) --> root�� ���� �ڽ��� inOrder ��ġ 
		// in_ridx --> root�� inOrder index 
		// [in_ridx + 1, in_eidx) --> root�� ���� �ڽ��� inOrder ��ġ 
		// [post_bidx, post_bidx + (in_ridx - in_bidx) ) -- > root�� ���� �ڽ��� PostOrder ��ġ 
		// [post_bidx + (in_ridx - in_bidx), post_eidx - 1 ) -- > root�� ���� �ڽ��� PostOrder ��ġ 
		findTree(post_bidx, post_bidx + (in_ridx - in_bidx), in_bidx, in_ridx);
		findTree(post_bidx + (in_ridx - in_bidx), post_eidx - 1, in_ridx + 1, in_eidx);
	}
	
	return;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		in_index[in[i]] = i;
	}
	for (int i = 0; i < n; i++) cin >> post[i];
	
	findTree(0, n, 0, n);
	cout << '\n';
	
	return 0;
} 
