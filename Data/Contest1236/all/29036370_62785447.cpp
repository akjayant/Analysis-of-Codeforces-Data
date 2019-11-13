#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define SZ(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
#define repe(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
inline int getv(int b, int c) {
	return min(b, c / 2) * 3;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		rep (i, 0, 50) {
			if (a >= i && b >= i + i) {
				ans = max(ans, i * 3 + getv(b - i * 2, c));
			}
		}
		cout << ans << endl;
	}
	return 0;
}