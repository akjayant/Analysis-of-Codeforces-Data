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

int n;
int a[N];

void run() {
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0;
	for(int i = n; i > n / 2; i--) {
		sum += a[i];
	}
	int tot = 0;
	for(int i = 1; i <= n; i++) tot += a[i];
	int sum2 = tot - sum;
	ll ans = 1ll * sum * sum + 1ll * sum2 * sum2;
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
    while(cin >> n) run();
    return 0;
}
