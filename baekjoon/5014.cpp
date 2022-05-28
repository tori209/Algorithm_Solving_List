#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	queue<int> cur;
	bool visit[1000001] = {false,};
	int ret = 0;
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	
	cur.push(s);
	visit[s] = true;
	while(!cur.empty()) {
		queue<int> next;
		while (!cur.empty()) {
			if (cur.front() == g) break;
			if (cur.front() + u <= f && !visit[cur.front() + u]) {
				next.push(cur.front() + u);
				visit[cur.front() + u] = true;
			}
			if (cur.front() - d > 0 && !visit[cur.front() - d]) {
				next.push(cur.front() - d);
				visit[cur.front() - d] = true;
			}
			cur.pop();
		}
		
		if (!cur.empty()) {
			cout << ret << '\n';
			return 0;
		};
		cur = next;
		ret++;
	}
	cout << "use the stairs\n";
	return 0;
}
