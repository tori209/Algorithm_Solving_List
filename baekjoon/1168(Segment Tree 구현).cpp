/*
	1168��
	����: �似Ǫ�� ����2 (1�� ��Ÿ�� 2��������, 2�� ��Ÿ�� 0.15�� �ָԱ��������� ���� ��Ǭ��.) 
	�Է�: ���� ���� k, n (1 <= k <= n <= 5,000)
	���: �־��� ���� ������ �似Ǫ�� ����
	
	�� �似Ǫ�� ����
	n���� ����� ���� �̷�� �ɾ��ְ�, 1������ n������ ������ ��,
	k���� �����ϰ�, k+1���� �������� k��°�� �ִ� �ο��� �ٽ� �����Ѵ�.
	�̸� �ݺ��Ͽ� ��� �ο��� ������ ��, ���ŵ� ������� ��ȣ�� ������ ����  �似Ǫ�� �����̶�� �Ѵ�.
*/

#include <iostream>
#include <vector>

using namespace std;

class Segment_Tree {
	private:
		int num;
		int tree[1 << 18];
	public:
		int _Creator(int idx, int s, int e);
		int _findVal(int idx, int s_range, int e_range, int s_tar, int e_tar) const;
		void _replaceVal(int idx, int s_range, int e_range, int tar_idx);
		
		Segment_Tree(int n) {
			num = n;
			_Creator(1, 0, n - 1);
		}
		
		void replace(int idx) {
			_replaceVal(1, 0, num-1, idx);
		}
		
		int findSum(int idx, int s_idx, int e_idx, int val) {
			//cout << s_idx << '\n';
			if (s_idx == e_idx) return s_idx;
			int mid = (s_idx + e_idx) / 2;
			
			//cout << val << ' ' << s_idx << ' ' << mid << ' '  << e_idx << '\n';
			
			if (val <= tree[2 * idx]) return findSum(2*idx, s_idx, mid, val);
			else return findSum(2*idx + 1, mid + 1, e_idx, val - tree[2*idx]);
		}
		
		~Segment_Tree() {}
}; 

int Segment_Tree::_Creator (int idx, int s, int e) {
	if (e == s) {
		tree[idx] = 1;
		return 1;
	}
	return tree[idx] = _Creator(2 * idx, s, (s + e)/2) + _Creator(2 * idx + 1, (s + e) / 2 + 1, e);
}

void Segment_Tree::_replaceVal(int idx, int s_range, int e_range, int tar_idx) {
	tree[idx]--;
	if (tar_idx == s_range && tar_idx == e_range) {
		return;
	}
	
	int mid_range = (s_range + e_range) / 2;
	if (tar_idx <= mid_range) _replaceVal(2*idx, s_range, mid_range, tar_idx);
	else _replaceVal(2*idx + 1, mid_range + 1, e_range, tar_idx);
	
	return;
}

int main() {
	//cin.tie(0);
	//cout.tie(0);
	//ios::sync_with_stdio(0);
	
	int n, k, idx, tar, size;
	cin >> n >> k;
	Segment_Tree st(n);
	
	idx = 1; size = n;
	cout << '<';
	while (size > 0) {
		idx += k - 1;
		if (idx % size == 0) idx = size;
		else idx %= size;
		
		tar = st.findSum(1, 0, n-1, idx);
		st.replace(tar);
		cout << tar + 1 << (size != 1 ? ", " : ">\n");
		
		size--;
	}
	
	return 0;
}
