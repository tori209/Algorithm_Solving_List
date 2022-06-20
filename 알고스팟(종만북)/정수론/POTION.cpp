/*
	POTION
	입력: 테스트 케이스 수 c (50 이하)
		재료의 수 n (1 이상 200 이하),
		레시피의 재료의 양 r(1 이상 1000 이하)
		이미 냄비에 넣은 재료의 양 (0 이상 1000 이하) 
	출력: 레시피대로 비율을 맞추기 위해 각 재료마다 더 넣어야하는 양 (1병 이상) 
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> recipe;
vector<int> recipe_add;
vector<int> pot; 

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

void getAns() {
	if (recipe.size() == 1) {
		recipe_add[0] = 0;
	}
	int g = gcd(recipe[0], recipe[1]);
	for (int i = 1; i < recipe.size() - 1; i++) {
		int t_g = gcd(recipe[i], recipe[i + 1]);
		g = gcd(g, t_g);
		if (g == 1) break;
	}
	
	for (int i = 0; i < recipe.size(); i++) {
		recipe_add[i] = recipe[i] / g;
	}
	
	int mul = 0;
	for (int i = 0; i < recipe.size(); i++) {
		int t_mul = ceil((double)(pot[i] - recipe[i]) / recipe_add[i]);
		mul = max(t_mul, mul);
	}
	
	for (int i = 0; i < recipe.size(); i++) {
		cout << (recipe[i] + mul * recipe_add[i] - pot[i]) << ' '; 
	}
	cout << '\n';
	return;
} 

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c, n;
	
	cin >> c;
	while (c--) {
		cin >> n;
		recipe.clear(); recipe.resize(n);
		pot.clear(); pot.resize(n);
		recipe_add.clear(); recipe_add.resize(n);
		for (int i = 0; i < n; i++) cin >> recipe[i];
		for (int i = 0; i < n; i++) cin >> pot[i]; 
		getAns();
	}
	
	return 0;
} 
