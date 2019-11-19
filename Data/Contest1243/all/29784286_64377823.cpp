#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    // cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
int prime;
bool get (int n) {
	int cnt = 0;
	int nn = n;
	for (int i = 2; i * i <= nn; ++i) {
		if (n % i == 0)
			++cnt, prime = i;
		while (n % i == 0)
			n /= i;
	}
	if (cnt == 0) {
		prime = nn;
		return true;
	}
	if (cnt > 1 or n > 1)
		return false;
	return true;
}
void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return;
	}
	auto lol = get(n);
	if (!lol)
		cout << 1;
	else
		cout << prime;
}     