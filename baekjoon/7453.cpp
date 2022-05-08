#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, idx1, idx2;
	long long count;

	int* a = new int[4000];
	int* b = new int[4000];
	int* c = new int[4000];
	int* d = new int[4000];
	int* ab = new int[16000000];
	int* cd = new int[16000000];
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab[i*n + j] = a[i] + b[j];
			cd[i*n + j] = c[i] + d[j];
		}
	}
	
	sort(ab + 0, ab + n*n);
	sort(cd + 0, cd + n*n);
	
	count = 0;
	idx1 = 0;
	idx2 = n * n - 1;
	while (idx1 != n * n && idx2 != -1) {
		if (ab[idx1] + cd[idx2] > 0) {
			idx2--;
		} else if (ab[idx1] + cd[idx2] < 0) {
			idx1++;
		} else {
			long long up, down;
			for (up = 0; idx1 + up < n * n; up++) {
				if (ab[idx1] != ab[idx1 + up]) break;
			}
			for (down = 0; idx2 - down > - 1; down++) {
				if (cd[idx2] != cd[idx2 - down]) break;
			}
			
			count += (up * down);
			idx1 += up;
			idx2 -= down;
		}
	}
	cout << count << '\n';
	return 0;
}
