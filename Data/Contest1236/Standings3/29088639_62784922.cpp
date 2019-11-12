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

int a, b, c;

void run() {
	cin >> a >> b >> c;
	int ta = a, tb = b, tc = c;

	int x = min(a, b / 2);
	int ans = 3 * x;
	b -= 2 * x;
	ans += min(b, c / 2) * 3;

	int y = min(tb, tc / 2);
	int res = y * 3;
	tb -= y;
	res += min(ta, tb / 2) * 3;
	
	ans = max(ans, res);
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
