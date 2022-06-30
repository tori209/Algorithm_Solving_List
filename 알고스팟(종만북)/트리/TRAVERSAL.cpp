#include <iostream>

using namespace std;

int inOrderIdx[1001];
int preOrder[100];

void findPostOrder (int pre_bidx, int pre_eidx, int in_bidx, int in_eidx) {
	int root = preOrder[pre_bidx];
	int in_ridx = inOrderIdx[root];
	int lhs_num = in_ridx - in_bidx;
	int rhs_num = in_eidx - in_ridx - 1;
	
	if (lhs_num > 0)
		findPostOrder(pre_bidx + 1, pre_bidx + lhs_num + 1, in_bidx, in_ridx);
	if (rhs_num > 0)
		findPostOrder(pre_bidx + lhs_num + 1, pre_eidx, in_ridx + 1, in_eidx);
	
	cout << root << ' ';
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n, temp;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> preOrder[i];
		for (int i = 0; i < n; i++) {
			cin >> temp;
			inOrderIdx[temp] = i;
		}	
		findPostOrder(0, n, 0, n);
		cout << '\n';
	}
	
	return 0;
}
