#include <bits/stdc++.h>
using namespace std;
const int SZ = 10;
int a[SZ + 9][SZ + 9];
pair<int, int> path[SZ * SZ + 9];
int pos[SZ + 9][SZ + 9];
long double f[SZ * SZ + 9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(9) << fixed;
	for(int i = 1; i <= SZ; i++) {
		for(int j = 1; j <= SZ; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i = 1; i <= SZ; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= SZ; j++) {
				cnt++;
				path[cnt] = make_pair(i, j);
				pos[i][j] = cnt;
			}
		}
		else {
			for(int j = SZ; j >= 1; j--) {
				cnt++;
				path[cnt] = make_pair(i, j);
				pos[i][j] = cnt;
			}
		}
	}
	f[1] = 0;
	for(int i = 2; i <= SZ * SZ; i++) {
		f[i] = 0;
		long double out = 0;
		for(int dice = 1; dice <= 6; dice++) {
			if(i - dice < 1) {
				out += (long double)1 / 6;
			}
			else {
				pair<int, int> x = path[i - dice];
				int lad = pos[x.first - a[x.first][x.second]][x.second];
				f[i] += (long double)1 / 6 * (1 + min(f[i - dice], f[lad]));
			}
		}
		f[i] = (f[i] + out) / (1 - out);
	}
	cout << (double)f[SZ * SZ] << "\n";
	return 0;
}