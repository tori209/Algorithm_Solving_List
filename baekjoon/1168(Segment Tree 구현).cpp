/*
	1168번
	문제: 요세푸스 문제2 (1은 런타임 2초이지만, 2는 런타임 0.15라서 주먹구구식으로 절대 못푼다.) 
	입력: 양의 정수 k, n (1 <= k <= n <= 5,000)
	출력: 주어진 수로 구성한 요세푸스 순열
	
	※ 요세푸스 순열
	n명의 사람이 원을 이루고 앉아있고, 1번부터 n번까지 존재할 때,
	k번을 제거하고, k+1번을 기준으로 k번째에 있는 인원을 다시 제거한다.
	이를 반복하여 모든 인원을 제거한 뒤, 제거된 순서대로 번호를 나열한 것을  요세푸스 순열이라고 한다.
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
