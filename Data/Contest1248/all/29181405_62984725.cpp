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
const int N = 1e5 + 5;

int n, m;
int a[N], b[N];

void run() {
	cin >> n;
	int c1 = 0, c2 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] & 1) ++c1;
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		if(b[i] & 1) ++c2;
	}
	ll ans = 1ll * c1 * c2 + 1ll * (n - c1) * (m - c2);
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
    int T; cin >> T;
    while(T--) run();
    return 0;
}
