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
const int N = 1e6 + 5;

ll n, k;
int a[N], b[N];

void run() {
	ll ans = (n + 1) * n / 2;
	if(ans > k) {
		cout << -1 << '\n';
		return;
	}
	for(int i = 1; i <= n; i++) a[i] = b[i] = i;
	int p = n / 2;
	int now = n - 1, pos = 1;
	for(int i = 1; i <= p; i++) {
		if(ans + now > k) {
			swap(a[pos], a[pos + k - ans]);
			break;
		}
		ans += now;
		now -= 2;
		swap(a[pos], a[n - pos + 1]);
		++pos;
	}
	ll sum = 0;
	for(int i = 1; i <= n; i++) sum += max(a[i], b[i]);
	cout << sum << '\n';
	for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
	for(int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    while(cin >> n >> k) run();
    return 0;
}
