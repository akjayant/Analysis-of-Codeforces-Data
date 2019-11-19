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

int n, p[N];

int get(int x) {re p[x] == x ? x : p[x] = get(p[x]);}
void unite(int x, int y) {p[get(x)] = get(y);}

void solve() {
    cin >> n;
    int x[n], y[n], c[n], k[n], mk[n];
    fo(n+1) p[i] = i;
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(k, 0, sizeof k);
    memset(c, 0, sizeof c);
    memset(mk, 0, sizeof mk);
    fo(n) cin >> x[i] >> y[i];
    fo(n) cin >> c[i];
    fo(n) cin >> k[i];
    ve< pair<ll, pii> > e;
    ll ans = 0;
    fo(n) e.pb(c[i], pii(n, i));
    fo(n) fr(j, i) e.pb(1ll * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), pii(i, j));
    sort(bnd(e));
    ve<pii> u;
    fo(sz(e)) if(e[i].sd.ft == n) {
        ans = e[i].ft;
        unite(n, e[i].sd.sd);
        mk[e[i].sd.sd] = 1;
        break;
    }
    for(auto x : e) if(get(x.sd.ft) != get(x.sd.sd)) {
        ans += x.ft;
        if(x.sd.ft == n) mk[x.sd.sd] = 1;
        else u.pb(x.sd.sd + 1, x.sd.ft + 1);
        unite(x.sd.ft, x.sd.sd);
    }
    cout << ans << endl;
    ans = 0;
    fo(n) if(mk[i]) ++ans;
    cout << ans << endl;
    fo(n) if(mk[i]) cout << i+1 << ' ';
    cout << endl << sz(u) << endl;
    sort(bnd(u));
    for(pii x : u) cout << x.ft << ' ' << x.sd << endl;
}

int main() {
#ifdef _LOCAL
    freopen("in.txt", "r", stdin);
    int tt; cin >> tt;
#else
    ios_base :: sync_with_stdio(0);
    int tt = 1;
#endif
    while(tt--) solve();
}
