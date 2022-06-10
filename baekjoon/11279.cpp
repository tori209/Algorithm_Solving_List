/*
	11279번
	문제: 최대 힙
	입력: 연산 개수 n (1 이상 100,000 이하)와 n개의 정수 x
		(x > 0이면 해당 수를 삽입, x == 0이면 최댓값 반환)
	출력: 0이 입력된 만큼 출력 실행. 
	
	기본 뼈대: 완전 이진 트리
	삽입 과정:
		완전 이진 트리에 따른 다음 leaf 위치에 새로운 값을 추가한다.
		해당 값을 parent와 비교하였을 때, leaf가 크다면 두 값을 switching 한다.
		만약 그렇지 아니하면 break한다.
		이를 parent에 대해 재시도한다. 
		이를 root에 도달할 때까지, 혹은 종료될 때까지 반복한다. (O(logN))
	삭제 과정:
		root의 값을 출력한 후, 가장 최근에 추가한 leaf의 값을 root에 덮어씌운다.
		이후 root와 좌/우 child를 비교하였을 때 두 값 중 하나라도 root보다 크면 그 값을 swap한다.
		아닐 경우 break한다.
		swap이 일어난 경우, swap한 child에 대해 위의 과정을 다시 실행한다.
		leaf에 도달하거나 과정이 종료될 때까지 위의 과정을 반복한다. (O(logN)) 
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	unsigned int val[100001];
	int n, x, valnum = 0;
	
	cin >> n;
	while (n--) {
		cin >> x;
		
		if (x == 0) { // 최댓값 출력 
			if (valnum == 0) cout << 0 << '\n';
			else {
				cout << val[1] << '\n';
				val[1] = val[valnum--];
				
				int left, right, temp;
				for (int idx = 1;;) {
					left = 2*idx;
					right = 2*idx + 1;
					
					if (left > valnum && right > valnum) break;	// leaf 도달
					if (val[idx] >= val[left] && val[idx] >= val[right]) break; // 더이상 나아갈 이유가 없음. 
					
					if (val[left] >= val[right]) {
						temp = val[idx];
						val[idx] = val[left];
						val[left] = temp;
						idx *= 2;
					} else {
						temp = val[idx];
						val[idx] = val[right];
						val[right] = temp;
						idx = 2*idx + 1;
					}
				}
			}
		} else {
			val[++valnum] = x;
			for (int idx = valnum;;) {
				if (idx == 1) break;
				
				int temp;
				if (val[idx] > val[idx/2]) {
					temp = val[idx];
					val[idx] = val[idx/2];
					val[idx/2] = temp;
					idx /= 2;
				} else break;
			}
		}
	}
	
	return 0;
}
