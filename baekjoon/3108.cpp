/*
	3108번
	문제: 로고 
	입력: 직사격형의 개수 N (1 이상 1000 이하) 
		각 직사각형의 좌표 x1, y1, x2, y2 (-500 이상 500이하) 
	출력: 직사각형 집합 개수 (겹치는 직사각형이 집합 내에 하나라도 있으면 같은 집합.) 
*/

#include <iostream>
#include <list>
#include <utility>
#include <set>

using namespace std;

bool isOverlap(pair<int, int> ld1, pair<int, int> ru1, pair<int, int> ld2, pair<int, int> ru2) {
	if (ld1.second > ru2.second) return false;
	if (ld2.second > ru1.second) return false;
	if (ru1.first < ld2.first) return false;
	if (ru2.first < ld1.first) return false;
	if (ld1.first > ld2.first && ld1.second > ld2.second && ru1.first < ru2.first && ru1.second < ru2.second) return false;
	if (ld1.first < ld2.first && ld1.second < ld2.second && ru1.first > ru2.first && ru1.second > ru2.second) return false;
	
	return true;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, setnum = 0, ret = 0;
	int x1, y1, x2, y2;
	list< set< pair< pair<int, int>, pair<int, int> > > > boxsetlist;
	set<pair<pair<int, int>, pair<int, int>>>::iterator boxsetiter;
	
	cin >> n;
	while (n--) {
		cin >> x1 >> y1 >> x2 >> y2;
		set<pair<pair<int, int>, pair<int, int>>> box;
		box.insert({{x1, y1}, {x2, y2}});
		
		if (isOverlap({0, 0}, {0, 0}, {x1, y1}, {x2, y2})) ret = -1;
		
		int num = boxsetlist.size();
		for (int i = 0; i < num; i++) {
			set<pair<pair<int, int>, pair<int, int>>> boxset = boxsetlist.front();
			boxsetlist.pop_front();
			for (boxsetiter = boxset.begin(); boxsetiter != boxset.end(); boxsetiter++) {
				if (isOverlap({x1, y1}, {x2, y2}, boxsetiter->first, boxsetiter->second)) break;
			}
			if (boxsetiter == boxset.end()) boxsetlist.push_back(boxset);
			else box.merge(boxset);
		}
		boxsetlist.push_back(box);
	}
	
	/*
	for (int i = 0; ; i++) {
		int x1, x2, x3, x4;
		int y1, y2, y3, y4;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;
		cout << (isOverlap({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}) ? "True" : "False") << '\n';
	}
	*/
	
	ret += boxsetlist.size();
	cout << ret << '\n';
	
	return 0; 
}
