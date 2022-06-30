/*
	6549번
	문제: 히스토그램에서 가장 큰 직사각형 
	입력: 너비가 1인 직사각형의 개수 n (1 이상 100,000 이하)
		※ 0이 입력되면 종료한다. 
		이후 n개의 직사각형들의 높이 hi (0 이상 1,000,000,000 이하)
	출력: 직사각형들을 순서대로 붙여 도형을 만들 때, 해당 도형이 포함할 수 있는 직사각형의 최대 크기
	
	※ 해법은 종만북의 예제를 보고 구현하였다. 
	핵심: i번째 직사각형의 높이보다 낮은 직사각형들 중 직사각형과 가장 가까운 좌측/우측 인덱스를 구한다. (각각 left[i], right[i]) 
	
	만약 i번째 직사각형의 left[i]와 right[i]를 알고 있다면,
	해당 직사각형을 높이로 갖는 직사각형의 최대 크기는, (right[i] - left[i] - 1) * height[i]가 된다.
	
	만약, 각 직사각형에 대해 left와 right를 일일이 구한다면, 좌/우로 선형 탐색을 하게 되므로 O(n^2)이 된다.
	따라서, 다른 해법을 찾아야만 한다.
	
	만약, 하단의 방법에 따라 스위핑을 한다면 left와 right를 구할 수 있다.
	우선, stack의 용도를 '현재 right를 알 수 없는 직사각형들의 모임'으로 정하자.
	right를 알 수 없다는 것은 '여태까지 본 직사각형들에 한하여서는(즉, 0~i번째) 자기 자신보다 높이가 낮은 직사각형은 없다.'라는 뜻이다.
	즉, stack의 바닥에 있을수록 직사각형의 높이는 작다는 뜻이며, 따라서 stack 내부에는 직사각형의 높이가 오름차순으로 나열되어있다고 할 수 있다.
	이는 곧, 최소한 stack 내에 있는 것들은 left를 알고 있다는 뜻으로 해석할 수 있으며, left는 stack 상에서 자기 자신 바로 뒤에 있는 직사각형이라고 생각할 수 있다. 
	그렇기에 stack 상에서는 높이가 동일한 직사각형은 존재하면 안되며, 따라서 높이가 동일한 직사각형은 stack에 저장할 수 없도록 해야한다.
	
	위의 아이디어를 토대로, 다음과 같은 규칙을 만들 수 있다.
		현재 i번째 직사각형의 높이를 보고 있다고 할 때,
		stack.top(= top)에 대하여 
		1) height[top] > height[i]
			top번째 상자에 대해, i번째 직사각형이 right의 역할을 하게 되며,
			top 바로 뒤에 위치하는 직사각형(= prev(top))이 left의 역할을 한다. 
			즉, top번째 상자를 포함하는 직사각형의 크기의 최댓값은 height[top] * (i - prev(top) - 1) 이 된다.
			※ stack에 top만 있을 경우, prev(top) - 1 대신 0으로 처리한다. 
			top번째 상자의 left, right를 모두 알게 되었으므로, top은 stack에서 제거한다.
			
			처리 이후, i번째 직사각형이 prev(top)의 right가 될 수도 있으므로, 분기를 다시 시도한다. 
		2) height[top] < height[i] 
			i번째 상자가 top번째 상자의 right가 될 수 없으므로, 일단 넘어간다.
			이때, top번째 상자는 i번째 상자의 left가 되기 때문에 i를 stack에 push한다.
		3) height[top] == height[i]
			stack의 정의 상 i를 버리거나, top을 pop한 후 i를 넣어야 한다.
			하지만, 만약 i를 넣게 된다면 차후 추가되는 직사각형들의 left가 i번째 상자가 된다는 것인데,
			만약 top을 유지하고, i를 버리게 된다면,
			차후 stack에 다른 원소 j를 넣을 때, j의 left가 top이라는 뜻이 된다.
			하지만 실질적으로 j의 left는 i가 되어야하기에, 그릇된 답이 출력된다.
			
			따라서, top를 버리고 i를 추가하여야 한다.
			
	위의 처리를 마무리한 뒤, stack에 반드시 1개 이상의 값이 남게 된다.
	아직까지 stack에 남은 직사각형들은 right가 없다는 뜻이기에,
	이들을 포함하는 직사각형의 최대 크기는 (n - prev(top) - 1) * height[top]이 된다.
	※ stack에 top만 있을 경우, prev(top) - 1 대신 0을 넣는다.  
*/
// 아이디어는 종만북 19장에서 알게 되었다. 

#include <iostream>
#include <stack>

using namespace std;

long long height[100000];

long long solve(int n) {
	long long ret = 0LL;
	stack<int> remain_idx;
	
	for (int i = 0; i < n; i++) 
		cin >> height[i];
	
	remain_idx.push(0);
	for (int i = 1; i < n; i++) {
		while (height[remain_idx.top()] >= height[i]) {
			int tar = remain_idx.top();
			remain_idx.pop();
			
			if (remain_idx.empty()) {
				ret = max(ret, height[tar] * i);
				break;
			}
			else
				ret = max(ret, height[tar] * (i - remain_idx.top() - 1));
		}
		remain_idx.push(i);
	}
	
	while (!remain_idx.empty()) {
		int tar = remain_idx.top();
		remain_idx.pop();
		if (remain_idx.empty())
			ret = max(ret, n * height[tar]);
		else
			ret = max(ret, (n - remain_idx.top() - 1) * height[tar]);
	}
	
	return ret;
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << solve(n) << '\n';
	}
	
	return 0;
}
