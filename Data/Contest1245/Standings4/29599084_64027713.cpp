/* be name khoda */

// #define stream_enable
#define long_enable
#define debug_enable

#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <limits.h>
#include <fstream>
#include <cstring>

using namespace std;

#ifdef stream_enable
#define cin sss
#endif

#ifdef long_enable
typedef long long int ll;
#else
typedef int ll;
#endif
typedef long double dbl;

typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<pii> vpii;

const ll MOD = 1000000007;

const long long BIG = 1446803456761533460LL;
const int Big = 336860180;

#ifdef long_enable
const ll INF = LONG_LONG_MAX;
#else
const ll INF = INT_MAX;
#endif

const ll adj4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const ll adj8[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back

#define print(x) cout << (x) << '\n'
#define print2(x, y) cout << (x) << ' ' << (y) << '\n'
#define print3(x, y, z) cout << (x) << ' ' << (y) << ' ' << (z) << '\n'
#define print4(x, y, z, t) cout << (x) << ' ' << (y) << ' ' << (z) << ' ' << (t) << '\n'
#define printp(x) cout << "(" << (x).ff << ", " << (x).ss << ")" << '\n'
#define printa(x, n) fori (ja12345, n) { cout << (x)[ja12345] << ' '; } cout << '\n'
#define printap(x, n) fori (ia1234567, n) { cout << "(" << (x)[ia1234567].ff << ", " << (x)[ia1234567].ss << ")" << '\n'; }
#define printaa(x, n, m) fori (iaa123456, n) { fori (jaa123456, m) { cout << (x)[iaa123456][jaa123456] << ' '; } cout << '\n'; }
#define printav(x, n) fori (iaa123477, n) { printv((x)[iaa123477]); }
#define printia(x, n) fori (ja212345, n) { cout << ja212345 << " : " << (x)[ja212345] << '\n'; }

#ifdef debug_enable
#define debug(x) cout << #x << " -> "; print(x)
#define debug2(x, y) cout << #x << ' ' << #y << " -> "; print2(x, y)
#define debug3(x, y, z) cout << #x << ' ' << #y << ' ' << #z << " -> "; print3(x, y, z)
#define debug4(x, y, z, t) cout << #x << ' ' << #y << ' ' << #z << ' ' << #t << " -> "; print4(x, y, z, t)
#define debugp(x) cout << #x << " -> "; printp(x)
#define debuga(x, n) cout << #x << " -> "; printa(x, n)
#define debugap(x, n) cout << #x << " ->\n"; printap(x, n)
#define debugaa(x, n, m) cout << #x << " ->\n"; printaa(x, n, m)
#define debugav(x, n) cout << #x << " ->\n"; printav(x, n)
#define debugia(x, n) cout << #x << " ->\n"; printia(x, n)
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x, y, z, t)
#define debugp(x)
#define debuga(x, n)
#define debugap(x, n)
#define debugaa(x, n, m)
#define debugav(x, n, m)
#define debugia(x, n)
#endif

#define forifrom(i, s, n) for(ll i = (s); i < (n); ++i)
#define forirto(i, n, e) for(ll i = (n) - 1; i >= (e); --i)
#define fori(i, n) forifrom (i, 0, n)
#define forir(i, n) forirto (i, n, 0)

#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

#define Add(a, b) a = (a + (b)) % MOD
#define Mul(a, b) a = (a * (b)) % MOD

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll powMod(ll a, ll b) {
    ll n = 1;
    ll p = a;
    while (b > 0) {
        if (b % 2 == 1) {
            n *= p;
            n %= MOD;
        }
        p *= p;
        p %= MOD;
        b /= 2;
    }
    return n;
}

ll modularInverse(ll a) {
    return powMod(a, MOD - 2);
}

stringstream sss;

// -----------------------------------------------------------------------

const ll maxn = 2010;

pii xs[maxn];
ll ki[maxn];
ll ci[maxn];
set<pii> st_c;
set<pair<ll, pii>> st_k;
vi cs;
vpii es;
bool vis[maxn];

ll dist(ll i, ll j) {
    return abs(xs[i].ff - xs[j].ff) + abs(xs[i].ss - xs[j].ss);
}

void MAIN() {

    ll n;
    cin >> n;
    fori (i, n) {
        cin >> xs[i].ff >> xs[i].ss;
    }
    fori (i, n) {
        cin >> ci[i];
        st_c.insert({ci[i], i});
    }
    fori (i, n) {
        cin >> ki[i];
    }

    ll ans = 0;
    ll mn = st_c.begin()->ss;
    st_c.erase(st_c.begin());
    ans += ci[mn];
    fori (i, n) {
        if (i == mn) continue;
        st_k.insert({dist(i, mn) * (ki[i] + ki[mn]), {mn, i}});
    }
    vis[mn] = true;
    cs.pb(mn);
    ll ii = 0;
    while (ii < n - 1) {
        ll mn;
        if (st_c.begin()->ff < st_k.begin()->ff) {
            mn = st_c.begin()->ss;
            ll val = st_c.begin()->ff;
            st_c.erase(st_c.begin());
            if (vis[mn]) continue;
            ans += val;
            cs.pb(mn);
        } else {
            mn = st_k.begin()->ss.ss;
            ll val = st_k.begin()->ff;
            ll fst = st_k.begin()->ss.ff;
            st_k.erase(st_k.begin());
            if (vis[mn]) continue;
            ans += val;
            es.pb({mn, fst});
        }
        ++ii;
        vis[mn] = true;
        fori (i, n) {
            if (vis[i]) continue;
            st_k.insert({dist(i, mn) * (ki[i] + ki[mn]), {mn, i}});
        }
    }
    print(ans);
    print(cs.size());
    for (auto c : cs) {
        cout << c + 1 << ' ';
    }
    cout << '\n';
    print(es.size());
    for (auto e : es) {
        cout << e.ff + 1 << ' ' << e.ss + 1 << '\n';
    }

}

// -----------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    sss << R"(
3
2 1
1 2
3 3
23 2 23
3 2 3
    )";
    MAIN();
    return 0;
}
