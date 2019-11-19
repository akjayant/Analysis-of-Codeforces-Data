#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = (ll)l; i <= (ll)r; ++i)
#define REP(i, r) for(ll i = (ll)0; i < (ll)r; ++i)
#define FORD(i, l, r) for(ll i = (ll)l; i >= (ll)r; --i)
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
const ll Bmax = 35;

ll t, l, r, f[Bmax][2][2][2][2];

ll getbit(ll a, ll k) {
    return (a >> (k - 1)) & 1;
}

ll dp(ll pos, bool a1, bool a2, bool b1, bool b2) {
    if (pos == 0) return 1;
    if (f[pos][a1][a2][b1][b2] != -1) return f[pos][a1][a2][b1][b2];
    ll res = 0;
    FOR(i, 0, 1) FOR(j, 0, 1) {
        if (i == j && i == 1) continue;
        ll _l = getbit(l, pos), _r = getbit(r, pos);
        if (a1 == false && i < _l) continue;
        if (a2 == false && i > _r) continue;
        if (b1 == false && j < _l) continue;
        if (b2 == false && j > _r) continue;
        res += dp(pos - 1, a1 || i > _l, a2 || i < _r, b1 || j > _l, b2 || j < _r);
    }
    return f[pos][a1][a2][b1][b2] = res;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef yt
        freopen("in.inp", "r", stdin);
    #endif // yt
    cin >> t;
    while(t--) {
        memset(f, -1, sizeof(f));
        cin >> l >> r;
        cout << dp(32, false, false, false, false) << '\n';
    }
}
