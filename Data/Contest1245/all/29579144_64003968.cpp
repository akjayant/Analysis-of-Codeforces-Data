#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define sz(x) (int)x.size()
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int dp[N];

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    for (char c : s) {
        if (c == 'w' || c == 'm') {
            cout << 0 << "\n";
            return;
        }
    }
    int ans = 1;
    char prevc = 'A';
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == prevc) {
            prevc = s[i];
            ++cnt;
        }
       // cout << i << " " << cnt << " " << prevc << endl;
        if (s[i] != prevc || i == n - 1) {
            if (prevc == 'n' || prevc == 'u') {
                ans = (ans * dp[cnt]) % MOD;
            }
            cnt = 1;
            prevc = s[i];
        }
    }
    cout << ans << "\n";
}

signed main() {
    using namespace std;
    cin.tie(0);
    cout.tie(0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < N; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    int t;
    t = 1;
    while (t--)
        solve();
    return 0;
}
