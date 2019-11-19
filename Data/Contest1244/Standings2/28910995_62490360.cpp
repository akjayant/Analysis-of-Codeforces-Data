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
const int MAXN = 1e5 + 20;
int a[MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	lint n, k;
	cin >> n >> k;
	rep (i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	rep (i, 2, n) {
		if (a[i] == a[i - 1]) l = i;
		else break;
	}
	per (i, n - 1, 1) {
		if (a[i] == a[i + 1]) r = i;
		else break;
	}
	if (l == n) {
		cout << 0 << endl;
		return 0;
	}
	int mn = a[1];
	int mx = a[n];
	while (k) {
		if (mx == mn) break;
		if (l >= r) break;
		if (l <= (n - r + 1)) {
			lint dist = a[l + 1] - a[l];
			if (k >= dist * l) {
				k -= dist * l;
				mn = a[++l];
				rep (i, l + 1, n) {
					if (a[i] == a[i - 1]) l = i;
					else break;
				}
			} else {
				mn += k / l;
				break;
			}
		} else {
			lint dist = a[r] - a[r - 1];
			if (k >= dist * (n - r + 1)) {
				k -= dist * (n - r + 1);
				mx = a[--r];
				per (i, r - 1, 1) {
					if (a[i] == a[i + 1]) r = i;
					else break;
				}
			} else {
				mx -= k / (n - r + 1);
				break;
			}
		}
	}
	cout << mx - mn << endl;
	return 0;
}