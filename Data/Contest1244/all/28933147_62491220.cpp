// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

int n;
vi G[100001];
ll c[3][100001];
ll dp[3][2];
int ans[100001];
int hist[100001];
int vt[100001];

int main() {
	cin >> n;
	for (int j=0; j<3; j++) {
		for (int i=1; i<=n; i++) cin >> c[j][i];
	}
	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int v = 0;

	for (int i=1; i<=n; i++) {
		if (G[i].size() > 2) {
			puts("-1");
			return 0;
		}
		if (G[i].size() == 1) {
			v = i;
		}
	}

	for (int i=1; i<=n; i++) {
		hist[i] = v;
		vt[v] = 1;
		for (auto e:G[v]) {
			if (!vt[e]) v = e;
		}
	}


	for (int j=0; j<3; j++) {
		for (int k=0; k<2; k++) {
			int t = j;
			for (int i=1; i<=n; i++) {
				dp[j][k] += c[t][hist[i]];
				t += k*2-1 + 3;
				t %= 3;
			}
		}
	}

	ll min_val=1e18;
	int min_idx=0;
	int min_dir=0;

	for (int i=0; i<3; i++) {
		for (int j=0; j<2; j++) {
			if (dp[i][j] < min_val) {
				min_val = dp[i][j];
				min_idx = i;
				min_dir = j;
			}
		}
	}

	printf("%lld\n", min_val);
	int t = min_idx;
	for (int i=1; i<=n; i++) {
		ans[hist[i]] = t;
		t += 2*min_dir-1+3;
		t %= 3;
	}

	for (int i=1; i<=n; i++) {
		printf("%d ", ans[i]+1);
	}
	return 0;
}
