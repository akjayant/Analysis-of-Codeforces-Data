#include <bits/stdc++.h>
#define mem(sx, sy) memset(sx, sy, sizeof(sx))
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8;
const double PI = acos(-1.0);
const ll llINF = 0x3f3f3f3f3f3f3f3f;
const double INF = 1e9;
using namespace std;
#define pa pair<int, int>
// const int maxn = 1e6+5;

int ma[100][100];
int n, m;
int id(int x, int y) {
	return x * m + y;
}
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
const int MAXN = 1e5 + 10;
ll f[MAXN];
const int MOD = 1e9 + 7;
int main() {
	/*
	for (n = 1; n <= 20; n++) {
		for (m = 1; m <= 20; m++) {

			if (n * m > 25) continue;
			mem(ma, -1);
			int ans = 0;
			for (int v = 0; v < (1 << (n * m)); v++) {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if (v & (1 << id(i - 1, j - 1))) ma[i][j] = 1;
						else ma[i][j] = 0;
					}
				}

				int flag = 1;
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						int c = 0;
						for (int tt = 0; tt < 4; tt++) {
							int ii = i + dx[tt];
							int jj = j + dy[tt];
							if (ma[ii][jj] == ma[i][j]) c++;
						}
						if (c > 1) { flag = 0; break; }
					}
				}
				ans += flag;
			}
			cout << setw(2) <<  ans << " ";




		}
		cout << endl;
	}
	*/
	
	f[0] = f[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= MOD;
	}
	int n, m;
	while (cin >> n >> m) {
		cout << (f[n] + f[m] - 1) * 2 % MOD << endl;
	}

}
/*
3
1 3 2
2
0 3
1
1

*/