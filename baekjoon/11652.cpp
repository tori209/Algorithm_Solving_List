/*
	11652��
	����: ī��
	�Է�: ī�� ���� N, N���� ī�� ������ ���� ����(���� < 2^62)
	���: ���� ���� ���� �ִ� ���� (�������� ��� �� �� ���� ���� ��)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool comp(pair<long long, int> &it1, pair<long long, int> &it2) {
	if (it1.second < it2.second) return true;
	else if (it1.second > it2.second) return false;
	else if (it1.first > it2.first) return true;
	else return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	long long temp;
	map<long long, int> match;
	vector<pair<long long, int>> vec; // ���� �̷��� ���߾ �ƴ�. 
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		match[temp]++;
	}
	for (pair<long long, int> p : match) vec.push_back(p);
	sort(vec.begin(), vec.end(), comp);
	
	cout << vec[vec.size() - 1].first << '\n';
	
	return 0;
}
