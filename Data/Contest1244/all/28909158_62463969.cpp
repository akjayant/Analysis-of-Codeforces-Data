#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;


void solve() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int cnt1 = (int)ceil((double)a/c);
        int cnt2 = (int)ceil((double)b/d);
        if (cnt1 + cnt2 <= k) {
            cout << cnt1 << " " << cnt2 << "\n";
        } else
            cout << "-1\n";
    }
}

int main() {
	//~ freopen(".in", "r", stdin);
	//~ freopen(".out", "w", stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
    solve();
    return 0;
}
