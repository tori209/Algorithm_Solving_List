#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int bidx, eidx, cnt = 0;
	string line;
	
	/*
	cin >> line;
	cout << line << '\n';
	
	for (bidx = 0; bidx < line.size(); bidx++)
		if (line[bidx] != ' ') break;
	for (eidx = line.size() - 1; eidx >= 0; eidx--)
		if (line[eidx] != ' ') break;
		
	for (int i = bidx; i < eidx; i++) 
		if (line[i] == ' ' && line[i] != line[i+1]) cnt++;
	*/
	while(cin >> line) cnt++;
	
	cout << cnt;
	
	return 0;
}
