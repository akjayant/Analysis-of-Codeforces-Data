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
    cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
const int N = 1005;
int arr[N];
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i += 1) 
		cin >> arr[i];
	int mx = -1;
	for (int check = 1; check <= n; ++check) {
		int cnt = 0;
		for (int i = 1; i <= n; i += 1) {
			if (arr[i] >= check)
				++cnt;
		}
		if (cnt >= check)
			mx = check;
	}
	cout << mx << '\n';
}     