#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++) 

#define pow CHANGETHENAMESTUPID

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 100100;
const ll inf = 4e18;

int n;

ll c[MAXN][3];
vector<int> graf[MAXN];

void load() {
	scanf("%d", &n);
	FOR(j, 3) FOR(i, n) scanf("%lld", &c[i][j]);
	FOR(i, (n-1)) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		graf[u].push_back(v); 
		graf[v].push_back(u);
	}
}

int red[MAXN];
ll dp[MAXN][3][3];
int best[MAXN][3][3];

void fun(int i, int b, int b1, int b2) {
	ll nk = dp[i-1][b1][b2] + c[red[i]][b];
	ll &ret = dp[i][b2][b];
	if (nk < ret) {
		ret = nk;
		best[i][b2][b] = b1;
	}
}

bool solve() {
	int rt = -1;
	FOR(i, n) {
		if (graf[i].size() > 2) return false;
		if (graf[i].size() == 1) rt = i;
	}
	int ind = 0;
	do {
		red[ind++] = rt;
		for (int sus : graf[rt]) {
			if (ind < 2 || sus != red[ind-2]) rt = sus;
		}
	} while (ind < n);
	FOR(i, n) FOR(j, 3) FOR(k, 3) dp[i][j][k] = inf;
	FOR(b1, 3) FOR(b2, 3) {
		if (b1 == b2) continue;
		else dp[1][b1][b2] = min(dp[1][b1][b2], c[red[0]][b1] + c[red[1]][b2]);
	}
	for (int i = 2; i < n; i++) {
		FOR(b, 3) {
			FOR(b1, 3) FOR(b2, 3) {
				if (b1 == b || b2 == b1 || b2 == b) continue;
				fun(i, b, b1, b2);
			}
		}
	}
	ll sol = inf;
	int best1, best2;
	FOR(i, 3) FOR(j, 3) {
		if (i == j) continue;
		if (dp[n-1][i][j] < sol) {
			sol = dp[n-1][i][j];
			best1 = i; best2 = j;
		}
		sol = min(sol, dp[n-1][i][j]);
	}
	int boj[n];
	boj[red[n-1]] = best2;
	boj[red[n-2]] = best1;
	ind = n-2;
	while (ind > 0) {
		int b = best[ind+1][best1][best2];
		boj[red[ind-1]] = b;
		best2 = best1;
		best1 = b;
		ind--;
	}
	printf("%lld\n", sol);
	FOR(i, n) printf("%d ", boj[i]+1);
	return true;
}

int main() {
	load();
	if (!solve()) printf("-1\n");
	return 0;
}
