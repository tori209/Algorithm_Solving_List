/*
	2263번
	문제: 트리의 순회
	입력: 이진트리의 정점 수 n (1 이상 100,000 이하)와 inorder / postorder 순회 시 출력 순서
	출력: preorder 시 출력 순서
	
	// 오히려 메모리 사용량이 늘었다. 원인 불명. 
*/

#include <iostream>

using namespace std;

int in_index[100001];
int post[100000]; 

void findTree(int post_bidx, int post_eidx, int in_bidx, int in_eidx) {
	int root = post[post_eidx - 1];		// subtree의 root 
	int in_ridx = in_index[root];	// inOrder 상에서 subtree root의 idx 
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
