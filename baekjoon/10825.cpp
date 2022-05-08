/*
	10825번
	문제: 국영수 
	입력: 인원 수 N / N개의 데이터 (학생명 국어 영어 수학) 
	출력: N개의 카드를 구매하기 위해 지불해야하는 금액의 최댓값.
		※ 단, N개를 초과하여 구매한 후 버리는 선택지는 불가하다.
		※ Pi 는 i개의 카드가 들어있는 카드팩을 의미한다. 
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
