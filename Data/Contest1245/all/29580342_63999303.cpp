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

void solve() {
    int n, i, a, b, c;
    cin >> n >> a >> b >> c;
    string s, ans;
    cin >> s;
    int wins = 0;
    for (i=0;i<n;i++) ans += '0';
    for (i=0;i<n;i++) {
        char it = s[i];
        if (it == 'S') {
            if (a > 0) {
                a--;
                wins++;
                ans[i] = 'R';
            }
        } else if (it == 'R') {
            if (b > 0) {
                b--;
                wins++;
                ans[i] = 'P';
            }
        } else {
            if (c > 0) {
                c--;
                wins++;
                ans[i] = 'S';
            }
        }
    }
    for (i=0;i<n;i++) {
        if (ans[i] == '0') {
            if (a > 0) {
                ans[i] = 'R';
                a--;
            } else if (b > 0) {
                ans[i] = 'P';
                b--;
            } else {
                ans[i] = 'S';
                c--;
            }
        }
    }
    if (2 * wins >= n) cout << "YES\n" << ans << '\n';
    else cout << "NO\n";

}

int main() {
    FASTIO; 
    int t = 1; 
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}