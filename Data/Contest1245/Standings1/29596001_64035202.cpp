#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
int l[35], r[35];
int dp[35][2][2][2][2];
// digit, greater match l, lesser match l, greater match r, lesser match r
// we can assign (0,0) (0,1) (1,0)
int get (int dig, bool less, int old, int new_dig) {
	if (less) {
		if (new_dig > r[dig] and !old)
			return -1;
		if (old)
			return old;
		return r[dig] > new_dig;
	}
	else {
		if (new_dig < l[dig] and !old)
			return -1;
		if (old)
			return old;
		return new_dig > l[dig];
	}
}
void solve() {
	memset(dp, 0, sizeof dp);
	int L, R;
	cin >> L >> R;
	if (L == R) {
		if (L + R == (L ^ R)) {
			cout << 1 << '\n';
			return;
		}
		else {
			cout << 0 << '\n';
			return;
		}
	}
	int maxbits = 31;
	for (int i = 0; i < maxbits; ++i) {
		if ((1LL << i) & L)
			l[maxbits - i] = 1;
		else
			l[maxbits - i] = 0;
		if ((1LL << i) & R) 
			r[maxbits - i] = 1;
		else
			r[maxbits - i] = 0;
	}
	// l[1], l[2], ..., l[35]
	dp[0][0][0][0][0] = 1;
	for (int i = 1; i <= maxbits; ++i) {
		for (int oa = 0; oa < 2; ++oa) {
			for (int ob = 0; ob < 2; ++ob) {
				for (int oc = 0; oc < 2; ++oc) {
					for (int od = 0; od < 2; ++od) {
						int na, nb, nc, nd;
						for (int new_dig1 = 0; new_dig1 < 2; ++new_dig1) {
							for (int new_dig2 = 0; new_dig2 < 2; ++new_dig2) {
								if (new_dig1 and new_dig2)
									continue;
								na = get(i, false, oa, new_dig1);
								nb = get(i, false, ob, new_dig2);
								nc = get(i, true, oc, new_dig1);
								nd = get(i, true, od, new_dig2);
								if (na == -1 or nb == -1 or nc == -1 or nd == -1)
									continue;
								dp[i][na][nb][nc][nd] += dp[i - 1][oa][ob][oc][od];
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int fa = 0; fa < 2; ++fa) {
		for (int fb = 0; fb < 2; ++fb) {
			for (int fc = 0; fc < 2; ++fc) {
				for (int fd = 0; fd < 2; ++fd) {
					ans += dp[maxbits][fa][fb][fc][fd];
				}
			}
		}
	}
	cout << ans << '\n';
}       
