#include <cstdio>
#include <algorithm>
#include <utility>

#define FOR(i, n) for(int i = 0; i < n; i++) 

#define pow CHANGETHENAMESTUPID

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 11;
const int M = 101;

double dp[N][N];

int index[N][N];;
int kon[M];

void load() {
	int ind = 0;
	FOR(i, 10) {
		FOR(j, 10) {
			int j_ = (i & 1) ? 9 - j : j;
			index[i][j_] = ind++;
		}
	}
	FOR(i, M) kon[i] = -1;
	FOR(i, 10) {
		FOR(j, 10) {
			int x;
			scanf("%d", &x);
			kon[index[i][j]] = index[i-x][j];
		}
	}
}

void solve() {
	double dp[110];
	dp[0] = 0;
	for (int i = 1; i < 100; i++) {
		dp[i] = 0;
		double right = 1;
		int br = 0;
		for (int k = 1; k <= 6; k++) {
			if (i - k >= 0) {
				right += 1.0/6.0 * min(dp[i-k], dp[kon[i-k]]);
			} else {
				br++;
			}
		}
		dp[i] = right / (1.0-(double)br/6.0);
	}
	printf("%.10lf\n", dp[99]);
}

int main() {
	load();
	solve();
	return 0;
}
