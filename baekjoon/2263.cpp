/*
	2263번
	문제: 트리의 순회
	입력: 이진트리의 정점 수 n (1 이상 100,000 이하)와 inorder / postorder 순회 시 출력 순서
	출력: preorder 시 출력 순서
*/

#include <iostream>

using namespace std;

int tree[100001][2];
int in[100000];
int post[100000];

void findTree(int post_bidx, int post_eidx, int in_bidx, int in_eidx) {
	if (post_bidx >= post_eidx) return; 	// 오류? 
	if (post_eidx - post_bidx == 1) {		// leaf 도달 
		tree[post[post_eidx - 1]][0] = tree[post[post_bidx]][1] = -1;
		return;
	} 
	
	// 최소한 자식 1개는 있는 경우들. 
	int root = post[post_eidx - 1];		// subtree의 root 
	int left = -1, right = - 1;	// subtree root의 좌/우 자식 
	int in_ridx;	// inOrder 상에서 subtree root의 idx 
	
	
	
	for (in_ridx = in_bidx; in_ridx < in_eidx; in_ridx++) {
		if (in[in_ridx] == root) break;
	}
	
	if (in_ridx == in_bidx) {
		// inOrder 구성에서 root가 첫번째에 나옴 --> 왼쪽 자식이 없다는 뜻 
		right = post[post_eidx - 2];
		findTree(post_bidx, post_eidx - 1, in_bidx + 1, in_eidx);
	} else if (in_ridx == in_eidx - 1) {
		// inOrder 구성에서 root가 마지막에 나옴 --> 오른쪽 자식이 없다는 뜻
		left = post[post_eidx - 2];
		findTree(post_bidx, post_eidx - 1, in_bidx, in_eidx - 1);
	} else {
		// inOrder 구성에서 root가 중간에 나옴 --> 좌/우 모두 있음.
		// [in_bidx, in_ridx) --> root의 좌측 자식의 inOrder 배치 
		// in_ridx --> root의 inOrder index 
		// [in_ridx + 1, in_eidx) --> root의 우측 자식의 inOrder 배치 
		// [post_bidx, post_bidx + (in_ridx - in_bidx) ) -- > root의 좌측 자식의 PostOrder 배치 
		// [post_bidx + (in_ridx - in_bidx), post_eidx - 1 ) -- > root의 우측 자식의 PostOrder 배치 
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
