/*
	11652번
	문제: 카드
	입력: 카드 개수 N, N개의 카드 각각에 적힌 정수(절댓값 < 2^62)
	출력: 가장 많이 갖고 있는 정수 (여러개일 경우 그 중 가장 작은 수)
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
	vector<pair<long long, int>> vec; // 굳이 이렇게 안했어도 됐다. 
	
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
