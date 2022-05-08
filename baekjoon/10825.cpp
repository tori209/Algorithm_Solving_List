/*
	10825��
	����: ������ 
	�Է�: �ο� �� N / N���� ������ (�л��� ���� ���� ����) 
	���: N���� ī�带 �����ϱ� ���� �����ؾ��ϴ� �ݾ��� �ִ�.
		�� ��, N���� �ʰ��Ͽ� ������ �� ������ �������� �Ұ��ϴ�.
		�� Pi �� i���� ī�尡 ����ִ� ī������ �ǹ��Ѵ�. 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
vector<vector<int>> d;
string name[100000];

bool comp(vector<int> &d1, vector<int> &d2) {
	if (d1[1] > d2[1]) return true;
	else if (d1[1] < d2[1]) return false;
	
	if (d1[2] < d2[2]) return true;
	else if (d1[2] > d2[2]) return false;
	
	if (d1[3] > d2[3]) return true;
	else if (d1[3] < d2[3]) return false;
	
	if (name[d1[0]].compare(name[d2[0]]) < 0) return true;
	else return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		d.push_back(*(new vector<int>(4, 0)));
		d[i][0] = i;
		cin >> name[i] >> d[i][1] >> d[i][2] >> d[i][3];
	}
	
	sort(d.begin(), d.end(), &comp);
	
	for (vector<int> it : d) {
		cout << name[it[0]] << '\n';
	}
	
	return 0; 
}
