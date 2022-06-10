/*
	2263번
	문제: 트리의 순회
	입력: 이진트리의 정점 수 n (1 이상 100,000 이하)와 inorder / postorder 순회 시 출력 순서
	출력: preorder 시 출력 순서
*/

#include <iostream>

using namespace std;

// inOrder는 좌/우측 자식을 root로 갖는 subtree의 총 node 개수를 구하기 위해 쓰임.
// preOrder는 현 subtree의 root의 좌/우측 자식을 알기 위해 쓰임.
int in_index[100001];
int in[100000];
int post[100000]; 

void findTree(int post_bidx, int post_eidx, int in_bidx, int in_eidx) {
	int root = post[post_eidx - 1];		// subtree의 root 
	int in_ridx = in_index[root];	// inOrder 상에서 subtree root의 idx 
	
	// 어차피 root->좌->우 순서로 출력하고, 아래 과정에서도 좌->우로 재귀호출하도록 설정했으므로 이상 없음. 
	cout << root << ' '; 
	
	if (post_bidx >= post_eidx) return; 	// 오류? 
	if (post_eidx - post_bidx == 1) {		// leaf 도달 
		return;
	} 
	
	// 최소한 자식 1개는 있는 경우들. 
	if (in_ridx == in_bidx) {
		// inOrder 구성에서 root가 첫번째에 나옴 --> 왼쪽 자식이 없다는 뜻 
		findTree(post_bidx, post_eidx - 1, in_bidx + 1, in_eidx);
	} else if (in_ridx == in_eidx - 1) {
		// inOrder 구성에서 root가 마지막에 나옴 --> 오른쪽 자식이 없다는 뜻
		findTree(post_bidx, post_eidx - 1, in_bidx, in_eidx - 1);
	} else {
		// inOrder 구성에서 root가 중간에 나옴 --> 좌/우 모두 있음.
		// [in_bidx, in_ridx) --> root의 좌측 자식의 inOrder 배치 
		// in_ridx --> root의 inOrder index 
		// [in_ridx + 1, in_eidx) --> root의 우측 자식의 inOrder 배치 
		// [post_bidx, post_bidx + (in_ridx - in_bidx) ) -- > root의 좌측 자식의 PostOrder 배치 
		// [post_bidx + (in_ridx - in_bidx), post_eidx - 1 ) -- > root의 우측 자식의 PostOrder 배치 
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
