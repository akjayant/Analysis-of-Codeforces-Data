#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 1005;

int n;
int pre[N];

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			pre[x]++;
		}

		for (int i = 1; i <= n; i++) {
			pre[i] += pre[i-1];
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int cnt = n - pre[i-1];
			if (cnt >= i) ans = i;
		}
		printf("%d\n", ans);
		reset(pre, 0);
	}
	return 0;
}