//{ <defines>
#ifndef _LOCAL
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#endif
#include <bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define re return
#define fo(n) for(int i=0;i<n;++i)
#define fr(i,n) for(int i=0;i<n;++i)
#define forb(a, b, c) for(int a = b; a != c; a += ((~~(b<c))<<1)-1)
#define ifn(x) if(!(x))
#define ef else if
#define ve vector
#define sz(x) int(x.size())
#define _  << ' ' <<
#define pb emplace_back
#define bnd(x) x.begin(), x.end()
#define pw(x) (1ll << x)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef ve<int> vi;
const ll OO = 4e18;
const ld pi = 3.1415926535897932384626433832;
const int md = 1e9 + 7,
          oo = 2e9;
//} </defines>
const int N = +100500;

int l[31], r[31], L, R;

void solve() {
    cin >> L >> R; int pL = L;
    if(!L && !R) {
        cout << 1 << endl;
        re;
    }
    ll f = 0;
    if(!L) {
        f = R+R+1;
        ++L;
    }
    fo(31) l[30 - i] = 1 & (L >> i);
    fo(31) r[30 - i] = 1 & (R >> i);
    ll dp[32][2][2][2], ans = 0;
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = 1;
    fo(32) fr(t, 2) fr(d0, 2) fr(d1, 2) {
        if(i < 31) fr(p0, 2) fr(p1, 2) {
            if(p0 && p1) continue;
            if(!t && p0 > p1) continue;
            if(!d0 && p0 < l[i]) continue;
            if(!d1 && p1 > r[i]) continue;
            int nt = p0 < p1 ? 1 : t;
            int nd0 = p0 > l[i] ? 1 : d0;
            int nd1 = p1 < r[i] ? 1 : d1;
            dp[i+1][nt][nd0][nd1] += dp[i][t][d0][d1];
        }
        if(i == 31) ans += dp[i][t][d0][d1];
    }
    ans *= 2;
    ans += f;
    cout << ans << endl;
#ifdef _LOCAL
    if(R - L <= 5000) {
        int e = 0;
        for(int l = pL; l <= R; ++l)
            for(int r = pL; r <= R; ++r) if((l & r) == 0) ++e;
        cerr << (ans == e ? "correct\n" : "incorrect\n");
        cerr << e << endl;
    }
#endif
}

int main() {
#ifdef _LOCAL
    freopen("in.txt", "r", stdin);
#else
    ios_base :: sync_with_stdio(0);
//    int tt = 1;
#endif
    int tt; cin >> tt;
    while(tt--) solve();
}
