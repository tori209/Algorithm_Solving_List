/*
	2263��
	����: Ʈ���� ��ȸ
	�Է�: ����Ʈ���� ���� �� n (1 �̻� 100,000 ����)�� inorder / postorder ��ȸ �� ��� ����
	���: preorder �� ��� ����
	
	// ������ �޸� ��뷮�� �þ���. ���� �Ҹ�. 
*/

#include <iostream>

using namespace std;

int in_index[100001];
int post[100000]; 

void findTree(int post_bidx, int post_eidx, int in_bidx, int in_eidx) {
	int root = post[post_eidx - 1];		// subtree�� root 
	int in_ridx = in_index[root];	// inOrder �󿡼� subtree root�� idx 
	int in_leftTreeNum = in_ridx - in_bidx;
	int in_rightTreeNum = in_eidx - in_ridx - 1;
	
	cout << root << ' ';
	
	if (in_leftTreeNum > 0)
		findTree(post_bidx, post_bidx + in_leftTreeNum, in_bidx, in_ridx);
	if (in_rightTreeNum > 0)
		findTree(post_eidx - in_rightTreeNum - 1, post_eidx - 1, in_ridx + 1, in_eidx);
		
	return; 
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		in_index[temp] = i;
	}
	for (int i = 0; i < n; i++) cin >> post[i];
	
	findTree(0, n, 0, n);
	cout << '\n';
	
	return 0;
} 
