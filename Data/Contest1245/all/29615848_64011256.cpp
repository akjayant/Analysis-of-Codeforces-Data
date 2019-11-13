#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define REP(i, r) for(int i = (int)0; i < (int)r; ++i)
#define FORD(i, l, r) for(int i = (int)l; i >= (int)r; --i)
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int Nmax = 1e5 + 112;;
const ll MOD = 1e9 + 7;

string s;
ll f[Nmax], ans = 1, n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef yt
        freopen("in.inp", "r", stdin);
    #endif // yt
    cin >> s;
    n = s.size();
    f[1] = 1;
    f[2] = 2;
    FOR(i, 3, Nmax - 1) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    REP(i, n) {
        int p = i;
        if (s[i] == 'm' || s[i] == 'w') ans = 0;
        if (s[i] == 'n' || s[i] == 'u') {
            while(p + 1 < n && s[p + 1] == s[p]) {
                ++p;
            }
            if (p - i + 1 >= 2) ans = (ans * f[p - i + 1]) % MOD;
            i = p;
        }
    }
    cout << ans;
}
