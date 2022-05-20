/*
	해석:
	채우는데 걸리는 시간과 높이를 구하는 것이기에,
	좌표값은 사실 의미가 없다.
	중요한 것은, 얼마나 블록을 채워야하는지에 집중하면 된다.
	즉, 정보를 요약하면
	좌표 각각에 블록이 얼마나 있는 것이 아닌,
	높이 h에 블록이 몇개 있는지만 알아도 해결이 가능하다는 점이다.
	
	※ 시각을 달리하면 연산 시간을 줄일 수도 있다는 점을 명심하자. 
*/

#include <cstdio>

int main() {
	int N, M, B, area, h, time, bottom, top = 0;
	int height[257] = {0, };
	
	scanf("%d%d%d", &N, &M, &B);
	area = N*M;
	for (int i=0; i<area; i++) {
		scanf("%d", &h);
		top = top < h ? h : top;
		for (int i=0; i<=h; i++)
			height[i]++;
	}
	
	time = bottom = 0;
	
	while(height[bottom] == area)
		bottom++;
	
	while(height[top] != area) {
		if (area-height[bottom] <= B && area-height[bottom] <= height[top]*2 ) {
			B -= area-height[bottom];
			time += area-height[bottom];
			height[bottom] = area;
			bottom++;
		} else {
			B += height[top];
			time += height[top]*2;
			height[top] = 0;
			top--;
		}
	}
	
	printf("%d %d", time, top);
	
	return 0;
}
