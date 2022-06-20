/*
	POTION
	�Է�: �׽�Ʈ ���̽� �� c (50 ����)
		����� �� n (1 �̻� 200 ����),
		�������� ����� �� r(1 �̻� 1000 ����)
		�̹� ���� ���� ����� �� (0 �̻� 1000 ����) 
	���: �����Ǵ�� ������ ���߱� ���� �� ��Ḷ�� �� �־���ϴ� �� (1�� �̻�) 
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
