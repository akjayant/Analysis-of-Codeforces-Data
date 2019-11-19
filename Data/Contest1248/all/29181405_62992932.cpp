#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define Local
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5, MOD = 1e9 + 7;

int n, m;

void run() {
	int ans = 0;
	int pre = 1, now = 1;
	for(int i = 2; i <= m; i++) {
		int tmp = now;
		now = (pre + now) % MOD;
		pre = tmp;
	}
	ans = 2ll * (now - 1) % MOD;
	pre = 1, now = 1;
	for(int i = 2; i <= n; i++) {
		int tmp = now;
		now = (pre + now) % MOD;
		pre = tmp;
	}
	ans = (ans + 2ll * now) % MOD;
	cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    while(cin >> n >> m) run();
    return 0;
}
