#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e9;
// const LL oo = 1e18;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int N = 4e5;
// const long double PI = acos(-1);

int f[N];

void solve() {
    int n, i, a, b, c;
    string s;
    cin >> s;
    n = s.length();
    f[0] = 1; f[1] = 1;
    for (i=2;i<N;i++) {
        f[i] = f[i-1] + f[i-2];
        if (f[i] >= MOD) f[i] -= MOD;
    }
    for (auto it : s) {
        if (it == 'm' || it == 'w') {
            cout << "0\n";
            return;
        }
    }
    LL ans = 1;
    for (i=0;i<n;i++) {
        int cnt = 1;
        while(i<n-1 && s[i+1] == s[i]) {
            i++;
            cnt++;
        }
        if (s[i] == 'u' || s[i] == 'n') {
            ans = (ans * f[cnt])%MOD;
        }
    }
    cout << ans << '\n';
}

int main() {
    FASTIO; 
    int t = 1; 
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}