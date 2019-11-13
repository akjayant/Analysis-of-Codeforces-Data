#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

string s;
int n, cnt, dem, ck;
int d[1000010];
long long res[1000010];
long long ans = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ///freopen("main.inp", "r", stdin);

    cin >> s; n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        if ( s[i] == 'u' || s[i] == 'n' ) {
            if ( s[i] == s[i - 1] ) dem ++;
            else {
                if ( dem ) d[++cnt] = dem;
                dem = 1;
            }
        }
        if ( s[i] == 'm' || s[i] == 'w' ) {
            cout << 0;
            return 0;
        }
    }
    if ( dem ) d[++cnt] = dem;
    res[1] = 1; res[2] = 2;
    for (int i = 3; i <= n; i++)
        res[i] = (res[i - 1] + res[i - 2]) % MOD;
    for (int i = 1; i <= cnt; i++)
        ans = (ans * res[d[i]]) % MOD;
    cout << ans;

    return 0;
}
